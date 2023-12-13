/*
  Water sensing - living wall

 
*/

// constants won't change. They're used here to set pin numbers:
const int mainRes = 2;   // the number of the water sensor for main resevoir
const int resAPin = 3;  // the number of the water sensor for resevoir A pin
const int resDPin = 4;  // the number of the water sensor for resevoir B pin
const int pump = 13;    // the number of the pump pin

// variables will change:
bool mainState = HIGH;  // variable for reading the pushbutton status
bool resAState = LOW;  // variable for reading the pushbutton status
bool resDState = LOW;  // variable for reading the pushbutton status
bool pumpCommand = LOW;  // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(pump, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(mainRes, INPUT);
  pinMode(resAPin, INPUT);
  pinMode(resDPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  //mainState = digitalRead(mainRes);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  mainState = digitalRead(mainRes);
  resAState = digitalRead(resAPin);
  resDState = digitalRead(resDPin);

  pumpCommand = (mainState && !resAState && !resDState) || (mainState && !resAState && resDState) || (mainState && resAState && !resDState);

  Serial.println(pumpCommand);

  if (pumpCommand == HIGH) {
    // turn LED on:
    digitalWrite(pump, HIGH);
  } 
  else {
    // turn LED off:
    digitalWrite(pump, LOW);
  }

}
