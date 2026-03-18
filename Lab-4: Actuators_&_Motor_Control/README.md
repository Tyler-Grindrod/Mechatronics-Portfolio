#  Lab 4: DC and Stepper Motor Control

##  Overview
This lab focused on interfacing an **Arduino Uno R3** with high-current actuators.

## System Functionality
* **Polaritity Switching:** `gate1` and `gate2` control the H-bridge gates to flip the voltage across the motor
* **Linear Mapping:** Using `abs(Value)` ensure the motor spins gaster as the potentiometer moves further away from the center in either direction. 

###  1. Bidirectional DC Motor Control
Using a Potentiometer, the motor speed is controlled via Pulse Width Modulation (PWM).
*  **Center Position:** Motor is off (0 PWM)
*  **Full Left/Right:** Motor Reaches maximum speed (255 PWM)
*  **Hardware:** L293D/L298N H-Bridge for polarity switching

` // Logic for Direction and Speed
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
analogWrite(en12, speed);      // Send PWM signal to H-Bridge `




###  2. Stepper Motor Control
The stepper motor was programmed with a custom stepping sequence to manage psotion and speed. 
*  **Speed Control:** The potentiometer adjusts the `delayMicroseconds()` between steps
*  **Deadband:** A "ddeadzone" was implemented at the potentiometer's center to prevent unintended movement.

##  Performance Data
The relationship between the analog input voltage and the motor output was verified as being linear.

## Youtube Link
https://youtube.com/shorts/EDRIIpdeKsc


