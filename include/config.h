#ifndef __CONFIG_H
#define __CONFIG_H

// Часові інтервали
#define INTERVAL_WIND_DIRECTION 9  // [сек] (15хв) Інтервал визначення напрямку вітру
#define INTERVAL_TEMP_HUM       9  // [сек] (15хв) Інтервал визначення температури та вологості
#define INTERVAL_SENDING        60 // [сек] (1хв) Інтервал надсилання даних

// Визначення швидкості вітру
#define ANEMOMETER_PIN 2 
#define CIRCLE_LEN 0.358142 * 3.14   // Довжина кола анемометра

// Номери пінів датчиків Холла
#define HALL_SENSOR_A_PIN 33
#define HALL_SENSOR_B_PIN 34

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

// Визначення температури та вологості
#define DHTPIN 14 


#define ERROR_CODE 666

#endif