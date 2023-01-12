// C++ code
//define voltage by using aduino board on pin analog
void setup(){
  Serial.begin(9600);
  pinMode(A5,INPUT);    
  pinMode(13,OUTPUT);
}
void loop(){
  int val = analogRead(A5); 
  digitalWrite(13,1);
// int val1 = (val*255.0)/1023.0;
//  analogWrite(11,val1);
  
   int voltage1=(1023*val)/1023;
   //int voltage2=(5*val2)/5;
   //int per = voltage*100/5;
  //Serial.println(voltage);
  //Serial.println("%");Serial.print(per);
  Serial.println(voltage1);
  delay(100);
  // Serial.println(val1);
  // delay(100);
  // Serial.println(val);
  // delay(100);

}
