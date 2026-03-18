# Lab 3: Fundamental Analog Electronics

## Overview
This lab involved the simulation and analysis of analog circuits using **TinkerCAD**.

## Circuit Implementation

### 1. Temperature Circuit
Designed a cirtcuit using an **LM393** and a **TMP36** temperature sensor toa cuate an LED based on a specific limit.
*  **Objective:** Calculate the resistor Value ($R_2$) requried for the LED to turn off at **100°C**
*  **Component Used:** LM393 Dual Comparator

### 2. Inductor Time Constant Circuit
Analyzed the behavuior of an inductor in a DC circuit with a flyback diode.
*  **Objective:** Determined the inductance ($L$) needed for a **5-second time constance** with a $1kΩ$ resistor
*  **Lesson:** I found the inductor initially acts as an open circuit ($0mA$) and behaves like a short circuit as current stablizes. I also learned that the flyback diode is a critical component that disspates the magnetic field when the switch opens, this prevent high-voltage spikes on the board.

### 3. Op-Amp Signal Processing
Implemented an Addition and Subtraction (Differential) circuits using an Op-Amp driven by ($+/-30V$)
* **Addition:** Calculated and verified the inverted output for various feedback resistor $RF$ values
* **Subtraction:** Analyzed a differential amplifier to remain within the power supply rails
* **Saturation Analysis:** Identitied that an $RF$ of $25KΩ$ in the adder circuit clipping at $-30V$

## TinkerCad Link
* **All Circuit Designs:** https://www.tinkercad.com/things/3pIT7zE8izT-lab3/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fcircuits&sharecode=Ng7uSgi3bW6zNBbpckOPGm0xddNo-MY_saK6v8q4XhA

