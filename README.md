# Lab Work #2: PWM Control via Keypad (STM32)

This project is the implementation of Laboratory Work #2 for the "Radio Control Systems" course.

## 🎯 Objective

The project demonstrates reading data from a 4x4 matrix keypad to control two independent PWM (Pulse Width Modulation) channels on an **STM32F103C8T6** microcontroller. The results (key pressed, PWM percentage, pulse width) are displayed on an OLED screen.

## ⚙️ Hardware Components

* **Microcontroller:** STM32F103C8T6 ("Blue Pill")
* **Keypad:** 4x4 Membrane Keypad
* **Display:** OLED 128x64 (SSD1306) via I2C
* **Actuators:** Servo motor (e.g., SG90) or any other PWM-controlled device.
* **Programmer:** ST-Link V2

## 🚀 Key Code Features

* **Non-Blocking Keypad Driver:** Uses a combination of external interrupts (`EXTI`) and a timer (`TIM2`) to implement reliable **debouncing**.
* **State Machine:** The keypad polling logic is implemented as a state machine (`KEY_STATE_IDLE`, `KEY_STATE_DEBOUNCING_PRESS`, etc.) to handle key presses and releases without using `HAL_Delay()`.
* **Hardware PWM:** Utilizes `TIM3` and `TIM4` timers to generate two independent PWM signals at 50 Hz.
* **I2C & OLED:** Uses the `ssd1306` library to output text information to the display.
* **Modularity:** The code is divided into logical modules (keypad, app_logic, screen_ui).

## 🛠️ Development Environment

This project was created and is compiled in **STM32CubeIDE**.
