//Instalar la libreria Grove Digital Light Sensor
#include <Wire.h>
#include <Digital_Light_TSL2561.h>
#define pinJ1A 36
#define pinJ1B 37
#define pinJ2A 34
#define pinJ2B 35
#define pinJ3A 27
#define pinJ3B 14
#define pinJ4A 12
#define pinJ4B 13
#define pinJ5A 22
#define pinJ5B 21
#define pinJ6A 18
#define pinJ6B 19
#define pinJ7A 2
#define pinJ7B 15
#define pinJ8A 16
#define pinJ8B 17

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

