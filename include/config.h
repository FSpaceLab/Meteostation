#ifndef __CONFIG_H
#define __CONFIG_H

// Часові інтервали
#define INTERVAL_WIND_DIRECTION 6  // [сек] (15хв) Інтервал визначення напрямку вітру
#define INTERVAL_TEMP_HUM       6  // [сек] (15хв) Інтервал визначення температури та вологості
#define INTERVAL_SENDING        18 // [сек] (1хв) Інтервал надсилання даних
#define INTERVAL_WIND_SPEED_ZEROING 7 // [сек] Інтервал після якого відбудеться онулення швидкості вітру

// Визначення швидкості вітру
#define ANEMOMETER_PIN 2 
#define CIRCLE_LEN 0.358142 * 1.39   // Довжина кола анемометра

// Номери пінів датчиків Холла
#define HALL_SENSOR_A_PIN 33
#define HALL_SENSOR_B_PIN 34

#define HALL_SENSOR_POWER_PIN 25 // Пін який буде давати живлення на датчики тільки в необхідний момент


// Межі аналогових значень для 8 напрямків вітру
const int WIND_DIRECTION_THRESHOLDS[8][2] = {
  {2020, 2200},     // N
  {1788, 2019},     // NE
  {1592, 1787},     //  E
  {1520, 1591},     // SE
  {-1671, -1520},   //  S
  {-1816, -1670},   // SW
  {-2046, -1815},   //  W
  {-2200, -2045}    // NW
};

// Кути напрямків вітру
const uint16_t WIND_DIRECTION_VALUES[8] = {
  0, 45, 90, 135, 180, 225,270, 315
};

// Визначення температури та вологості
#define DHTPIN 14 

// Визначення кількості опадів
#define RAIN_SENSOR_PIN 27

#define ERROR_CODE 666

#endif