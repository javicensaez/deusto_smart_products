#include "Deusto.h"

// Definición del pin al que está conectado el LED
const int pinLED = pinJ4A; // El LED está conectado al pin J4A

// Variables para controlar la intensidad del LED
int incremento = 1; // Incremento/decremento en la intensidad del LED
int intensidad = 0; // Valor actual de la intensidad del LED, inicialmente apagado (0)

// Configuración inicial del programa
void setup() {
  // Inicialización de la comunicación serial a 115200 baudios
  Serial.begin(115200);
  // Espera de medio segundo antes de continuar
  delay(500);
}

// Bucle principal del programa
void loop() {
  // Incrementar la intensidad del LED
  intensidad += incremento;
  
  // Comprobar si la intensidad supera los límites permitidos (0 a 255)
  if (intensidad > 255 || intensidad < 0) {
    // Si la intensidad excede los límites, invertir el sentido del incremento
    incremento = -incremento;
  }
  
  // Establecer la intensidad del LED
  analogWrite(pinLED, intensidad);
  
  // Esperar un breve periodo de tiempo para permitir cambios visibles en la intensidad
  delay(10);
}
