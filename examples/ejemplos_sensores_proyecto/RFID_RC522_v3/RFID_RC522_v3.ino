
#include <Wire.h>
#include "MFRC522_I2C.h"


//Conectar a J5
MFRC522 mfrc522(0x28);  // Create MFRC522 instance.



String CurrentCard;    
int CardTimeOut = 0;
int detectada=0;

void setup() {
  Serial.begin(115200);  // Initialize serial communications with the PC
  Wire.begin();          // Initialize I2C

  mfrc522.PCD_Init();  // Init MFRC522
  //ShowReaderDetails();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, type, and data blocks..."));
}

void loop (){
  // Look for new cards
  if (mfrc522.PICC_IsNewCardPresent()) {
    CardTimeOut = 0;
    
    if (mfrc522.PICC_ReadCardSerial()&&(detectada==0)) {
      detectada=1;
      long long codigo=dameCodigo() ;
      Serial.printf("%lld\n",codigo);
    }
  }
  if ((CardTimeOut == 10)&&(detectada==1)) {

    detectada=0;
    Serial.println("retirada");
  }
  CardTimeOut += 1;
}

long long dameCodigo() {
  long long codigoTarjeta = 0;
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    codigoTarjeta = codigoTarjeta + mfrc522.uid.uidByte[i] << i * 8;
  }
  return codigoTarjeta;
}

