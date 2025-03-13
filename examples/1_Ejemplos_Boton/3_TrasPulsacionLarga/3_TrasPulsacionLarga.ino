#include "Deusto.h" 

//Instalar libreria onebutton

#include <OneButton.h>

#define PIN_INPUT 0 // Pin de entrada del boton, el de la placa. Entrega un 0 cuando se pulsa
#define PIN_LED 5 // Pin de salida del led, el de la placa

// define un boton
OneButton boton;

int ledState = LOW; // estado del led

void setup()
{
  Serial.begin(115200); // Inicia la comunicación serie


  
  pinMode(PIN_LED, OUTPUT); // Configura un led, primero el pin, luego si es entrada o salida
  digitalWrite(PIN_LED, ledState); // Inicializa el led

  // Configura un boton, primero el pin, luego si es pullup o pulldown y por último si es activo en alto o en bajo
  boton.setup(PIN_INPUT, INPUT, true);

  // Configura la función que se ejecutará cuando se suelta el boton después de una pulsación larga
  boton.attachLongPressStop(largaPulsacion);
} 


// Función que se ejecuta constantemente
void loop()
{
  // Actualiza el estado del boton
  boton.tick();

  // Espera 10ms
  delay(10);
} 


// Función que se ejecuta cuando se suelta el boton después de una pulsación larga
void largaPulsacion()
{
  Serial.println("x1");

  ledState = !ledState; // Cambia el estado del led
  digitalWrite(PIN_LED, ledState);
} // doubleClick
