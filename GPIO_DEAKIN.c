#include "GPIO_DEAKIN.h"

void Config_GPIO(char PortNum, char PinNum, bool Mode) {
    uint32_t MASK = (1 << PinNum);  // Single-bit MASK for selected pin
    uint32_t TEMP;

    if (Mode == OUTPUT) {
        TEMP = PORT->Group[PortNum].DIR.reg;   // Get the current values of DIR register
        TEMP |= MASK;                          // Set the pin as output, using OR operator
        PORT->Group[PortNum].DIR.reg = TEMP;   // Write back
    } else {
        TEMP = PORT->Group[PortNum].DIR.reg;
        TEMP &= ~MASK;                         // Clear bit to make pin input, using AND with a not MASK
        PORT->Group[PortNum].DIR.reg = TEMP;   // Write back
    }
}

void Write_GPIO(char PortNum, char PinNum, bool State) {
    uint32_t MASK = (1 << PinNum); // Single-bit MASK for selected pin
    uint32_t TEMP;

    TEMP = PORT->Group[PortNum].OUT.reg;    // Get the current values of OUT register

    if (State == HIGH) {
        TEMP |= MASK;                      // Set pin high
    } else {
        TEMP &= ~MASK;                     // Set pin low
    }

    PORT->Group[PortNum].OUT.reg = TEMP;
}

bool Read_GPIO(char PortNum, char PinNum) {
    if (PortNum > 1 || PinNum > 31) return false;    // Cross-verify whether the pin number of port number exceeds the expected value.
    uint32_t MASK = (1 << PinNum);
    uint32_t TEMP = PORT->Group[PortNum].IN.reg;    // Get the current values of IN register

    return (TEMP & MASK) ? HIGH : LOW;              // Using AND operator to read the value of the specified pin.
}
