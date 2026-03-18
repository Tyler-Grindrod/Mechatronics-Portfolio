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
