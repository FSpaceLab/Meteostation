#include "meteostation.h"

// Змінні для розрахунку напрямку вітру
int hallSensorAValue, hallSensorBValue;


float calcWindSpeed(float start_time)
{
    return 1 / (millis() / 1000.0 - start_time) * CIRCLE_LEN;
}


int readHallSensors()
{
    hallSensorAValue = analogRead(HALL_SENSOR_A_PIN);
    hallSensorBValue = analogRead(HALL_SENSOR_B_PIN);

    if (hallSensorAValue < hallSensorBValue)
        return ((hallSensorBValue + hallSensorAValue) / 2) * -1;
    else
        return (hallSensorBValue + hallSensorAValue) / 2;
}


uint16_t determineWindDirection(int sensorValue)
{
    for (int i = 0; i < 8; i++)
    {
        if (sensorValue >= WIND_DIRECTION_THRESHOLDS[i][0] && sensorValue <= WIND_DIRECTION_THRESHOLDS[i][1])
        {
            return WIND_DIRECTION_VALUES[i];
        }
    }
    return ERROR_CODE;
}