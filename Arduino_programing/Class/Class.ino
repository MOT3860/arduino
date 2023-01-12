#include <SoftwareSerial.h>
#include "motor.h"
SoftwareSerial BTSerial(3, 2);  //Tx,Rx
motor motor1(5, 6);             //RX,TX
motor motor2(7, 8);
motor motor3(9, 10);
motor motor4(11, 12);
int power;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(38400);
  //Serial1.begin(9600);
  // Serial.println("ATcommand");
  motor1.init();
  motor2.init();
  motor3.init();
  motor4.init();  //ATcommand Start
}

void loop() {
  if (Serial1.available())
  //   Serial.write(BTSerial.read());
  //   motor1.drive(100);
  //   motor2.drive(100);
  // if (Serial.available())
  //   BTSerial.write(Serial.read());
  //if(Serial.available())


  {
    //Serial.println(Serial1.readStringUntil('*'));
    String ch = Serial1.readStringUntil('*');
    String X = ch.substring(ch.indexOf('X') + 1, ch.indexOf('Y'));
    String Y = ch.substring(ch.lastIndexOf('Y')+1,ch.lastIndexOf('*'));
    //int powerX = X.toInt();
    Serial.println(X);    
    Serial.println(Y);
    if (ch == 'F') {
      power = 100;
    } else if (ch == 'B') {
      power = -100;
    } else if (ch == 'L') {
      power = 50;
    } else if (ch == 'R') {
      power = -50;
    }
    // else
    // {
    //   power=0;
    // }
    //Serial.println(ch);
    // motor1.drive(powerX);
  }
  // motor2.drive(power);
  // motor3.drive(power);
  // motor4.drive(power);
}