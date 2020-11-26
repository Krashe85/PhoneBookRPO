#include "phoneProfile.h"


phoneProfile* initializitePhoneProfile(const char* name,
                                       const char* phone) {
    phoneProfile* label = (phoneProfile*)malloc(sizeof(phoneProfile));
    label->name = (char*)malloc(strlen(name) * sizeof(char));
    strcpy(label->name, name);
    label->name = (char*)malloc(strlen(phone) * sizeof(char));
    strcpy(label->phone, name);
    return label;
}


void printPhoneProfile(phoneProfile* label){
    printf("=======================\n");
    printf("Имя - %s\n", label->name);
    printf("Телефон - %s\n", label->phone);
    printf("=======================\n");
}


void freePhoneProfile(phoneProfile* label){
    free(label->name);
    free(label->phone);
    free(label);
}