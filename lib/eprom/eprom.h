#include <Arduino.h>
#include <EEPROM.h>

// получение данных, начиная с addr
String readFromEeprom(int addr);

// запись строки data, начиная с адреса addr
bool write2Eeprom(int addr, String data);