#include "gsm.h"


void SetupGsm(HardwareSerial & _serial)
{
    _serial.println("AT");
    delay(1000);
    if (_serial.available())
        Serial.write(_serial.read());


    _serial.println("AT+CPIN?");
    delay(1000);

    _serial.println("AT+CREG?");
    delay(1000);

    _serial.println("AT+CGATT?");
    delay(1000);

    _serial.println("AT+CIPSHUT");
    delay(1000);

    _serial.println("AT+CIPSTATUS");
    delay(2000);

    _serial.println("AT+CIPMUX=0");
    delay(2000);

    _serial.println("AT+CSTT=\"internet\""); // start task and setting the APN,
    delay(1000);
}


void SendData(HardwareSerial & _serial, float h, float t, float s, float d)
{
    _serial.println("AT+CIICR"); // bring up wireless connection
    delay(3000);

    _serial.println("AT+CIFSR"); // get local IP adress
    delay(2000);

    _serial.println("AT+CIPSPRT=0");
    delay(3000);

    _serial.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\""); // start up the connection
    delay(6000);

    _serial.println("AT+CIPSEND"); // begin send data to remote server
    delay(4000);

    String str = "GET " + String(SERVER_LINK) + "&field1=" + String(h) + "&field2=" + String(t) + "&field3=" + String(s) + "&field4=" + String(d);
    Serial.println(str);
    _serial.println(str); // begin send data to remote server

    delay(4000);

    _serial.println((char)26); // sending
    delay(5000);               // waitting for reply, important! the time is base on the condition of internet

    _serial.println("AT+CIPSHUT"); // close the connection
    delay(100);
}