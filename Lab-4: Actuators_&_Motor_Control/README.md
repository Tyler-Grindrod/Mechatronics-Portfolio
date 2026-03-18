#  Lab 4: DC and Stepper Motor Control

##  Overview
This lab focused on interfacing an **Arduino Uno R3** with high-current actuators.

## System Functionality

###  1. Bidirectional DC Motor Control
Using a Potentiometer, the motor speed is controlled via Pulse Width Modulation (PWM).
*  **Center Position:** Motor is off (0 PWM)
*  **Full Left/Right:** Motor Reaches maximum speed (255 PWM)
*  **Hardware:** L293D/L298N H-Bridge for polarity switching



###  2. Stepper Motor Control
The stepper motor was programmed with a custom stepping sequence to manage psotion and speed. 
*  **Speed Control:** The potentiometer adjusts the `delayMicroseconds()` between steps
*  **Deadband:** A "ddeadzone" was implemented at the potentiometer's center to prevent unintended movement.

##  Performance Data
The relationship between the analog input voltage and the motor output was verified as being linear.

## Youtube Link
https://youtube.com/shorts/EDRIIpdeKsc


