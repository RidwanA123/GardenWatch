int pirValue;
int soundSensor;
  int pirPin = 25;
  int buzzerPin = 8;
  int soundPin = A1;
void setup() {


  pinMode(pirPin, INPUT);
  pinMode(9, OUTPUT);
 Serial.begin(9600);

  

}

void loop() {
  // put your main code here, to run repeatedly:
  pirValue = digitalRead(pirPin);
  soundSensor = analogRead(soundPin);

  if (pirValue == HIGH) {
    if (soundSensor <519) {
      delay(100);
    Serial.println("ANIMAL");
        tone(buzzerPin,800,4000);
    delay(3000);
    //Send Radio Signal
    //Send Picture
    //Buzzer
    }
    
  }
}
