#include <SPI.h>
int led = 4;
int button = 2;
SPIClass * spi = new SPIClass(VSPI);

void setup() {
spi->begin();
pinMode(SS,OUTPUT);
pinMode(led,OUTPUT);
pinMode(button,INPUT_PULLUP);
}

void loop() {
spi->beginTransaction(SPISettings());
digitalWrite(SS,LOW);

int data;

if (digitalRead(button) == LOW){
  data = 1;
}
else{
  data = 0;
}
int daryafti = spi->transfer(data);

if(daryafti == 1){
  digitalWrite(led,HIGH);
}
else{
  digitalWrite(led,LOW);
}

digitalWrite(SS,HIGH);
spi->endTransaction();
delay(200);
}
