#ifndef __GSM_H
#define __GSM_H

#include <Arduino.h>

void SetupGsm(HardwareSerial & _serial);
void SendData(HardwareSerial & _serial, float h, float t, float s, float d);

#endif