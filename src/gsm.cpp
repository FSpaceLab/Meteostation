#include "gsm.h"

unsigned long current_time_gsm;
unsigned long preview_time_gsm;

void SendData(float h, float t, float s, float d)
{
    Serial1.begin(9600, SERIAL_8N1, 16, 17);
    if (Serial1.available())
        Serial.write(Serial1.read());

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

    String str = "GET https://api.thingspeak.com/update?api_key=RLHRL8UF3X65GQH6&field1=" + String(h) + "&field2=" + String(t) + "&field3=" + String(s) + "&field4=" + String(d);
    Serial.println(str);
    Serial1.println(str); // begin send data to remote server

    delay(4000);

    Serial1.println((char)26); // sending
    delay(5000);               // waitting for reply, important! the time is base on the condition of internet
    Serial1.println();

    Serial1.println("AT+CIPSHUT"); // close the connection
    delay(100);
}