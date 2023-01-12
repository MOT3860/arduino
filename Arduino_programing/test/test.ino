#define L_EN  11
#define R_EN  10
#define RPWM 9
#define LPWM 8
void setup() {
pinMode(L_EN,OUTPUT);
pinMode(R_EN,OUTPUT);
pinMode(RPWM,OUTPUT);
pinMode(LPWM,OUTPUT);

digitalWrite(L_EN,HIGH);
digitalWrite(R_EN,HIGH);

}

void loop() {
  analogWrite(LPWM,HIGH);      
  analogWrite(RPWM,255);
}
