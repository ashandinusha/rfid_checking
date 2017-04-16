/*
 * Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 */

#include <SPI.h> //Serial Port connection enable
#include <MFRC522.h> //RFID module import

#define RST_PIN         5          // Configurable, see typical pin layout above
#define SS_PIN          53         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup(){

    Serial.begin(9600);
    mfrc522.PCD_Init();   // Init MFRC522
    mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details

}

void loop(){

    //This will look for new cards
     if ( (! mfrc522.PICC_IsNewCardPresent()) || ( ! mfrc522.PICC_ReadCardSerial())) {

         /*TODO here goes the code to navigate the car until it meet 
          predefined rfid tag*/
     }else{
         /*If any RFID tag is detected then the id of the tag will send via bluetooth to Mobile serial
        */

          String s = "";
    for (byte i = 0; i < mfrc522.uid.size; i++)
    {
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      s += (String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
      s += (String(mfrc522.uid.uidByte[i], HEX));
    }
     BTserial.println("ID " + String(s));
     }


}