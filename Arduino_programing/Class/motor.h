#include "Arduino.h"
class motor{
  private:
          int pin1,pin2,pow;
  public:
        motor(int pinR,int pinL){
          pin2=pinL;
          pin1=pinR;
        }
  void init(){
    pinMode(pin1, OUTPUT);
    pinMode(pin2 , OUTPUT);
  }
  void drive(int p){
        if(p>0)
        {
          analogWrite(pin1, p);
          digitalWrite(pin2, 0);
        }
        else if(p<0)
        {
          analogWrite(pin2, p);
          digitalWrite(pin1, 0);
        }
        else
        {
          digitalWrite(pin1, 0);
          digitalWrite(pin2, 0);
        }
  }
};