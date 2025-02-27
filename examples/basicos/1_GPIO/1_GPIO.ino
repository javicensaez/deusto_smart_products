/*
 Ejemplo básico para leer el boton de la placa y encender el led de la placa
 Cuando el boton se este pulsando
*/

//Esta librería tiene las definiciones de los pines de la tarjeta de expansión
#include "Deusto.h" 




// Hardware button A.  Call read() before checking if isPressed()
Button BtnPlaca = Button(pinBontonPlaca, true, DEBOUNCE_MS);


int buttonState = 0;  // Variable en la que se guardara el estado del boton

// Funcion que solo se ejecuta una vez al comienzo
void setup() {
  pinMode(pinLedPlaca,OUTPUT);
}


// Función que se ejecuta constantemente
void loop() {
  // Lee el valor del boton
   BtnPlaca.read();

  // Chequea si el boton esta pulsado. Importante el boton de la placa cuando
  // Se presiona entrega un 0 no un 1, como suele ser lo habitual
  if (BtnPlaca.isPressed()) {
    // turn LED on:
    digitalWrite(pinLedPlaca, HIGH);
  } else {
    // turn LED off:
    digitalWrite(pinLedPlaca, LOW);
  }
}