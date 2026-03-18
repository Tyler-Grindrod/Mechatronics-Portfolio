#define en12 9
#define gate1 8
#define gate2 11
// Potentiometer
#define POT A0

void setup() {
  pinMode(en12,OUTPUT);
// Gate1 & Gate2 helpe verse the Polarity of the stepper motor
  pinMode(gate1,OUTPUT);
  pinMode(gate2,OUTPUT);
  Serial.begin(9600);
  delay(500);
  Serial.println("pot,pwm");

}

void loop(){
  int pot = analogRead(POT);
  int value = pot - 512;
  value = value/2;

  if (value > 0) {

    digitalWrite(gate1, HIGH);
    digitalWrite(gate2, LOW);
  }

  else if (value < 0) {
    digitalWrite(gate1, LOW);
    digitalWrite(gate2, HIGH);
    
  }

  else {
    digitalWrite(gate1, LOW);
    digitalWrite(gate2, LOW);
  }


  int speed = abs(value);
  analogWrite(en12, speed);
  Serial.print(pot);
  Serial.print(",");
  Serial.println(speed);

  delay(50);
   
}
