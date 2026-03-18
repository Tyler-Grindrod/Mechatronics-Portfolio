// Lab 5: PhotoResistor Sensor
// Tyler W. Grindrod

#define photoResistor_Pin A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Read PhotoResistor Analog-to-Digital Converter (ADC) values between 0-1023
  // 0 = 0V, 1023 = 5V
  int luminosity = analogRead(photoResistor_Pin);
  Serial.println(luminosity);
  delay(100); // wait 100ms between readings

}
