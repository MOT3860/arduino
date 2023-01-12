#include <SoftwareSerial.h>
SoftwareSerial bt_serial(18,19);//Tx,Rx
int R_EN[]={37,33,29,25};
int L_EN[]={35,31,27,23};
int LPWM[]={11,9,7,5};
int RPWM[]={10,8,6,4};

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
bt_serial.begin(9600);
  for (int i=0;i<=3;i++){
    pinMode(R_EN[i],OUTPUT);  
    pinMode(L_EN[i],OUTPUT);
    digitalWrite(L_EN[i],HIGH);
    digitalWrite(R_EN[i],HIGH);
  }
}
void loop() {
  // if (bt_serial.available()>0){
  //   int ch = bt_serial.read();
  //   Serial.println(ch);
  // }
 for (int m= 0;m<=3;m++){
analogWrite(RPWM[m],1);
analogWrite(LPWM[m],200);   
  }
  // delay(5000);
  // for (int j=4; j>=0; j--){
  //   analogWrite(LPWM[j],HIGH);
  //   analogWrite(RPWM[j],200);
  // }
  // delay(5000);

}