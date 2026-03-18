#include <Servo.h>
Servo myServo;
// D# → Digital GPIO Pin # located on Adruino board
const int xPin = A0; // Joystick X-axis → A0 pin
const int yPin = A1; // Joystick Y-axis → A1 pin
const int swPin = 2; // Joystick Switch → Pin D2 
const int ledPin = 11; // Led throttle → Pin D10
const int buzzerPin = 6; // Active Buzzer Horn → Pin D6
const int servoPin = 9; // Servo Motor → Pin D9
void setup() {
 // put your setup code here, to run once:
pinMode(ledPin, OUTPUT);
digitalWrite(ledPin, LOW);
pinMode (buzzerPin, OUTPUT);
digitalWrite(buzzerPin, LOW);
pinMode(swPin, INPUT_PULLUP); 
myServo.attach(servoPin); // Servo to control pin
myServo.write(90);
// Monitor to help Debug
Serial.begin(9600);
}
void loop() {
//--------READ INPUTS--------//
int xVal = analogRead(xPin); // 
int yVal = analogRead(yPin); // 
int swVal = digitalRead(swPin); // 
//--------Throttle Led via X-axis on Joystick--------//
// Our goal is map joystick X (0-1023 to LED PWM (0-255)
int ledPWM = map(xVal, 0, 1023, 0, 255);
analogWrite(ledPin, ledPWM); 
//--------Steering Servo via Y-axis on Joystick--------//
// Our goal is to map Joystick Y (0-1023) to servo angle (0°→180°)
int servoAngle = map(yVal, 0, 1023, 0, 180);
myServo.write(servoAngle);
//--------Activate Buzzer via Joystick toggle--------//
if (swVal == LOW) {
 digitalWrite(buzzerPin, HIGH); // Button pressed → Buzzer on
} else {
 digitalWrite(buzzerPin,LOW); // Button released → Buzzer off
}
Serial.print("X = "); Serial.print(xVal);
Serial.print(" | Y = "); Serial.print(yVal);
Serial.print(" | SW = "); Serial.println(swVal);
delay(10); // Stability delay for 10 ms
}
