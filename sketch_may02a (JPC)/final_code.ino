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
int oldButtonState = LOW; // old button state for previous input made
int ledState = LOW; // initialised value of the led state when the push button turns on 


void setup() {
    // Set's up the motion sensor
    Serial.begin(9600);
    pinMode(Motion_Sensor_PIN, INPUT);
    pinMode(LED, OUTPUT); 
    //the LED, OUTPUT is a setup of the LED light for the potentiometer and pushbutton

    // Set's up the pushbutton
    pinMode(buttonPin, INPUT_PULLUP);


}

void loop() {
    // Loops a motion sensor on what it should do
    motionStatePrevious = motionStateCurrent; // stores the old state 
    motionStateCurrent = digitalRead(Motion_Sensor_PIN); // reads the new state 

    if (motionStatePrevious == LOW && motionStateCurrent == HIGH) { // A conditional that basically says if the previous state
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
    Serial.println(potVal); // Also reads out the value from the potentiometer for feedback. Not needed but it's there
    delay(200); // delay it by 2/10 of a second or 200 miliseconds 

    // Loops the push button
    buttonState = digitalRead(buttonPin); // The button state is the state of the button either pressed or not

    if (buttonState != oldButtonState && buttonState == HIGH) 
    // if button state DOES NOT EQUAL to the old button state AND the pressed button state, then the below
    // function will run.
    {
      ledState = (ledState == LOW ? HIGH : LOW); 
      // if LED State of the LED light IS EQUAL TO it being off and if that's true then check if it's on and ignores 
      // if it's off again henceforth the :
      digitalWrite(LED, ledState); // the LED light will turn on or off based on the button whether it's pressed or not
      delay(50); // delays by 50 miliseconds or 1/20 of a second
      oldButtonState = buttonState; // The old button state will store whatever the current button state has done

    // Loops the light sensor; collects light   
    int analogValue = analogRead(A1); // Reads the sensor value 

    Serial.print("Brightness: "); // prints out the string 
    Serial.print(analogValue); // Reads out whatever the light sensor picks up

    if (analogValue <10) { // If the light sensor value is less than 10
      Serial.println("Dark!"); // Prints out string value
    } else
    if (analogValue >800) { // else if light sensor value is greeater than 800
      Serial.println("TOO BRIGHT AHHHHH!"); // Prints out string value
    }

    }
}

// All code referencing and credits will be put in the reference list on the evaluation sheet :)