#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int pirPin = 6;
int pirValue;
RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
    pinMode(pirPin, INPUT);
    Serial.begin(9600);
}

void loop() {

   pirValue = digitalRead(pirPin);
  if (true) {
      int text = 69;
      radio.write(&text, sizeof(text));
  Serial.println("Motion detected");
  delay(500);
  }
  
}
