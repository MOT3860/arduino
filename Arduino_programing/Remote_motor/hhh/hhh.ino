#include <MotorControl.h>
#include <Encoder.h>
#include "motor.h"
#define CON_FREQ 50
#define MOTOR_GAIN (60*CON_FREQ) / (17.0 * 25.0)
unsigned long int timer = 0;
volatile float refSpeed = 0.0;
MotorControl control(2, 3, MOTOR_GAIN, CON_FREQ, 0.1,0);
motor motor(9, 10);
void setup() {
  Serial.begin(9600);
  motor.init();
  pinMode(13, OUTPUT);
  control.setMotorParameter(17.0, 25.0);  // CPR, Gear Ratio
  control.setInputGain(1.0);
  control.setInputDifferentialThreshold(0.5);
  control.setEncoderReadQuadrature(true);
}
void loop() {
  Serial.print(refSpeed);
  Serial.print(" ");
  Serial.println(control.getSpeed());
  if (millis() >= timer + 20) {  //50 spins per second
    timer = millis();
    int32_t pwm = control.controlCalc(refSpeed);
    motor.drive(pwm);
  }
  if (Serial.available()) {
    String x = Serial.readString();
    x.trim();
    refSpeed = x.toFloat();
  }
}