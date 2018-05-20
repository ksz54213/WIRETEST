#include "DHT.h"
#define dht_dpin 2 //  
#define DHTType DHT11  //

DHT dht(dht_dpin,DHTType);

void setup(){
Serial.begin(9600);

delay(300);

Serial.println("Humidity and temperature\n\n");

pinMode(8,OUTPUT);

digitalWrite(8,1);

dht.begin();

delay(700); 
}
void loop(){
//dht.read11(dht_dpin); //libraryDHT.read11
Serial.print("Humidity = "); 
float h = dht.readHumidity();
Serial.print(h);
Serial.print("% ");
Serial.print("temperature = ");
float d = dht.readTemperature();
Serial.print(d);
Serial.println("C ");
delay(1000); //1000ms }
}
