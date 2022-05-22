#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int pirValue;
int soundSensor;
int digitalSoundSensor;
int pirPin = 25;
int buzzerPin = 9;
int soundPin = A1;
int digitalsoundpin = 2;
bool analog = false;


RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";
void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

  pinMode(pirPin, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);



}

void loop() {
  // put your main code here, to run repeatedly:
 const char text[] = "Motion Detected (RF)";
  pirValue = digitalRead(pirPin);
  soundSensor = analogRead(soundPin);
  digitalSoundSensor = digitalRead(digitalsoundpin);
  Serial.println(soundSensor);
  
  if (pirValue == HIGH) {
    if (analog == true) {
      if (soundSensor < 520 || soundSensor > 522) {
      delay(100);
      radio.write(&text, sizeof(text));
      Serial.println("ANIMAL");
      tone(buzzerPin, 800, 4000);
      delay(3000);
      //Send Picture

    }
   

    }
    else{
      if (digitalSoundSensor == HIGH) {
      delay(100);
      radio.write(&text, sizeof(text));
      Serial.println("ANIMAL");
      tone(buzzerPin, 800, 4000);
      delay(3000);
    }
  }
}
}
