#ifndef DYNAMIC_FBE_H
#define DYNAMIC_FBE_H


#include"../phoneProfile/phoneProfile.h"

typedef struct{
    phoneProfile **elements;
    int size;
}fakeBase;
fakeBase *initializationFakeDataBase();
void fakeAdd(fakeBase *base, const phoneProfile* label);
int fakeSearchProfileId(fakeBase *base, const phoneProfile *label);
int fakeDelete(fakeBase *base, const phoneProfile* label);

#endif