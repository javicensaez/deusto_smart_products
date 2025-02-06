//Incluir Libreria FastLED
#include <FastLED.h>

#define pinJ1A 36
#define pinJ1B 37
#define pinJ2A 34
#define pinJ2B 35
#define pinJ3A 27
#define pinJ3B 14
#define pinJ4A 12
#define pinJ4B 13
#define pinJ5A 22
#define pinJ5B 21
#define pinJ6A 18
#define pinJ6B 19
#define pinJ7A 2
#define pinJ7B 15
#define pinJ8A 16
#define pinJ8B 17

// How many leds in your strip?
#define NUM_LEDS 30 

const int DATA_PIN=pinJ6A;


// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
	Serial.begin(57600);
	Serial.println("resetting");
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS); 
	FastLED.setBrightness(84);
}


void loop() { 
  // Turn the LED on, then pause
  FastLED.clearData(); //Borra todos los leds.
  FastLED.show(); //Muestra los cambios
  delay(1000);
  leds[0] = CRGB::Red; //Pone el prinmer led en rojo
  leds[1]=	CRGB(255,100,20); //Pone un color pasando el valor de R,G,B
  FastLED.show(); //Muestra los cambios
  delay(1000);
  FastLED.showColor(CRGB(0,100,0)); //Pone todos los leds en verde
  delay(1000);

  // Now turn the LED off, then pause
  leds[0] = CRGB::Black; //Apaga el led 0
  FastLED.show();
  delay(500);

for (int n=0; n<NUM_LEDS;n++){
  int miColor=map(n,0,NUM_LEDS,0,255); //Mapea el numero de leds a los posibles colores
  leds[n]=CHSV(miColor,255,255); /La primera valiable es el color de 0 a 255, luego la saturación y luego el valor

}
 FastLED.show();
  delay(5000);

}
