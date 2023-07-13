#include "gsm.h"

unsigned long current_time_gsm;
unsigned long preview_time_gsm;

void SendData(float h, float t, float s, float d, float b)
{
    Serial1.begin(9600, SERIAL_8N1, 16, 17);
    if (Serial1.available())
        Serial.write(Serial1.read());
    
    Serial1.println("AT+CFUN=1");
    delay(1000);

    Serial1.println("AT");
    delay(1000);

    Serial1.println("AT+CPIN?");
    delay(1000);

    Serial1.println("AT+CREG?");
    delay(1000);

    Serial1.println("AT+CGATT?");
    delay(1000);

    Serial1.println("AT+CIPSHUT");
    delay(1000);

    Serial1.println("AT+CIPSTATUS");
    delay(2000);

    Serial1.println("AT+CIPMUX=0");
    delay(2000);

    Serial1.println("AT+CSTT=\"internet\""); // start task and setting the APN,
    delay(1000);

    Serial1.println("AT+CIICR"); // bring up wireless connection
    delay(3000);

    Serial1.println("AT+CIFSR"); // get local IP adress
    delay(2000);

    Serial1.println("AT+CIPSPRT=0");
    delay(3000);

    Serial1.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\""); // start up the connection
    delay(6000);

    Serial1.println("AT+CIPSEND"); // begin send data to remote server
    delay(4000);

    String str = "GET https://api.thingspeak.com/update?api_key=79NA5ZUGQP4CS0JY&field1=" + String(0) + "&field2=" + String(b) + "&field3=" + String(s) + "&field4=" + String(d) + "&field6=" + String(t)+ "&field8=" + String(h);
    Serial.println(str);
    Serial1.println(str); // begin send data to remote server

    delay(4000);

    Serial1.println((char)26); // sending
    delay(5000);               // waitting for reply, important! the time is base on the condition of internet
    Serial1.println();

    Serial1.println("AT+CIPSHUT"); // close the connection
    delay(100);

    Serial1.println("AT+CFUN=0");
    delay(100);

}

float levelBattery()
{
  static int count;
  static float averege;
  float voltage;
  if (count == 500)
  {
    voltage = 0.104 * exp(0.00135 * (averege / float(count)));
    averege = 0;
    count = 0;
  }
  else
  {
    count++;
    averege += analogRead(batPin);
  }
  int percentages = round(100 - (8.42 - voltage) / 2.3 * 100);
  if ((percentages < 0) || (percentages > 100))
    percentages = 666;
  return percentages;
}