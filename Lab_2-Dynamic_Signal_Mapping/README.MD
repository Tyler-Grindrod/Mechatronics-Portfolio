# Lab 2: Joystick-Controlled Mechatronic System

## Overview
This project focused on using an **Arduino Uno R3** to process analog signals from a joystick and convert them into mechanical and electrical outputs.

## System Functionality
The system monitors three independent inputs from the joystick to control different actuators:
1.  **Throttle Control (X-axis):** Maps analog values ($0-1023$) to LED brightness using PWM ($0-255$).
2.  **Steering Control (Y-axis):** Maps analog values (0-1023) to a Micro Servo angle (0°→180°).
3.  **Buzzer Switch:** Pressing the joystick toggle activates an active Piezo buzzer.

## Hardware Stack
* **Controller:** Arduino Uno R3
* **Inputs:** 2-Axis Joystick (X: A0, Y: A1, SW: D2)
* **Outputs:** Micro Servo, Active Buzzer, red LED with 220 Ω resistor

## Logic Mapping
The core of this lab is the `map()` function, which linearizes the joystick's voltage input into usable ranges for the actuators

```cpp
// Mapping Joystick to Servo Angle
int servoAngle = map(yVal, 0, 1023, 0, 180);
myServo.write(servoAngle);

// Mapping Joystick to LED Intensity
int ledPWM = map(xVal, 0, 1023, 0, 255);
analogWrite(ledPin, ledPWM);

https://youtu.be/kf10Zy_-o3U
