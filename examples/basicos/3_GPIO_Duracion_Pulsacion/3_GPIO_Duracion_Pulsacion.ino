/*
 Ejemplo básico para leer el boton de la placa y encender el led de la placa
 Este ejemplo cambia el estado del led cada vez que se pulsa el boton de la placa
*/

//Esta librería tiene las definiciones de los pines de la tarjeta de expansión
#include "Deusto.h"

#define duracionPulsacion 1000

long long pressTime=0;
long long releaseTime=0;


// Hardware button A.  Call read() before checking if isPressed()
Button BtnPlaca = Button(pinBontonPlaca, true, DEBOUNCE_MS);


int buttonState = 0;  // Variable en la que se guardara el estado del boton

// Funcion que solo se ejecuta una vez al comienzo
void setup() {
  pinMode(pinLedPlaca, OUTPUT);
  Serial.begin(115200);
}


// Función que se ejecuta constantemente
void loop() {
  // Lee el valor del boton
  BtnPlaca.read();
  if(BtnPlaca.wasPressed()){
    pressTime=BtnPlaca.lastChange();
  }
  if(BtnPlaca.wasReleased()){
    releaseTime=BtnPlaca.lastChange();
    int tiempoPresionado=releaseTime-pressTime;
    Serial.printf("Tiempo Presionado %d\n", tiempoPresionado);
    if(tiempoPresionado>duracionPulsacion){
      int estadoLed=digitalRead(pinLedPlaca);
      digitalWrite(pinLedPlaca,!estadoLed);
    }
  }
  
  delay(30);
}