#include <Arduino.h>
#include "meteostation.h"

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
    if (flagWindSpeed != previewFlagWindSpeed && counterWindSpeed == 3)
    {
        windSpeed = calcWindSpeed(startTimeWindSpeed);
        previewFlagWindSpeed = flagWindSpeed;
    }

    // Визначення напрямку вітру кожні `WIND_DIRECTION_DELAY` секунд
    if (((current_time - preview_time_wind_direction) / 1000) >= WIND_DIRECTION_DELAY)
    {
        sensorValue = readHallSensors();
        windDirection = determineWindDirection(sensorValue);
    }
    preview_time_wind_direction = millis();


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
