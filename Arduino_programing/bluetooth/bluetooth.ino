
#include <SoftwareSerial.h>
SoftwareSerial myserial (11,12);//Rx tx 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myserial.begin(9600);
  myserial.begin(9600);
}
void loop() {
  if (myserial.available())
  {
   Serial.write(myserial.read());
  }
}