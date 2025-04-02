#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include "Adafruit_VL53L0X.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

const int I2C2_SDA = 19;
const int I2C2_SCL = 18;

TwoWire I2C2 = TwoWire(1);

float red, green, blue;

void setup() {
  Serial.begin(115200);
  I2C2.begin(I2C2_SDA, I2C2_SCL);

  // wait until serial port opens for native USB devices
  while (!Serial) {
    delay(1);
  }

  if (tcs.begin()) {
    //Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1)
      ;  // halt!
  }

  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin(VL53L0X_I2C_ADDR, false, &I2C2)) {
    Serial.println(F("Failed to boot VL53L0X"));
    while (1)
      ;
  }
  // power
  Serial.println(F("VL53L0X API Simple Ranging example\n\n"));
}


void loop() {
  leerDistancia();
  leerColor();
  delay(100);
}

void leerDistancia() {
  VL53L0X_RangingMeasurementData_t measure;

  Serial.print("Reading a measurement... ");
  lox.rangingTest(&measure, false);  // pass in 'true' to get debug data printout!

  if (measure.RangeStatus != 4) {  // phase failures have incorrect data
    Serial.print("Distance (mm): ");
    Serial.println(measure.RangeMilliMeter);
  } else {
    Serial.println(" out of range ");
  }
}

void leerColor() {
  tcs.setInterrupt(false);  // turn on LED
  delay(60);                // takes 50ms to read
  tcs.getRGB(&red, &green, &blue);
  tcs.setInterrupt(true);  // turn off LED
  Serial.print("R:\t");
  Serial.print(int(red));
  Serial.print("\tG:\t");
  Serial.print(int(green));
  Serial.print("\tB:\t");
  Serial.print(int(blue));
  Serial.print("\n");
}
