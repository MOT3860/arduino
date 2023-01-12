#include <SoftwareSerial.h>
SoftwareSerial R_serial(2,3);//rx,tx
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  R_serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  if (R_serial.available()){
    char b = R_serial.read();
    R_serial.print("HI");
   Serial.println(b);
}
}
