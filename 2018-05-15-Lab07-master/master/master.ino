//https://github.com/smarmengol/Modbus-Master-Slave-for-Arduino
#include "DHT.h"
#include "Wire.h"
#include<LiquidCrystal.h>
#define dht_dpin 13 //  
#define DHTType DHT11  //

LiquidCrystal lcd(16, 15, 5, 4, 3, 2);
DHT dht(dht_dpin,DHTType);

const int SLAVE_ADDRESS = 1;
char incomingByte = 0;

void setup(){
Serial.begin(9600);
Wire.begin();
delay(300);

Serial.println("Humidity and temperature\n\n");

pinMode(12,OUTPUT);

digitalWrite(12,1);

dht.begin();
lcd.begin(16, 2);
delay(700); 
}

void loop(){
  Wire.requestFrom(SLAVE_ADDRESS, 16);  
  while (Wire.available()) {
      lcd.setCursor(0,0);
    incomingByte = Wire.read(); // receive a byte
    // Display at LCD 
    lcd.print(incomingByte);
    delay(1000);
    lcd.clear();
    // LCD 
  }

  /*lcd.clear();
  lcd.setCursor(0,0);
float h = dht.readHumidity();
String h1="";
h1+=h;
 lcd.print("h = ");
  lcd.print(h1);*/
//----------------

/*float d = dht.readTemperature();
String d1 = "";
d1+=d;
lcd.setCursor(0,1);
 */
//delay(1000); //1000ms

}
