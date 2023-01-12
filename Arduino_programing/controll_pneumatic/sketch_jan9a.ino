#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

void setup() {
  Serial.begin(115200);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
  // wait until serial port opens for native USB devices
  while (! Serial) {
    delay(1);
  }
  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
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
    int distance = measure.RangeMilliMeter;
  }
   if (measure.RangeMilliMeter<=100){
    digitalWrite(8,1);
    digitalWrite(9,0);
  }
  else if (measure.RangeMilliMeter>100){
    digitalWrite(8,0);
    digitalWrite(9,1);
  }
  else {
    digitalWrite(8,0);
    digitalWrite(9,0);
  }

}