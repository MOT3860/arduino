
//int segment[10] = {0,0,1,1,0,0,1,1,1,0};
int num[]= {B1111110,B0000110,B1101101,B1111001,B0110011,B1011011,B1011111,B1110000,B1111111,B1111011};
void setup() {
  Serial.begin(9600);
 for (int i =2;i<=9;i++){
   pinMode(i,OUTPUT);
 }
}
int t (int n){
  int x=n;
 // int num[]= {B1111110,B0000110,B1101101,B1111001,B0110011,B1011011,B1011111,B1110000,B1111111,B1111011};
  for (int i=2;i<=9;i++){
    digitalWrite(i,bitRead(num[x],i-2));
  }
}
 void loop() {
  for (int j=0; j<=9; j++){
  for (int i=2; i<=9; i++){
  digitalWrite(i,bitRead(t(j),i-2));
  Serial.println(j);
  }
delay(300);
  // digitalWrite(13,1);
  // digitalWrite(12,1);
  // digitalWrite(7,1);
  // digitalWrite(9,1);
  // digitalWrite(10,1);
  // digitalWrite(11,0);
  // delay(500);
  // digitalWrite(13,1);
  // digitalWrite(12,1);
  // digitalWrite(7,1);
  // digitalWrite(9,0);
  // digitalWrite(10,1);
  // digitalWrite(11,1);
  // delay(500);
  }
  }
