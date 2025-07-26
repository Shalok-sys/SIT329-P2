#include "GPIO_DEAKIN.h"

void setup() {
    Config_GPIO(PORT_A, 17, OUTPUT); // PA17 is LED pin 13, which is an in-built LED.
}

void loop() {
    Write_GPIO(PORT_A, 17, HIGH);
    delay(1000);
    Write_GPIO(PORT_A, 17, LOW);
    delay(1000);
}
