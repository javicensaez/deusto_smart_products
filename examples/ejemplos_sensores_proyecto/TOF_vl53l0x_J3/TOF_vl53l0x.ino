#include <Wire.h>

TwoWire miWire = TwoWire(1); // bus I2C 0 o 1



#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  Serial.begin(115200);


  
  Serial.println("Adafruit VL53L0X test");
  miWire.begin(17, 18); // SDA, SCL J3



  if (!lox.begin(0x29, false, &miWire)) {
    Serial.println("Error al iniciar sensor");
    while (1);
  }
  // power 
  Serial.println(F("VL53L0X API Simple Ranging example\n\n")); 
}


void loop() {
  VL53L0X_RangingMeasurementData_t measure;
    
  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print("Distance (mm): "); Serial.println(measure.RangeMilliMeter);
  } else {
    Serial.println(" out of range ");
  }
    
  delay(100);
}