const int LED = 6;
int pinPot = 0;
int potVal = 0;

void setup() {
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
}

void loop () {
    potVal = analogRead(pinPot);
    potVal = map(potVal, 0, 1023, 0, 255);
    analogWrite(LED, potVal);
    Serial.println(potVal);
    delay(200);
}