#include <Adafruit_Sensor.h>

// C++ code
//
bool val=0;
bool last_val=0;
bool led_status=0;
void setup()
{
  Serial.begin(9600);
  pinMode(13,INPUT_PULLUP);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop(){
  val=digitalRead(13);
  if (val!=last_val&&val&&!led_status){
    digitalWrite(12,HIGH);
    digitalWrite(11,1);
    led_status=1;
    Serial.println("on led");
  }else if(val!=last_val&&val&&led_status){
    digitalWrite(12,0);
    digitalWrite(11,0);
    led_status=0;
    Serial.println("off led");
  }
	last_val=val;
}
  
