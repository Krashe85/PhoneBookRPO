#ifndef DYNAMIC_PHONE_PROFILE_H
#define DYNAMIC_PHONE_PROFILE_H

#include<string.h>
#include<stdio.h>

typedef struct {
    char* name;
    char* phone;
}phoneProfile;

void printPhoneProfile(phoneProfile* label);
void freePhoneProfile(phoneProfile* label);

#endif