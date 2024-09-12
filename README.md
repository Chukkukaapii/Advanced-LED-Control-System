# Advanced LED Control System for Microcontroller

## Objective
The following C program simulates an advanced LED control system on a microcontroller. This program includes almost all the major control aspects of LEDs through nested structures to handle state, brightness, and color, along with group settings about LEDs.

## Structure Definitions

- **LEDSettings**: Represents individual LED settings.
  - `state`: 1 for ON, 0 for OFF.
  - `brightness`: LED brightness level (0-255).
  - `color`: RGB color value stored in 32-bit format.

- **LEDGroup**: Represents a group of LEDs and their collective settings.
  - `singleLED`: Holds the individual LED settings using the `LEDSettings` structure.
  - `groupState`: Controls the ON/OFF state for the entire group.
  - `groupBrightness`: Adjusts the brightness for the entire group.

## Functions
- **initLEDGroup(LEDGroup *group)**: Initializes the LED group with default settings (all LEDs OFF, minimum brightness, and no color).
- **updateLEDGroupSettings(LEDGroup *group, uint8_t groupState, uint8_t groupBrightness, uint8_t state, uint8_t brightness, uint32_t color)**: Updates both individual LED settings and group settings based on function arguments.
- **displayLEDGroupStatus(const LEDGroup *group)**: Displays the current status of the individual LED/group settings.

## How to Compile and Run the Program
- To compile the program on Linux/Windows using GCC:
  ```bash
  gcc -o led_control led_control.c
  ./led_control    # Linux/Unix
  led_control.exe  # Windows

## Embedded Development Environment Specifics

### 1. Toolchain and IDE Setup

- **Toolchain**: You will need an embedded toolchain compatible with your microcontroller (example: ESP-IDF for ESP32).

  Ensure that the toolchain is correctly installed and configured with the selected IDE.

### 2. Microcontroller Setup

- **Target Microcontroller**: Specify the microcontroller 

  
  Ensure that you have the correct pin configuration in your code, this is very  important.

### 3. Flashing the Program

- **Flashing Tools**:Depending on the microcontroller, you will use flashing tools to upload a binary/hex file to the device. For example:
  - **ESP32**: Use `esptool.py` for flashing the binary.
 (or utilise the IDE you have chosen)
