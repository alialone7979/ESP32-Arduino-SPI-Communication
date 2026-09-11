
#include <SPI.h>
int led = 7;
int button = 2;

volatile boolean received;
int slavereceived,slavesend;
int buttonstate;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(button,INPUT_PULLUP);
  pinMode(MISO,OUTPUT);
  SPCR |= _BV(SPE);
  received = false;
  SPI.attachInterrupt();
}

ISR (SPI_STC_vect){
  slavereceived = SPDR;
  received = true;
}

void loop() {
  if (received == 1){
    Serial.println(slavereceived);
    if (slavereceived == 1){
      digitalWrite(led,HIGH);
    }
    else{
      digitalWrite(led,LOW);
    }
    buttonstate = digitalRead(button);
    if (buttonstate == LOW){
      slavesend = 1;
    }
    else{
      slavesend = 0;
    }
    SPDR = slavesend;
    delay(200);
  }
}
