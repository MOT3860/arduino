#include <ArduinoJson.h>
// #include <Ultrasonic.h>
#include <SoftwareSerial.h>
#include "motor.h"
//Ultrasonic ult(53, 51);           //ECO,TRI
SoftwareSerial BTSerial(18, 19);  //Tx,Rx
motor motor4(4, 5);               //RPWM,LPWM
motor motor3(6, 7);
motor motor1(8, 9);
motor motor2(10, 11);
motor motor5(2,3);
// int R_en[] = { 25, 29, 33, 37 };
// int L_en[] = { 23, 27, 31, 35 };
int power;
int dist;
unsigned long counter;
// int period = 500;
// unsigned long time_out = 0;
//volatile bool status;
void setup() {
  Serial.begin(9600);
  //BTSerial.begin(38400);
  Serial1.begin(9600);
  // Serial.println("ATcommand");
  // for (int i = 0; i < 4; i++) {
  //   pinMode(R_en[i], OUTPUT);
  //   pinMode(L_en[i], OUTPUT);
  //   digitalWrite(R_en[i], 1);
  //   digitalWrite(L_en[i], 1);
  // }
  motor1.init();  
  motor2.init();
  motor3.init();
  motor4.init();  //ATcommand Start
  motor5.init();
}
int x1, y1, x2, y2;
int M1, M2, M4, M3,M5;
void loop() {
  String x = "";
  //dist = ult.read();
  if (Serial1.available() >= 1) {
    counter = millis();
    x = Serial1.readStringUntil('#');
    //Serial.println(x);
    StaticJsonDocument<200> doc;
    deserializeJson(doc, x);
    int value = doc["valueX"];
    x1 = doc["joys"][0];
    y1 = doc["joys"][1];
    x2 = doc["joys"][2];
    y2 = doc["joys"][3];
    int button1 = doc["buttons"][0];
    // if (button1 ==0) {
    //   digitalWrite(49, HIGH);
    //   digitalWrite(47, LOW);
    //   Serial.println("shoot");
    // }
    // if (button1 != 0) {
    //   digitalWrite(49, LOW);
    //   digitalWrite(47, LOW);
    //   Serial.println("unshoot");
    // }
    if (x1 <= 5 && x1 > -5 && y1 >= -9 && y1 <= 0) {
      x1 = 0;
      y1 = 0;
    }
    if (x2 <= 4 && x2 >= -15 && y2 >= -15 && y2 <= 0) {
      x2 = 0;
      y2 = 0;
    }
    M1 = y1 + x1;
    M2 = y1 - x1;
    M3 = y1 + x1;
    M4 = y1 - x1;
    
    if (x2 <= 255 && x2 > 0 && y2 <= 0 && y2 >= -20) {
      M1 = y2 + x2;
      M2 = y2 - x2;
      M3 = y2 - x2;
      M4 = y2 + x2;
      Serial.println("Left");
    }
    if (x2 >= -255 && x2 < 0 && y2 <= 0 && y2 >= -20) {
      M1 = y2 + x2;
      M2 = y2 - x2;
      M3 = y2 - x2;
      M4 = y2 + x2;
      Serial.println("Rigth");
    }
    if (y2>=-255 && y2 < 0 && x2 >0){
      M5 = y2;
      Serial.println("shoot");
    }
    else{
      M5 =0;
    }
  }
  if (millis() - counter >= 500) {
    M1 = 0;
    M2 = 0;
    M3 = 0;
    M4 = 0;
    M5 = 0;
  }
  motor1.drive(M1);
  motor2.drive(M2);
  motor3.drive(M3);
  motor4.drive(M4);
  motor5.drive(M5);
  Serial.println(x2);
}
