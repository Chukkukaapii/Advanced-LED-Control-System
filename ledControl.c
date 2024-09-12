#include <stdio.h>
#include <stdint.h>

// Structure representing individual LED settings
typedef struct {
    uint8_t state;       // LED ON/OFF state: 1 = ON, 0 = OFF
    uint8_t brightness;  // LED Brightness level (0 - 255)
    uint32_t color;      // RGB color (24-bit encoded)
} LEDSettings;

// Structure representing a group of LEDs and their settings
typedef struct {
    LEDSettings singleLED;  // Individual LED settings
    uint8_t groupState;     // Group state: 1 = All ON, 0 = All OFF
    uint8_t groupBrightness;// Group brightness (0 - 255)
} LEDGroup;

// Function to initialize the LED group with default values
void initLEDGroup(LEDGroup *group) {
    group->singleLED.state = 0;              // All LEDs OFF
    group->singleLED.brightness = 0;         // Minimum brightness
    group->singleLED.color = 0x000000;       // Default color (Black - RGB 0,0,0)
    
    group->groupState = 0;                   // Group OFF
    group->groupBrightness = 0;              // Minimum group brightness
}

// Function to update both individual LED and group settings
void updateLEDGroupSettings(LEDGroup *group, uint8_t groupState, uint8_t groupBrightness, uint8_t state, uint8_t brightness, uint32_t color) {
    // Update group settings
    group->groupState = groupState;
    group->groupBrightness = groupBrightness;

    // Update individual LED settings
    group->singleLED.state = state;
    group->singleLED.brightness = brightness;
    group->singleLED.color = color;
}

// Function to display the current status of the LED group
void displayLEDGroupStatus(const LEDGroup *group) {
    printf("=== LED Group Status ===\n");
    printf("Group State: %s\n", group->groupState ? "ON" : "OFF");
    printf("Group Brightness: %u\n", group->groupBrightness);
    
    printf("\n--- Individual LED Settings ---\n");
    printf("LED State: %s\n", group->singleLED.state ? "ON" : "OFF");
    printf("LED Brightness: %u\n", group->singleLED.brightness);
    printf("LED Color (RGB): #%06X\n", group->singleLED.color);
}

int main() {
    // Create an LED group
    LEDGroup ledGroup;

    // Initialize the LED group with default values
    initLEDGroup(&ledGroup);

    // Display initial status
    displayLEDGroupStatus(&ledGroup);

    // Update the LED group with new settings
    updateLEDGroupSettings(&ledGroup, 1, 128, 1, 200, 0xFF5733);  // Group ON, Group Brightness 128, LED ON, Brightness 200, Color Orange
    
    // Display updated status
    displayLEDGroupStatus(&ledGroup);

    return 0;
}
