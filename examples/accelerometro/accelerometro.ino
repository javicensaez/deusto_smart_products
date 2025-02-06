//Instalar la libreria Accelerometer_MMA7660
//https://github.com/Seeed-Studio/Accelerometer_MMA7660

#include <Wire.h>
#include "MMA7660.h"
#include "Deusto.h"


//Se conecta en el J5, no hace falta definir pin Funciona por I2C
MMA7660 accelemeter; //Instancia el accelerometro

float ax,ay,az; //variables donde guardar la acceleracion

void setup() {
	delay(1000);
  Wire.begin(); //Comienza las comunicaciones I2C
  accelemeter.init();   //Inicia el sensor conectado en J5
	Serial.begin(115200);

}

void loop() {
	accelemeter.getAcceleration(&ax,&ay,&az);
  Serial.printf("ax=%.2f ay=%.2f az=%.2f\n",ax,ay,az);
	delay(1000); //No utilizar delays, no se puede medir antes de cada 250ms
}

