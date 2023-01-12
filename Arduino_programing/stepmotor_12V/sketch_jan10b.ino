#include <AccelStepper.h>
#define dirPin 2
#define stepPin 5
#define motorInterfaceType 8

// Create a new instance of the AccelStepper class:
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);

void setup() {
stepper.setMaxSpeed(1000);
stepper.setAcceleration(500);
}

void loop() {
stepper.moveTo(8000);
stepper.runToPosition();
delay(1000);
// Move back to zero:
stepper.moveTo(0);
stepper.runToPosition();
delay(1000);
}