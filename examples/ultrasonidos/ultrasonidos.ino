//Instalar la libreria grove ultrasonic ranger
#include "Ultrasonic.h"
#include "Deusto.h"

const int pinUltra=pinJ7A; //pin al que esta conectado el sensor en este caso en el conector J7
Ultrasonic ultrasonic(pinUltra);

long RangeInCentimeters;



void setup() {
	delay(1000);
	Serial.begin(115200);

}

void loop() {
	RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // 
	Serial.print(RangeInCentimeters);//0~400cm
	Serial.println(" cm");
	delay(250); //No utilizar delays, no se puede medir antes de cada 250ms
}

