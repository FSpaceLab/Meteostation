#pragma once
// Визначення швидкості вітру
#define ANEMOMETER_PIN 2 
#define CIRCLE_LEN 0.358142   // Довжина кола анемометра

// Номери пінів датчиків Холла
#define HALL_SENSOR_A_PIN 33
#define HALL_SENSOR_B_PIN 34
#define WIND_DIRECTION_DELAY 600 // в секундах (15хв)


// Межі аналогових значень для 8 напрямків вітру
const int WIND_DIRECTION_THRESHOLDS[8][2] = {
  {2200, 2340},     // N
  {1970, 2199},     // NE
  {1740, 1969},     //  E
  {1650, 1739},     // SE
  {-1760, -1650},   //  S
  {-2009, -1761},   // SW
  {-2240, -2010},   //  W
  {-2340, -2241}    // NW
};

// Кути напрямків вітру
const uint16_t WIND_DIRECTION_VALUES[8] = {
  0, 45, 90, 135, 180, 225, 360
};