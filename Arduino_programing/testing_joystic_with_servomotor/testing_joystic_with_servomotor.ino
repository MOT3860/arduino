#include <Servo.h>
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT); 
  pinMode(2,INPUT);
  // pinMode(13,OUTPUT);
  // pinMode(12,OUTPUT);
  myservo.attach(13);

}

void loop() {
  // put your main code here, to run repeatedly:
  int x = analogRead(A0);
  int y = analogRead(A1);
   int pos1= (x*180.0)/1023.0;
   //int pos2= (y*180.0)/1023.0;
   //myservo.write(pos1);
if (pos1<86.0){
    myservo.write(pos1);
  Serial.println(pos1);
} 
else if (pos1>86.0){
  myservo.write(pos1);
    Serial.println(pos1);
}
else {
  myservo.write(pos1);
}
}
