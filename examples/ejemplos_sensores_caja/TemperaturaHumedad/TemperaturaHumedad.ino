#include <Arduino.h>
#include "DHTesp.h"
#include "Deusto.h"

DHTesp dhtSensor1;

int dhtPin1 = 27;

TempAndHumidity sensor1Data;
float temp;
float hum;

void setup() {

  Serial.begin(115200);
  dhtSensor1.setup(dhtPin1, DHTesp::DHT11);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor1Data = dhtSensor1.getTempAndHumidity();  // Read values from sensor 1
 temp=sensor1Data.temperature;
 hum=sensor1Data.humidity;
  Serial.print("La temperatura es: ");
  Serial.println(temp);
  Serial.print("La humedad es: ");
  Serial.println(hum);
  delay(2000);
}
