#ifndef DYNAMIC_FBE_H
#define DYNAMIC_FBE_H


#include "../phoneProfile/phoneProfile.h"
#include "../utilites/dynamicString.h"

typedef struct fakeBase{
    phoneUserLabel **elements;
    int size;
}fakeBase;
fakeBase *initializationFakeDataBase();
void fakeAdd(fakeBase *base, phoneUserLabel* label);
int fakeSearchProfileId(fakeBase *base, const phoneUserLabel *label);
void fakeDelete(phoneUserLabel* label, fakeBase* db);
int fakeLikeSearch(fakeBase *base, char * name);
void fakeEditPhoneLabel(fakeBase* db, phoneUserLabel* label,
                        const char* newName, const char* newPhone);
int dumpBaseToFile(fakeBase* db, const char* path);
fakeBase *dumpBaseFromFile(fakeBase* db, const char* path);


#endif