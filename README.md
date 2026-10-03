# Inverted Pendulum Control System

## Overview

This project presents the development of a physical inverted pendulum system along with simulation and control analysis.

The physical prototype consists of a three-wheel cart with two motor-driven wheels and a front caster wheel, carrying a vertical pendulum. The system was developed to study the dynamics and control of an inherently unstable inverted pendulum.

A simulation was also developed to analyse the system behaviour and study swing-up and stabilisation using control techniques.

## Physical Prototype

The physical system was built using an Arduino UNO, DC gear motors, an MPU6050 accelerometer and gyroscope, an L298N motor driver, a battery supply, and a pendulum mechanism.

The cart uses two driven wheels for movement and a front caster wheel for support.

### Hardware

- Arduino UNO
- 2 DC gear motors
- 2 motor-driven wheels
- 1 front caster wheel
- MPU6050 accelerometer and gyroscope
- L298N motor driver
- 12 V battery supply
- Pendulum rod
- Pivot and bearing mechanism
- Base/chassis
- Breadboard and jumper wires

[View Hardware Components](./Hardware/Components.md)

## Control Approach

The project uses feedback-based control to stabilise the inverted pendulum.

The simulation described in the project report uses:

1. **Energy-Based Swing-Up Control**  
   The cart is moved strategically to provide the pendulum with sufficient energy to move from the downward position toward the upright position.

2. **LQR Stabilisation**  
   Once the pendulum approaches the upright position, Linear Quadratic Regulator (LQR) control is used to maintain the pendulum near the upright position.

## Simulation

The system was modelled and simulated to study:

- Cart position
- Cart velocity
- Pendulum angle
- Pendulum angular velocity
- Control force

The simulation results demonstrate the swing-up and subsequent stabilisation of the pendulum.

## Results

The project demonstrated successful pendulum rotation and stabilisation. The simulated system settles near the upright position, while the cart position, velocity, angular velocity, and control force settle toward their steady-state values.

## Physical Prototype Demonstration

A working video of the physical inverted pendulum prototype is available in the `Hardware` folder.

[View the working video](./Hardware/Inverted_pendulum_video.mp4)

## Project Report

The complete project report is available here:

[View Project Report](./Inverted_Pendulum_Project_Report.pdf)

## Team Members

- Agrima Goel
- Neha Evane
- Sweta Maurya
- Tanvi Sharma
