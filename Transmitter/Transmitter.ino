int pirValue;
  int pirPin = 6;
  int buzzerPin = 7;
void setup() {


  pinMode(pirPin, INPUT);
  pinMode(9, OUTPUT);
 Serial.begin(9600);

  

}

void loop() {
  // put your main code here, to run repeatedly:
  pirValue = digitalRead(pirPin);
  if (pirValue == HIGH) {
    Serial.println("ANIMAL");
        tone(buzzerPin,800,4000);
    delay(1000);
    //Send Radio Signal
    //Send Picture
    //Buzzer
    
    
  }
}
