const int sensorPin = 2;
int pinNow = LOW;
int pinPrevious = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);

}

void loop() {
  pinPrevious = pinNow;
  pinNow = digitalRead(sensorPin);
  if (pinPrevious == LOW && pinNow == HIGH) {
    Serial.println("I see you");

  else if (pinPrevious == HIGH && pinNow == LOW) {
    Serial.println("You ran away :(");
  }

  }


}