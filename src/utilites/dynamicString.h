#ifndef DYNAMIC_DYNAMIC_STRING_H
#define DYNAMIC_DYNAMIC_STRING_H

typedef struct {
    char* string;
    long currentSize;
    long currentlyUsed;
}dynamicString;

dynamicString* generateString();
void addToString(dynamicString* string, char symbol);
void readToString(dynamicString* string);
void freeString(dynamicString* string);

#endif