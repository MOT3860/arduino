#include <ArduinoJson.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(12, 13);  // RX, TX
void setup() {
  Serial.begin(9600);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(6,OUTPUT);
  pinMode(7,INPUT_PULLUP);
  mySerial.begin(9600);
}
long valx1, valy1, valx2, valy2;
void loop() {  // run over and over
// Serial.println(digitalRead(7));
  int y1 = analogRead(A4);
  int x1 = analogRead(A5);
  int y2 = analogRead(A2);
  int x2 = analogRead(A3);
  for (int i = 0; i <70; i++) {
    valx1 += x1;
    valy1 += y1;
    valx2 += x2;
    valy2 += y2;
  }
  x1 = map(valx1 / 70, 0, 1023, -255, 255);
  y1 = map(valy1 / 70, 0, 1023, -255, 255);
  y2 = map(valy2 / 70, 0, 1023, -255, 255);
  x2 = map(valx2 / 70, 0, 1023, -255, 255);
  valx1 = 0;
  valy1 = 0;
  valx2 = 0;
  valy2 = 0;
  //   if (prex1 != x1 || prey1 != y1 || prex2 != x2 || prey2 != y2) {
    StaticJsonDocument<200> doc;
    JsonArray joys = doc.createNestedArray("joys");  //using an array in json
    joys.add(x1);
    joys.add(y1);
    joys.add(x2);
    joys.add(y2);
    JsonArray buttons = doc.createNestedArray("buttons");
    buttons.add(digitalRead(7));
    //buttons.add(0);
    serializeJson(doc, Serial);
    Serial.println("#");
    serializeJson(doc, mySerial);
    mySerial.println("#");
    delay(10);
  // }
  //data = "";
  // prex1 = x1;
  // prey1 = y1;
  // prex2 = x2;
  // prey2 = y2;
  // last_millis = millis;
}