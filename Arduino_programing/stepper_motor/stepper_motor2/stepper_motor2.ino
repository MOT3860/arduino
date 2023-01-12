#include <Stepper.h>
#define STEPS 32
Stepper stepper(STEPS,8,9,10,11);
int val=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  stepper.setSpeed(200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0);
  {
    val=Serial.parseInt();
    stepper.step(val);
    Serial.println(val);
    
  }
}
