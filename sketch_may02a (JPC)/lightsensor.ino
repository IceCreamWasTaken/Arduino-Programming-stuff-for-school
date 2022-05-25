void setup() {
    Serial.begin(9600);
}

void loop() {
    int analogValue = analogRead(A1);

    Serial.print("Brightness: ")
    Serial.print(analogValue);

    if (analogValue <10) {
        Serial.println("- Dark");
    }
}