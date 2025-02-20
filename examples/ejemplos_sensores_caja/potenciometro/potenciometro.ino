#include "Deusto.h"

//Conectar el potenciometro a una entrada ADC, preferiblemente del ADC1
const int pinPot=pinJ1A;

float valorPot; //variable donde guardar el valor del potenciometor
float valorTension; //variable donde guardar el valor de la tension en mV

void setup() {
	delay(1000);
	Serial.begin(115200);

}

void loop() {
	valorPot=analogRead(pinPot); //AnalogRead en el ESP32 devuelve un valor entre 0 y 4095
  valorTension=map(valorPot,0,4095,0,3300)/1000.0; //Mapea la entrada del por entre 0 y 4095 a un valor entre 0 y 3300. 
                                                   //Tiene que es valores enteros, luego divido entre mil para que este en V
                                                   // Importante poner 1000.0 si pones 1000 lo hace mal sin decimales. 
  Serial.printf("Valor Pot=%.2f y su tension es %.2f\n",valorPot,valorTension);
	delay(1000); //No utilizar delays, no se puede medir antes de cada 250ms
}

