#include <Ultrasonic.h>
#include <SoftwareSerial.h>
SoftwareSerial T_serial(52,53);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  T_serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 T_serial.print("HELLO");
 char p = T_serial.read();
 Serial.println(p);
}
