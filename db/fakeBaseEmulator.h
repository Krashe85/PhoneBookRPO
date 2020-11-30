#ifndef DYNAMIC_FBE_H
#define DYNAMIC_FBE_H


#include"../phoneProfile/phoneProfile.h"

typedef struct fakeBase{
    phoneUserLabel **elements;
    int size;
}fakeBase;
fakeBase *initializationFakeDataBase();
void fakeAdd(fakeBase *base, phoneUserLabel* label);
int fakeSearchProfileId(fakeBase *base, const phoneUserLabel *label);
void fakeDelete(phoneUserLabel* label, fakeBase* db);

#endif