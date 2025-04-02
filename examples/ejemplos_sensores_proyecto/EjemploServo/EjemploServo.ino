#include <ESP32Servo.h> 

Servo myservo;  // create servo object to control a servo


int servoPin = 27;      // GPIO pin used to connect the servo control (digital out)

  
int val;    // variable to read the value from the analog pin

void setup()
{
	// Allow allocation of all timers
	ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);// Standard 50hz servo
  myservo.attach(servoPin, 500, 2400);   // attaches the servo on pin 18 to the servo object
                                         // using SG90 servo min/max of 500us and 2400us
                                         // for MG995 large servo, use 1000us and 2000us,
                                         // which are the defaults, so this line could be
                                         // "myservo.attach(servoPin);"
}

void loop() {
 
  myservo.write(0);                  // set the servo position according to the scaled value
  delay(2000);                          // wait for the servo to get there
  myservo.write(180);                  // set the servo position according to the scaled value
  delay(2000);                          // wait for the servo to get there
}

