#include <eprom.h>

// запись строки data, начиная с адреса addr
bool write2Eeprom(int addr, String data)
{
    int len = data.length();
    EEPROM.write(addr, len);
    for (int i = 0; i < len; i++)
    {
        EEPROM.write(addr + 1 + i, data[i]);
    }
    bool result = EEPROM.commit();
    if (result)
    {
        Serial.println("EEPROM successfully committed");
    }
    else
    {
        Serial.println("ERROR! EEPROM commit failed");
    }
    return result;
}

// получение данных, начиная с addr
String readFromEeprom(int addr)
{
    String str;
    int len = EEPROM.read(addr);
    str.reserve(len);
    for (int i = 0; i < len; i++)
    {
        str += (char)EEPROM.read(addr + 1 + i);
    }
    return str;
}