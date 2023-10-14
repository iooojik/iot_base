#include <serializer.h>

char* serialize(StaticJsonDocument doc){
    int len1 = measureJson(doc);
    char output[len1];
    serializeJson(doc, output, sizeof(output));
    return output;
}