#  Lab 4: DC and Stepper Motor Control

##  Overview
This lab focused on interfacing an **Arduino Uno R3** with high-current actuators.

## System Functionality

###  1. Bidirectional DC Motor Control
Using a Potentiometer, the motor speed is controlled via Pulse Width Modulation (PWM).
*  **Center Position:** Motor is off (0 PWM)
*  **Full Left/Right:** Motor Reaches maximum speed (255 PWM)
*  **Hardware:** L293D/L298N H-Bridge for polarity switching

```cpp
// Logic for Direction and Speed
int pot = analogRead(POT);
int value = pot - 512; // Center the 0-1023 input
value = value / 2;     // Scale to approx. 0-255

if (value > 0) {
    digitalWrite(gate1, HIGH); // Forward Polarity
    digitalWrite(gate2, LOW);
} else if (value < 0) {
    digitalWrite(gate1, LOW);  // Reverse Polarity
    digitalWrite(gate2, HIGH);
} else {
    digitalWrite(gate1, LOW);  // Brake/Stop
    digitalWrite(gate2, LOW);
}

int speed = abs(value);        // Absolute value for PWM
analogWrite(en12, speed);      // Send PWM signal to H-Bridge
```
## Explanation:
*  **Polaritity Switching:** `gate1` and `gate2` control the H-bridge gates to flip the voltage across the motor
*  **Linear Mapping:** Using `abs(Value)` ensure the motor spins gaster as the potentiometer moves further away from the center in either direction. 

###  2. Stepper Motor Control
The stepper motor was programmed with a custom stepping sequence to manage psotion and speed. 
*  **Speed Control:** The potentiometer adjusts the `delayMicroseconds()` between steps
*  **Manual Toggling:** To workaround using  library for the movement, this implemntation manually toggles the `IN1-IN4` pins to compelete the full-step sequence.

```cpp
// Stepper Sequence Logic
if (abs(distanceFromCenter) < deadband) {
    // Stop all coils if in deadband to prevent overheating
    digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
} else {
    // Map speed: center = maxDelay (slow), edges = minDelay (fast)
    delayValue = map(magnitude, 0, 512, maxDelay, minDelay);
    
    // Increment or Decrement step based on direction
    if (distanceFromCenter > 0) stepNumber++;
    else stepNumber--;

    // Keep stepNumber within 0-3 range
    if (stepNumber > 3) stepNumber = 0;
    if (stepNumber < 0) stepNumber = 3;

    // Single-Phase Full Step Sequence
    if (stepNumber == 0)      { digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW); ... }
    else if (stepNumber == 1) { digitalWrite(IN1, LOW);  digitalWrite(IN2, HIGH); ... }
    // ... continues for steps 2 and 3
}
delayMicroseconds(delayValue); // Control rotational speed
```
## Explanation:
*    **Deadband:** A ```cpp int deadband = 30;``` 


##  Performance Data
The relationship between the analog input voltage and the motor output was verified as being linear.

## Youtube Link
https://youtube.com/shorts/EDRIIpdeKsc


