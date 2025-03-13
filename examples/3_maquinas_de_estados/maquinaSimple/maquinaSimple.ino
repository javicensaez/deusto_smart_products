#include <Ticker.h>
#include <OneButton.h>

int estado = 0;
const int ledPin =  5;// the number of the LED pin
const int bottonPin = 0;
// Variables will change:
int ledState = LOW;   
// define un boton
OneButton boton;
int flagClick = 0; // Flag para saber si se ha pulsado el boton
int flagLongPress = 0; // Flag para saber si se ha pulsado el boton

// Declaramos un objeto de la clase Ticker
// Este objeto se encargará de ejecutar la función flip cada vez que pase un tiempo determinado
// El tiempo se indica en segundos
Ticker flipper;

void setup() {

  Serial.begin(115200); // Inicia la comunicación serie
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  // Configura un boton, primero el pin, luego si es pullup o pulldown y por último si es activo en alto o en bajo
  boton.setup(bottonPin, INPUT, true);

  // Configura la función que se ejecutará cuando se pulse el boton
  boton.attachClick(simpleClick);
  boton.attachLongPressStop(pulsadoLargo);
  flipper.attach(0.5, blinkled);
}

void loop() {
boton.tick();
  switch (estado) {
    case 0: estadoCero(); break;
    case 1: estadoUno(); break;
  }


}

void estadoCero() {
    if(flagClick == 1) {
      flagClick = 0;
      estado = 1;
      Serial.println("Cambio del estado 0 al estado 1");
    }

}


void estadoUno() {
 if(flagLongPress == 1) {
      flagLongPress = 0;
      estado = 0;
      Serial.println("Cambio del estado 1 al estado 0");
    }
}

void blinkled() {
    ledState = !ledState;
    digitalWrite(ledPin, ledState);

}

void simpleClick() {
  flagClick = 1; // Se ha pulsado el boton
} 

void pulsadoLargo() {
  flagLongPress=1;
  Serial.println("Pulsado largo");

}