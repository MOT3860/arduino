// C++ code
//define voltage by using aduino board on pin analog
void setup(){
  Serial.begin(9600);
  pinMode(A3,INPUT); 
}
void loop(){
  long val = analogRead(A3); 
  
   //int voltage=(5*val)/1023;
   int per = val*100/1023;
  //Serial.println(voltage);
  Serial.println("%");Serial.print(per);
}
