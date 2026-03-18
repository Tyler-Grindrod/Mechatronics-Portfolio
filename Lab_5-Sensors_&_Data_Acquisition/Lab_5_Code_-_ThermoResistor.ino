// Lab 5: ThermoResistor Sensor
// Tyler W. Grindrod

#define ThermoResistor_Pin A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  int temperature = analogRead(ThermoResistor_Pin);
  Serial.println(temperature);
  delay(50); // wait 50ms between readings

}
