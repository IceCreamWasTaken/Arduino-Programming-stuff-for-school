const int sensorPin = 2;
int PinNow = LOW;
int PinPrevious = LOW;
int LED = 3;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);

}

void loop() {
  PinPrevious = PinNow;
  PinNow = digitalRead(sensorPin);
  if (PinPrevious == LOW && PinNow == HIGH) {
    Serial.println("I see you");
    digitalWrite(LED, HIGH);
    delay(2000);

  else if (PinPrevious == HIGH && PinNow == LOW) {
    Serial.println("You ran away :(");
    digitalWrite(LED, LOW);
    delay(2000);
  }

  }


}