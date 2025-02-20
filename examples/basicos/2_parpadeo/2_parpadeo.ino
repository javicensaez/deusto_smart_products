/*
 Ejemplo para que el led de la placa parpadee cada segundo
 */


//Esta librería tiene las definiciones de los pines de la tarjeta de expansión
#include "Deusto.h" 

// Libreria para la gensition de temporizaciones periodicas
// El ticker ejecutara una acción indicada cada vez que pase un tiempo determinado
#include <Ticker.h>


#define LED_BUILTIN 5

// Declaramos un objeto de la clase Ticker
// Este objeto se encargará de ejecutar la función flip cada vez que pase un tiempo determinado
// El tiempo se indica en segundos
Ticker flipper;

// Contador de veces que se ha ejecutado la función flip
int count = 0;

// Función que se ejecutará cada vez que pase un tiempo determinado
void flip() {
  int state = digitalRead(LED_BUILTIN);  // Lee el estado actual del led
  digitalWrite(LED_BUILTIN, !state);     // Cambia el estado del led al valor contrario

  // inclrementa el contador
  ++count;
  // Cuando el contador llega a un valor determinado, cambia la frecuencia de parpadeo
  if (count == 20) {
    flipper.attach(0.1, flip);
  }
  // Cuando el contador llega a otro valor determinado, para de parpadear
  else if (count == 120) {
    flipper.detach();
  }
}

// Función que se ejecuta al principio del programa
//Configura el pin del led como salida y lo apaga
//Configura el objeto flipper para que ejecute la función flip cada 0.3 segundos
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  flipper.attach(0.3, flip);
}

// Función que se ejecuta continuamente
// En este caso no hace nada, se ha configurado un ticker para que ejecute la función flip cada cierto tiempo
void loop() {}