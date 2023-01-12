#include <EasyMFRC522.h>
#include <RfidDictionaryView.h>
#include<SPI.h>
#include<MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN,RST_PIN);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
SPI.begin();
mfrc522.PCD_Init();
Serial.println("approximate your card ot reader");
Serial.println();
}
void loop() {
  // put your main code here, to run repeatedly:
  if (!mfrc522.PICC_IsNewCardPresent()){
    return;
  }
  if (!mfrc522.PICC_ReadCardSerial()){
    return;
  }
  Serial.println("UID tag");
  String content="";
 byte letter;
  for (byte i=0;i<mfrc522.uid.size;i++){ 
    Serial.print(mfrc522.uid.uidByte[i]<0x10?"0":"");
    Serial.print(mfrc522.uid.uidByte[i]);
    content.concat(String(mfrc522.uid.uidByte[i]<0x10?"0":""));
    content.concat(String(mfrc522.uid.uidByte[i],HEX));
  } 
  for(int k=0;k<mfrc522.uid.size;k++ ){
    Serial.println(mfrc522.uid.uidByte[k]);
  }
  //Serial.print(mfrc522.uid.size);
  //Serial.print(mfrc522.uid.uidByte[1]);
  Serial.println();
  Serial.print("massage:");
 content.toUpperCase();
  if (content.substring(0)=""){
 Serial.println("Authorized access");
 Serial.println();
  delay(3000);
  }
  // else if (content.substring(0)=""){
  //   Serial.println("Authorized denied");
  //   delay(2000);
  // }
 else {
 Serial.println(" Access denied");
 delay(3000); 
 }
}