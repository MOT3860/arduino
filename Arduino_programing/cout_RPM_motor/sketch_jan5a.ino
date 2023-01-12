#include <Encoder.h>
Encoder encod(2,3);
long count=0;
long lastcount=0;
bool val =0;
long distance =0;
long lastdist=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(6,OUTPUT);
  pinMode(7,INPUT_PULLUP);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(7);
  count = encod.read();
  long rpm = 60.0* (count-lastcount)/(17.0*25.0)/0.016;
  lastcount= count;
  //Serial.println(rpm);
  distance =count/(68.0*25.0) ;
  int d =distance;
  //analogWrite(9,0);
  // lastdist =distance;
   if (d==2&&val&&!lastdist){
    analogWrite(9,0);
   //count -count;
   //d++;
   //Serial.println(d);
   }
  else if (!val&&d==0){
    analogWrite(9,100);
    Serial.println("h");
  }
   d =  count-lastcount;
  Serial.println(count-lastcount);
 // Serial.println(rpm);
}
