#include <Stepper.h>

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

// Potentiometer
#define POT A0
unsigned long minDelay = 2500; // Fastest speed(2.5 ms)
unsigned  long maxDelay = 8000; // slow speed (8 ms)

int deadband = 30;
int stepNumber = 0;

void setup() {
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  Serial.begin(115200);
}

void loop(){
  int potValue = analogRead(POT); // 0 to 1023

  float voltage  = potValue * (5 / 1023.0 );
  
  int distanceFromCenter = potValue - 512;

  unsigned long delayValue;


  if (abs(distanceFromCenter) < deadband) {

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delayValue = maxDelay;
  }

  else {
    int magnitude = abs(distanceFromCenter);
    // map from max Delay at center to mindelay at edges
    delayValue = map(magnitude,0,512,maxDelay,minDelay );
    if (distanceFromCenter > 0) {
      stepNumber++;
    }
    else {
      stepNumber--;
    }

      if (stepNumber > 3)stepNumber = 0;
      if (stepNumber < 0)stepNumber = 3;

      if (stepNumber == 0) {
        digitalWrite(IN1,HIGH);
        digitalWrite(IN2,LOW);
        digitalWrite(IN3,LOW);
        digitalWrite(IN4,LOW);
      }

      else if(stepNumber == 1) {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
      }
        else if(stepNumber == 2) {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
      }

        else if(stepNumber == 3) {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);

      }
  }

    delayMicroseconds(delayValue);

    static int counter = 0;
    counter++;

    if(counter > 200) {
      Serial.print(voltage); // X-axis is input voltage
      Serial.print(";"); // semicolon seperator
      Serial.println(delayValue); // y-axis in milliseconds
      counter = 0 ;
    }

}
