// Lab 5: UltraSonic Sensor
// Tyler W. Grindrod

#define echoPin 8
#define trigPin 12


void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.println("Psotion_Inches, Time_ms");
}

void loop() {
  long duration;
  float posInches;
  unsigned long currentTime = millis();

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  duration = pulseIn(echoPin, HIGH);
  posInches = (duration / 74) / 2; 


  Serial.print(posInches);
  Serial.print(",");
  Serial.print(currentTime);
  Serial.println();

  delay(100);
}
