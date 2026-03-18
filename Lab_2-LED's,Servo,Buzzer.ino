#include <Servo.h>

Servo myServo;

const int ledPin = 11; // Check your board and verify
const int buzzerPin = 6; // Check your board and verify
const int swPin = 2;
const int servoPin = 9;

const int xpin  = A0;
void setup() {
  // put your setup code here, to run once:
pinMode(ledpin, OUTPUT);
pinMode(swPin, INPUT_PULLUP)
// buzzerPin
//servo Pin


}

void loop() {
  // put your main code here, to run repeatedly:
  // Crete three variables that respectively read the inputs of the x, y, and switch 

  // ------------ LED

// create a variable that is equated to a function that can covert this analog value to a tangible number.

// actuate (send the command) to our led based on analog input

// ------------- servo

// create a variable that is equated to a function that can covert this analog value to a tangible number
// take that variable and use a function that drives the servo to the respective angle based on the variable just created 

// ---- switch

if(swVal == LOW) {
  digitalWrite(buzzerPin, HIGH);
}

else{
  // turn buzzer off
}

  delay(10)

}
