//Instalar la libreria Grove Digital Light Sensor
#include <Wire.h>
#include <Digital_Light_TSL2561.h>
#include "Deusto.h"

//Se conecta en el J5, no hace falta definir pin Funciona por I2C

int valorLuz;



void setup() {
	delay(1000);
   Wire.begin(); //Comienza las comunicaciones I2C
    TSL2561.init(); //Inicia el sensor conectado en J5
	Serial.begin(115200);

}

void loop() {
	valorLuz=TSL2561.readVisibleLux(); //Lee el sensor de luz del sensor 
  Serial.print("The Light value is: ");
  Serial.println(valorLuz);
	delay(1000); //No utilizar delays, no se puede medir antes de cada 250ms
}

