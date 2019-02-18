/*
  Traffic Signal
*/

const int RED = 12;
const int BLUE = 13;
const int GREEN = 2;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.println("Traffic Singal setup");
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("RED=1  BLUE=0  GREEN=0");
  digitalWrite(RED, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(BLUE, LOW);
  digitalWrite(GREEN, LOW);
  delay(3000);                       // wait for a second

  //BLUE like Orange light it wil blow
  Serial.println("RED=0  BLUE=1  GREEN=0");
  digitalWrite(RED, LOW);
  digitalWrite(BLUE, HIGH);
  digitalWrite(GREEN, LOW);
  delay(1000);
  
  //GREEN IS ON
  Serial.println("RED=0  BLUE=0  GREEN=1");
  digitalWrite(RED, LOW);
  digitalWrite(BLUE, LOW);
  digitalWrite(GREEN, HIGH);
  delay(3000); 
}
