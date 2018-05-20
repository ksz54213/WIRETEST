#include "DHT.h"
#include "Wire.h"
#include<LiquidCrystal.h>
#define dht_dpin 13 //  
#define DHTType DHT11  //

LiquidCrystal lcd(16, 15, 5, 4, 3, 2);
DHT dht(dht_dpin,DHTType);

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
  lcd.clear();
  lcd.setCursor(0,0);
//dht.read11(dht_dpin); //libraryDHT.read11
Serial.print("Humidity = "); 
float h = dht.readHumidity();
String h1="";
h1+=h;
Serial.print(h);
 lcd.print("h = ");
  lcd.print(h1);
//----------------

Serial.print("% ");
Serial.print("temperature = ");

float d = dht.readTemperature();
String d1 = "";
d1+=d;
lcd.setCursor(0,1);
 lcd.print("d = ");
  lcd.print(d1);
  
Serial.print(d1);
Serial.println("C ");
delay(1000); //1000ms

}
