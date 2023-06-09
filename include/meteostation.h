#ifndef __METEOSTATION_H
#define __METEOSTATION_H

#include <Arduino.h>
#include "config.h"


float calcWindSpeed(float start_time);
int readHallSensors();
uint16_t determineWindDirection(int sensorValue);


#endif