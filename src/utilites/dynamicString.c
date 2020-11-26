#include "dynamicString.h"


dynamicString* generateString() {
    dynamicString* result =
        (dynamicString*)malloc(sizeof(dynamicString));
    result->currentSize = 16;
    result->currentlyUsed = 0;
    result->string = (char*)malloc(result->currentSize * sizeof(char));
    memset(result->string, '\0', result->currentSize * sizeof(char));

    return result;
}


void addToString(dynamicString* string, char symbol) {
    if (string->currentlyUsed > string->currentSize) {
        string->currentSize += 16;
        string->string =
            (char*)realloc(string->string, string->currentSize * sizeof(char));
        memset(&(string->string[string->currentlyUsed]), '\0', sizeof(char) * (string->currentSize - string->currentlyUsed));
    }

    string->string[string->currentlyUsed] = symbol;
    ++string->currentlyUsed;
}

void readToString(dynamicString* string) {
    char newSymbol;
    scanf("%c", &newSymbol);

    while (newSymbol != '\n') {
        addToString(string, newSymbol);
        scanf("%c", &newSymbol);
    }
}

void freeString(dynamicString* string) {
    free(string->string);
    free(string);
}