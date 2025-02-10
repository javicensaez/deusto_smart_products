//Incluir libreia ESP32 Servo
#include <ESP32Servo.h> 
#include "Deusto.h"

// Crear un objeto servo para controlar un servo
Servo myservo;

// Definir el pin GPIO utilizado para conectar el control del servo (salida digital)
const int servoPin = pinJ4A; // El servo está conectado al pin J4A

// Configuración inicial del programa
void setup() {
  // Permitir la asignación de todos los temporizadores
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  // Establecer la frecuencia del servo en 50Hz (estándar para servos)
  myservo.setPeriodHertz(50);

  // Adjuntar el servo al pin especificado, con valores de pulso mínimo y máximo para el rango del servo
  myservo.attach(servoPin, 1000, 2000);
  // Esto establece el servo en el pin especificado y define los valores mínimos y máximos del pulso.
  // Para servos SG90, se utilizan 1000us y 2000us. 
  // Para servos MG995, se puede utilizar el rango predeterminado de 1000us y 2000us.
  // Por lo tanto, esta línea podría ser simplemente "myservo.attach(servoPin);" con valores predeterminados.
}

// Bucle principal del programa
void loop() {
  // Mover el servo a 0 grados
  myservo.write(0);
  // Esperar un segundo para que el servo alcance la posición deseada
  delay(1000);
  
  // Mover el servo a 90 grados
  myservo.write(90);
  // Esperar un segundo para que el servo alcance la posición deseada
  delay(1000);
}


