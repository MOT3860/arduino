
#include <Ultrasonic.h>
Ultrasonic ultrasonic(12,13);
int distance;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
distance= ultrasonic.read();
//Serial.print(myserial.read());
//float mettre = (distance *1)/100;
Serial.print("distance in CM ");  
Serial.println(distance);

}