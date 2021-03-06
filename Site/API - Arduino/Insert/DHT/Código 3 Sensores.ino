#include "DHT.h"
#define dht_type DHT11
 #include <Adafruit_Sensor.h>

#include <DHT.h>
#include <DHT_U.h>

#include "DHT.h"
 
#define DHTPIN A1 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11
 
DHT dht(DHTPIN, DHTTYPE);
int sensorPin=A0;
int sensorValue=0;
int sensorPin_lm35=A5;
int sensorValue_lm35=0;
void setup() 
{
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();
}
 
void loop() 
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(t) || isnan(h)) 
  {
    Serial.println("Failed to read from DHT");
  } 
  else
  {
    //Serial.print("Umidade: ");
    Serial.print(h);
    Serial.print(";");
   // Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.print(";");
   //Serial.println();
  }

  sensorValue = analogRead(sensorPin);
  Serial.print(sensorValue);
  Serial.print(";");
  sensorValue_lm35 = analogRead(sensorPin_lm35);
  Serial.print(sensorValue_lm35);
  Serial.print(";");
  Serial.println();
  delay(100);
  }  
