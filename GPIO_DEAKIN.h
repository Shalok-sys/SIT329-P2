// GPIO_DEAKIN.h
#ifndef GPIO_DEAKIN_H
#define GPIO_DEAKIN_H

#ifdef __cplusplus
extern "C" { // ensures that the module naming of GPIO_DEAKIN.C is implemented in terms of .cpp files. 
#endif

#include <stdbool.h>
#include <stdint.h>
#include "sam.h"

// Defines constant variables, that allow similar usage to Arduino API

#define INPUT  0
#define OUTPUT 1
#define LOW    0
#define HIGH   1
#define PORT_A 0
#define PORT_B 1

void Config_GPIO(char PortNum, char PinNum, bool Mode);
void Write_GPIO(char PortNum, char PinNum, bool State);
bool Read_GPIO(char PortNum, char PinNum);

#ifdef __cplusplus
}
#endif

#endif
