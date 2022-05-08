const int Motion_Sensor_PIN = 7;
const int LED = 6;
int motionStateCurrent = LOW;
int motionStatePrevious = LOW;

void setup() {
    Serial.begin(9600);
    pinMode(Motion_Sensor_PIN, INPUT);
}

void loop() {
    motionStatePrevious = motionStateCurrent;
    motionStateCurrent = digitalRead(Motion_Sensor_PIN, INPUT);

    if (motionatStatePrevious == LOW && motionStateCurrent == HIGH) {
    Serial.println("I see you");
    digitalWrite(LED, HIGH);

  else 
  if (motionStatePrevious == HIGH && motionStateCurrent == LOW) {
    Serial.println("You ran away :(");
    digitalWrite(LED, LOW);
}