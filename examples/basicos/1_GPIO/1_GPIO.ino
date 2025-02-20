/*
 Ejemplo básico para leer el boton de la placa y encender el led de la placa
 Cuando el boton se este pulsando
*/

//Esta librería tiene las definiciones de los pines de la tarjeta de expansión
#include "Deusto.h" 

// Definición de los pines en los que estan conectados los perifericos
const int buttonPin = 0;  // El numero del pin en el que esta conectado el boton
const int ledPin = 5;    // El numero del pin en el que esta conectado el led


int buttonState = 0;  // Variable en la que se guardara el estado del boton

// Funcion que solo se ejecuta una vez al comienzo
void setup() {
  // Define el led como una salida
  pinMode(ledPin, OUTPUT);
  // Define el boton como una entrada
  pinMode(buttonPin, INPUT);
}


// Función que se ejecuta constantemente
void loop() {
  // Lee el balor del boton
  buttonState = digitalRead(buttonPin);

  // Chequea si el boton esta pulsado. Importante el boton de la placa cuando
  // Se presiona entrega un 0 no un 1, como suele ser lo habitual
  if (buttonState == LOW) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
