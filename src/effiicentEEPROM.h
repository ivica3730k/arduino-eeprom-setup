#include <Arduino.h>
#include <EEPROM.h>

void writeEEPROM(uint16_t start_address, char *data, uint16_t data_length);
void readEEPROM(uint16_t start_address, char *data, uint16_t data_length);