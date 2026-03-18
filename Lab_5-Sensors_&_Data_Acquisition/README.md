# Lab 5: Sensor Integration and Data Mapping

## Overview
This lab focused on practical application of analog and digital sensors. The project involved two main parts: determining the optimal passive resistor for a photoresistor-based voltage divider and implementing real-time distance measurement using an ultrasonic sensor.

## System Components

###  1. Photoresistor
Optimize the sensitivty of a phtoresistor, different passive resistors (1kΩ, 5kΩ, 10kΩ, 20kΩ, 30kΩ) were tested in a voltage divider configuration.
*  **Objective:** Find the reistor that provides the best range of operation and linear sensitivity.
*  **Findings:** A 10kΩ resistor was found the be the best match, providing a wife range of output bits relative to the fluctuation of lumens.


### Photoresistor Logic

```cpp
void loop() {
  // Read ADC values between 0-1023 (0 = 0V, 1023 = 5V)
  int luminosity = analogRead(photoResistor_Pin);
  Serial.println(luminosity);
  delay(100); // 100ms sampling rate
}
```

###  2. Ultrasonic Distance Tracking
Measure distance from the sensor by calculating the time-of-flight of an ultrasonic pusle. The system sends out a pusle and measure the time it takes for the pulse to reach back to the sensor. 
*  **Trgger:** A 10µs HIGH pulse is sent to the `trigpin` to initiate the sensor
*  **Measurement:** The duration of the return echo is converted to inches using the speed of sound

### Ultrasonic Logic

```cpp
void loop() {
  long duration;
  float posInches;

  // Trigger the 10-microsecond pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo duration and convert to inches
  duration = pulseIn(echoPin, HIGH);
  posInches = (duration / 74) / 2; 

  Serial.print(posInches);
  Serial.println(" inches");
  delay(100);
}
```

###  3. Thermistor 
Implement a thermal sensing cricuit to monitor ambient temperature changes using different passive resistors (120Ω, 240Ω, 360Ω, 1.5kΩ, 5kΩ) were tested in a voltage divider configuration.
*  **Objective:** Use a NTC (Negative Temperature Coefficent) thermistor with the Arduino ADC to capture thermal data
*  **Findings:** As temeprature increases, the resistance of the thermistor decreases, resulting in a higher voltage reading at the analog pin.

### Thermistor Logic

```cpp
void loop() {
  int temperature = analogRead(ThermoResistor_Pin);
  Serial.println(temperature);
  delay(50); // High-frequency sampling for thermal gradients
}
```
## Lessons Learned
*  **Resistors:** The "ideal" passive resistor in a voltage divider should closely match the sensor's resistance at its most common operating point to maximize sensitivity
*  **Pulse Duration:** Discovered that even minor deviations in the trigger pulse timing `delayMicroseconds` can impact the reliability of the sensor
*  **Noise:** Observed that analog sensor readings can be noisy, necessitating a small `delay()` or software filtering to stabilize data for graphing.
