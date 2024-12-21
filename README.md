# Interupts
Interrupts, Timers, and more!
# Dual Interrupt LED Control Project

---

## Project Overview
This project demonstrates the use of AVR interrupts to control two LEDs:
1. **LED 1**: Controlled by an external interrupt triggered by a button press.
2. **LED 2**: Blinks at 1-second intervals using a timer interrupt.

The project is coded in **C++** for compatibility with various IDEs, such as **Visual Studio 2022**, **Atmel Microchip Studio**, and **Arduino IDE**.

---

## Hardware Components
- **Microcontroller**: Arduino Uno (ATmega328P)
- **LEDs**:
  - **LED 1**: Button-controlled, connected to `PD3`.
  - **LED 2**: Timer-controlled, connected to `PD2`.
- **Button**: Normally Open (NO), connected to `PD3`.
- **Resistors**:
  - **220Ω**: Connected to each LED for current limiting.
  - **10kΩ**: Pull-down resistor for the button (if needed).

---

## Hardware Setup

### **LED 1 Circuit**
- `5V → 220Ω resistor → LED → Button → GND`.

### **LED 2 Circuit**
- `PD2 → 220Ω resistor → LED → GND`.

### **Button Circuit**
- **NO button**: Connect one terminal to `GND` and the other to `PD3`.
- Optional: Add a 10kΩ pull-down resistor between `PD3` and `GND` for stability.

---

## Software Features
1. **Timer Interrupt**:
   - Configures **Timer1** in CTC mode.
   - Toggles LED 2 every 1 second using `TIMER1_COMPA_vect`.

2. **External Interrupt**:
   - Configures **INT0** (connected to the button on `PD3`).
   - Toggles the state of LED 1 (ON/OFF) when the button is pressed.

3. **C++ Modular Design**:
   - Functions for initialization and ISR logic.
   - Compatible with **standard C++ IDEs** for flexibility.

---

## Code Summary

### **Initialization**
- **Timer1**: Configured for a 1-second interrupt using a 1024 prescaler.
- **INT0**: Configured to trigger on a falling edge (button press).

### **Main Loop**
- Continuously monitors the button state for LED 1.
- Timer interrupt toggles LED 2 ON/OFF.

### **Interrupt Service Routines**
- `TIMER1_COMPA_vect`: Toggles LED 2 every 1 second.
- `INT0_vect`: Toggles the `button_state` to control LED 1.

---

## How to Use
1. **Compile and Upload**:
   - Open the project in your preferred IDE.
   - Compile the code and upload it to your microcontroller.

2. **Run the Project**:
   - Press the button to toggle LED 1 ON/OFF.
   - Observe LED 2 blinking with a 1-second ON/OFF cycle.

---

## AVR Programming Elements
This project incorporates the following AVR programming elements:
1. **Interrupts**:
   - Timer interrupt for LED 2 blinking.
   - External interrupt for button-controlled LED 1.

2. **Port Manipulation**:
   - Direct control of LED pins using `PORTD` registers.

3. **Timers**:
   - Timer1 configured in CTC mode for precise timing.

---

## Troubleshooting
- **LED 1 Not Responding**:
  - Verify the button wiring and ensure the pull-down resistor is in place.
  - Check the `PD3` pin connection.

- **LED 2 Not Blinking**:
  - Ensure Timer1 is configured correctly.
  - Verify the `PD2` pin connection.

---

## Future Improvements
1. Add debounce logic for the button press.
2. Use PWM to control LED brightness.
3. Integrate additional sensors or outputs for extended functionality.

---

## Credits
Developed by Michael Garcia. This project is a demonstration of AVR programming principles for interrupt-driven applications.
