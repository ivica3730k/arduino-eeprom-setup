#include "effiicentEEPROM.h"

#include <Arduino.h>
#include <EEPROM.h>


void writeEEPROM(uint16_t start_address, char *data, uint16_t data_length)
{
    
    for (int i = 0; i < data_length; i++)
    {
        if (data[i] != EEPROM.read(i + start_address))
        {
            EEPROM.write(i + start_address, data[i]);
        }
    }
}

void readEEPROM(uint16_t start_address, char *data, uint16_t data_length)
{
    for (int i = 0; i < data_length;i++)
    {
        data[i] = EEPROM.read(i + start_address);
    }
}