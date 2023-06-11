#include "gsm.h"

unsigned long current_time_gsm;
unsigned long preview_time_gsm;

void SendData(float h, float t, float s, float d){
if (Serial1.available())
    Serial.write(Serial1.read());

    current_time_gsm = millis();
  if (((current_time_gsm - preview_time_gsm) / 1000) >= GSM_DELAY)
    {
       Serial1.println("AT");
    }
  preview_time_gsm = millis();

  current_time_gsm = millis();
  if (((current_time_gsm - preview_time_gsm) / 1000) >= GSM_DELAY)
    {
       Serial1.println("AT+CPIN?");
    }
  preview_time_gsm = millis();

 current_time_gsm = millis();
  if (((current_time_gsm - preview_time_gsm) / 1000) >= GSM_DELAY)
    {
       Serial1.println("AT+CREG?");
    }
  preview_time_gsm = millis();

 current_time_gsm = millis();
  if (((current_time_gsm - preview_time_gsm) / 1000) >= GSM_DELAY)
    {
       Serial1.println("AT+CGATT?");
    }
  preview_time_gsm = millis();

current_time_gsm = millis();
  if (((current_time_gsm - preview_time_gsm) / 1000) >= GSM_DELAY)
    {
       Serial1.println("AT+CIPSHUT");
    }
  preview_time_gsm = millis();

current_time_gsm = millis();
  if (((current_time_gsm - preview_time_gsm) / 1000) >= GSM_DELAY)
    {
       Serial1.println("AT+CIPSTATUS");
    }
  preview_time_gsm = millis();

current_time_gsm = millis();
  if (((current_time_gsm - preview_time_gsm) / 1000) >= GSM_DELAY)
    {
       Serial1.println("AT+CIPMUX=0");
    }
  preview_time_gsm = millis();

  current_time_gsm = millis();
  if (((current_time_gsm - preview_time_gsm) / 1000) >= GSM_DELAY)
    {
       Serial1.println("AT+CSTT=\"internet\"");
    }
  preview_time_gsm = millis();

  current_time_gsm = millis();
  if (((current_time_gsm - preview_time_gsm) / 1000) >= GSM_SEND_DELAY)
    {
        Serial1.println("AT+CIICR");
    }
  preview_time_gsm = millis();

 current_time_gsm = millis();
  if (((current_time_gsm - preview_time_gsm) / 1000) >= GSM_DELAY)
    {
       Serial1.println("AT+CIFSR");
    }
  preview_time_gsm = millis();


   current_time_gsm = millis();
  if (((current_time_gsm - preview_time_gsm) / 1000) >= GSM_SEND_DELAY)
    {
       Serial1.println("AT+CIPSPRT=0");
    }
  preview_time_gsm = millis();

   current_time_gsm = millis();
  if (((current_time_gsm - preview_time_gsm) / 1000) >= GSM_CONNECTON_DELAY)
    {
       Serial1.println("AT+CIPSPRT=0");
    }
  preview_time_gsm = millis();

    if (((current_time_gsm - preview_time_gsm) / 1000) >= GSM_CONNECTON_DELAY)
    {
       Serial1.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"");
    }
  preview_time_gsm = millis();

      if (((current_time_gsm - preview_time_gsm) / 1000) >= GSM_SEND_DELAY)
    {
       Serial1.println("AT+CIPSEND");
    }
  preview_time_gsm = millis();

      if (((current_time_gsm - preview_time_gsm) / 1000) >= GSM_SEND_DELAY)
    {
       String str = "GET https://api.thingspeak.com/update?api_key=RLHRL8UF3X65GQH6&field1=" + String(h) + "&field2=" + String(t) + "&field3=" + String(s) + "&field4=" + String(d) ;
        Serial.println(str);
        Serial1.println(str);
    }
  preview_time_gsm = millis();

      if (((current_time_gsm - preview_time_gsm) / 1000) >= GSM_CONNECTON_DELAY)
    {
        Serial1.println((char)26);
    }
  preview_time_gsm = millis();

        if (((current_time_gsm - preview_time_gsm) / 1000) >= GSM_CONNECTON_DELAY)
    {
        Serial1.println("AT+CIPSHUT");
    }
  preview_time_gsm = millis();
}

