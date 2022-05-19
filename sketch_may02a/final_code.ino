// Set's all the known variables, with the pins connected to the arduino. Separate spaces means that it 
// comprises a different part

// The void setup and loop goes in the following order in the order in which I programmed the part:
// Motion Sensor > Potentiometer > PushButton > LightSensor

// There will be some duplicated lines of code, which those will be negated and will be mentioned as a code comment
// next to the code if it's been duplicated



// Set's the pins for the motion sensor
const int Motion_Sensor_PIN = 7; // A constant integer that can't change value to pin 7 as variable name 'Motion_Sensor_PIN'
const int LED = 6; // constant integer, connected to pin 6 as this is the LED light
int motionStateCurrent = LOW; 
int motionStatePrevious = LOW;
// the motionStateCurrent and motionStatePrevious are both variables used later, henceforth both need to start as LOW 
// as a way to reset the sensor and set's it as off.


// Set's the pins for the potentiometer 
int pinPot = 0; // Set's the initial value for the potentiometer as zero
int potVal = 0; // Set's the variable when turned left and right of the knob, to zero


// Set's the pins for the push button
const int buttonPin = 8; // Constant integer of the button as a digital input as pin 8
int buttonState = 0; // a changeable state of the button when pressed, sets to zero to start with (or sets it to zero when reset)
int flag = 0; // variable that indicates a boolean logic value (as 0s or 1s, ups or downs, true or false)


void setup() {
    // Set's up the motion sensor
    Serial.begin(9600);
    pinMode(Motion_Sensor_PIN, INPUT);
    pinMode(LED, OUTPUT); 
    //the LED, OUTPUT is a setup of the LED light for the potentiometer and pushbutton

    // Set's up the pushbutton
    pinMode(butttonPin, INPUT_PULLUP);


}

void loop() {
    // Loops a motion sensor on what it should do
    motionStatePrevious = motionStateCurrent; // stores the old state 
    motionStateCurrent = digitalRead(Motion_Sensor_PIN); // reads the new state 

    if (motionatStatePrevious == LOW && motionStateCurrent == HIGH) { // A conditional that basically says if the previous state
    // is off and the current state is on then the bottom functions will be run
    Serial.println("I see you"); // Prints a message through the serial monitor
    digitalWrite(LED, HIGH); // turns on the LED 
    }
  else 
  if (motionStatePrevious == HIGH && motionStateCurrent == LOW) { // A conditional saying if the previous state is high 
  // or if it's on and the current state is off the bottom functions will be run
    Serial.println("You ran away :("); // Prints a message through the serial monitor 
    digitalWrite(LED, LOW); // turns off the LED
}
    // Loops the potentiometer adjusting the brightness manually
    potVal = analogRead(pinPot); // Analog input of the actual potentiometer which is converted to a number
    potVal = map(potVal, 0, 1023, 0, 255); // adjusted based on the mapping configurations of the potentiometer 
    analogWrite(LED, potVal); // LED brightness get's adjusted based off potVal value
    Serial.println(potVal); // Also reads out the value from the potentiometer for feedback
    delay(200); // delay it by 2/10 of a second or 200 miliseconds 

    // Loops the push
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

