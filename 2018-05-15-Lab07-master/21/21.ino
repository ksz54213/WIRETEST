#include <Wire.h>

String toSend;

void setup()
{
Wire.begin(2);                // join i2c bus with address #2
Wire.onRequest(requestEvent); // register event
}

void loop()
{
 toSend += analogRead(0)+";";
 if ( toSend.length()>20 ) toSend="";
 delay(100);
}

void requestEvent()
{
 char buffer[32];
 toSend.toCharArray(buffer, 32);
 Wire.send(buffer);
}

