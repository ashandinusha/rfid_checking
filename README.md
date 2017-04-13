# rfid_checking
##RC522 Module checking with Arduino UNO

 Typical pin layout used:
 
|Signal| MFRC522 Reader/PCD Pin| UNO|Mega|
|------|-----------------------|----|----|
|RST/Reset| RST| 9 | 5|
|SPI SS   |  SDA(SS)    |  10|53 |
|SPI MOSI |  MOSI       |  11 / ICSP-4|   51|
|SPI MISO |  MISO       |  12 / ICSP-1|   50|
|SPI SCK  |  SCK        |  13 / ICSP-3|   52|
 
