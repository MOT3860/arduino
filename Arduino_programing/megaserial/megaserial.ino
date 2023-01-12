#include <SoftwareSerial.h>
SoftwareSerial mserial(9,6);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mserial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  mserial.print("hello");
  if(mserial.available()){
    //Serial.println(mserial.read());
    mserial.print("hello");   
  }
}
