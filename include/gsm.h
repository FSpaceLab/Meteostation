#ifndef __GSM_H
#define __GSM_H
#define batPin 35
#include <Arduino.h>
#include <config.h>

void SendData(float h, float t, float s, float d, float b, uint16_t rainInterruptAmount);
float levelBattery();

#endif