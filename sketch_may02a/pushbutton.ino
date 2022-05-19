const int buttonPin = 8;
const int LED = 6;
int buttonState = 0;
int flag = 0;

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(butttonPin, INPUT_PULLUP); 
}

void loop() {
    buttonState = digitalRead(buttonPin)
    
    if (buttonState == LOW) {
        if (flag == 0){
            digitalWrite(LED, HIGH);
            flag = 1;
        }
    else 
    if (flag == 1){
        digitalWrite(LED, LOW);
        flag = 0;   
    }
}
}