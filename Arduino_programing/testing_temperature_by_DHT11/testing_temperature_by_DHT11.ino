#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("DHTxxtest!"));
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if(isnan(h)||isnan(t)||isnan(f)) { 
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float hif = dht.computeHeatIndex(f,h);
  float hic = dht.computeHeatIndex(t,h,false);
  
  Serial.println(F("Humidity:"));
  Serial.print(h);
  Serial.print(F("% temperatuer:"));
  Serial.print(t);
  Serial.println(F("C"));
  Serial.print(f);
  Serial.println(F("F Heat index:"));
  Serial.print(hic);
  Serial.print(F("C"));
  Serial.print(hif);
  Serial.println(F("F"));
}