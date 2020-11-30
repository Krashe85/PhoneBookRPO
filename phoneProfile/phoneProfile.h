#ifndef DYNAMIC_PHONE_PROFILE_H
#define DYNAMIC_PHONE_PROFILE_H

#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct phoneUserLabel{
    char* name;
    char* phone;
}phoneUserLabel;

void printPhoneProfile(phoneUserLabel* label);
void freePhoneProfile(phoneUserLabel* label);
char *formatToFile(phoneUserLabel* label);
phoneUserLabel* buildPhoneProfile(const char* name,
                                       const char* phone);

#endif