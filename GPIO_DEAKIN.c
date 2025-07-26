#include "GPIO_DEAKIN.h"

void Config_GPIO(char PortNum, char PinNum, bool Mode) {
    uint32_t MASK = (1 << PinNum);  // Single-bit mask for selected pin
    uint32_t TEMP;

    if (Mode == OUTPUT) {
        TEMP = PORT->Group[PortNum].DIR.reg;   // Read direction register
        TEMP |= MASK;                          // Set the pin as output
        PORT->Group[PortNum].DIR.reg = TEMP;   // Write back
    } else {
        TEMP = PORT->Group[PortNum].DIR.reg;
        TEMP &= ~MASK;                         // Clear bit to make pin input
        PORT->Group[PortNum].DIR.reg = TEMP;
    }
}

void Write_GPIO(char PortNum, char PinNum, bool State) {
    uint32_t MASK = (1 << PinNum);
    uint32_t TEMP;

    TEMP = PORT->Group[PortNum].OUT.reg;

    if (State == HIGH) {
        TEMP |= MASK;  // Set pin high
    } else {
        TEMP &= ~MASK; // Set pin low
    }

    PORT->Group[PortNum].OUT.reg = TEMP;
}

bool Read_GPIO(char PortNum, char PinNum) {
    if (PortNum > 1 || PinNum > 31) return false;
    uint32_t MASK = (1 << PinNum);
    uint32_t TEMP = PORT->Group[PortNum].IN.reg;

    return (TEMP & MASK) ? HIGH : LOW;
}
