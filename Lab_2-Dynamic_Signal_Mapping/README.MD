# Lab 2: Joystick-Controlled Mechatronic System

## Overview
This project focused on using an **Arduino Uno R3** to process analog signals from a joystick and convert them into mechanical and electrical outputs.

## System Functionality
The system monitors three independent inputs from the joystick to control different actuators:
1.  **Throttle Control (X-axis):** Maps analog values ($0→1023$) to LED brightness using PWM ($0→255$).
2.  **Steering Control (Y-axis):** Maps analog values ($0→1023$) to a Micro Servo angle ($0°→180°$).
3.  **Buzzer Switch:** Pressing the joystick toggle activates an active Piezo buzzer.

## Hardware
* **Controller:** Arduino Uno R3
* **Inputs:** 2-Axis Joystick (X: A0, Y: A1, SW: D2)
* **Outputs:** Micro Servo, Active Buzzer, red LED with 220 Ω resistor

## Logic Mapping
The core of this lab is the `map()` function, which linearizes the joystick's voltage input into usable ranges for the actuators

## Youtube Link: 
https://youtu.be/kf10Zy_-o3U

```cpp
// Mapping Joystick to Servo Angle
int servoAngle = map(yVal, 0, 1023, 0, 180);
myServo.write(servoAngle);

// Mapping Joystick to LED Intensity
int ledPWM = map(xVal, 0, 1023, 0, 255);
analogWrite(ledPin, ledPWM);
```

* **10-bit Input:** The Arduino `analogRead()` function returns a value between **0 and 1023**
* **8-bit Output:** The `analogWrite()` function for the LED requires a value between **0 and 255**
* **Servo Range:** The `myServo.write()` function expects an angle between **0 and 180**

## Technical Challenges and Lessons Learned
1. **Signal Stability & Jitters**
During the initial testing, the servo motor exhibited "chatter", known as micro-oscillations when the joystick was at the point of origin.
* **The Fix:** I implemented a `delay(10);` at the end of the `loop()` to provide a stability window for the Analog-to-Digital Converter (ADC).
* **Future Improvement:** In a robust application, I would implement a **Deadband** to eliminate the jitter without increasing the loop speed.

2. **Power Management**
The system drives an LED, Servo, and an active Buzzer simultaneously.
* **Observation:** If the Servo draws too much power, the LED would dim.
* **Future Improvement:** Whiel the USB power from the laptop is sufficient, an integrated power supply module would ensure consistent performance from the Servo motor. 
