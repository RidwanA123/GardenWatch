

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int buzzerpin = 7;
RF24 radio(8, 9); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
    pinMode(LED_BUILTIN, OUTPUT);  
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()) {  //When a signal is received, send serial over to Python
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println("B");
    tone(buzzerpin,500,1000);  //Beep
}
}
