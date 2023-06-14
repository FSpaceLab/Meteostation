#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include "meteostation.h"
#include "config.h"

// ==== PRIVATE DEFINES ====
#define DHTTYPE    DHT22


// ==== PRIVATE VARIABLES ====
// Змінні для визначення швидкості вітру
bool previewFlagWindSpeed = true;
bool flagWindSpeed = false;
uint8_t counterWindSpeed;
double startTimeWindSpeed;
float windSpeed;

// Змінні для визначення напрямку вітру
uint16_t windDirection;
int sensorValue;

// Змінні для створення затримок
unsigned long preview_time_wind_direction;
unsigned long current_time;
unsigned long preview_time_temp_hum;

// Обʼєкт для роботи з DHT22 (визначення температури та вологості)
DHT_Unified dht(DHTPIN, DHTTYPE);
sensors_event_t event;
float temperature, humudity;

// ==== DECLARATION PRIVATE FUNCTIONS ====
void IRAM_ATTR windSpeedISR();


// ==== SETUP AND LOOP FUNCTIONS ====
void setup()
{
    Serial.begin(9600);
    pinMode(HALL_SENSOR_A_PIN, INPUT);
    pinMode(HALL_SENSOR_B_PIN, INPUT);
    pinMode(ANEMOMETER_PIN, INPUT_PULLUP);
    attachInterrupt(ANEMOMETER_PIN, windSpeedISR, CHANGE);
}


void loop()
{
    current_time = millis();

    // Визначення швидкості вітру кожні 4 виклики переривання `windSpeedISR`
    if (flagWindSpeed != previewFlagWindSpeed)
    {
        if (counterWindSpeed == 3)
            windSpeed = calcWindSpeed(startTimeWindSpeed);
        previewFlagWindSpeed = flagWindSpeed;
    }

    // Визначення напрямку вітру кожні `INTERVAL_WIND_DIRECTION` секунд
    if (((current_time - preview_time_wind_direction) / 1000) >= INTERVAL_WIND_DIRECTION)
    {
        sensorValue = readHallSensors();
        windDirection = determineWindDirection(sensorValue);
        preview_time_wind_direction = current_time;
    }

    // Визначення температури та вологості кожні `INTERVAL_TEMP_HUM` секунд
    if (((current_time - preview_time_temp_hum) / 1000) >= INTERVAL_TEMP_HUM)
    {
        // Температура
        dht.temperature().getEvent(&event);
        temperature = isnan(event.temperature) ? ERROR_CODE : event.temperature;

        // Вологість
        dht.humidity().getEvent(&event);
        humudity = isnan(event.relative_humidity) ? ERROR_CODE : event.relative_humidity;

        preview_time_temp_hum = current_time;
    }
}


// ==== PRIVATE FUNCTIONS ====
void IRAM_ATTR windSpeedISR()
{
    flagWindSpeed = !flagWindSpeed;

    if (counterWindSpeed < 3)
    {
        counterWindSpeed++;
    }
    else
    {
        counterWindSpeed = 0;
        startTimeWindSpeed = millis() / 1000.0;
    }
}
