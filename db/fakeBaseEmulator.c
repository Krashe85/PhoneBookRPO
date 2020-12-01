#include "fakeBaseEmulator.h"
#include <string.h>

fakeBase *initializationFakeDataBase(){
    fakeBase *base = (fakeBase*)malloc(sizeof(fakeBase));
    base->elements = (phoneUserLabel**)malloc(sizeof(phoneUserLabel*));
    base->size = 0;
    return base;
}

void fakeSort(fakeBase* array) {
    for (unsigned long i = 0; i < array->size; i++) {
        for (unsigned long j = i + 1; j < array->size; j++) {
            if (strcmp(array->elements[i]->name, array->elements[j]->name) > 0) {
                phoneUserLabel* temp = array->elements[j];
                array->elements[j] = array->elements[i];
                array->elements[i] = temp;
            }
        }
    }
}

void fakeDelete(phoneUserLabel* label, fakeBase* db) {
    int labelID = fakeSearchProfileId(db, label);
    freePhoneProfile(label);
    db->elements[labelID] = NULL;

    for (unsigned long i = labelID; i < db->size; i++) {
        db->elements[i] = db->elements[i + 1];
    }
    db->size = db->size - 1;
    fakeSort(db);
}

void fakeAdd(fakeBase *base, phoneUserLabel* label){
    int searchResult = fakeSearchProfileId(base, label);
    if (searchResult > -1){
        return;
    }
    int currentSize = base->size;
    base->elements = (phoneUserLabel**)realloc(base->elements, sizeof(phoneUserLabel*)*(currentSize+1));
    base->elements[currentSize] = label;
    base->size = ++currentSize;
    fakeSort(base);
}

int fakeSearchProfileId(fakeBase *base, const phoneUserLabel *label){
    // при наождение похожего профиля возвращает 1, иначе -1
    for (int element=0; element < base->size; ++element){
        phoneUserLabel *currentProfile = base->elements[element];
        if (strcmp(currentProfile->phone, label->phone) == 0 && strcmp(currentProfile->name, label->name) == 0){
            return element;
        }
    }
    return -1;
}

int fakeLikeSearch(fakeBase *base, char * name){
    // при наождение похожего профиля возвращает 1, иначе -1
    for (int element=0; element < base->size; ++element){
        phoneUserLabel *currentProfile = base->elements[element];
        if (strcmp(currentProfile->name, name) == 0){
            return element;
        }
    }
    return -1;
}

void fakeEditPhoneLabel(fakeBase* db, phoneUserLabel* label,
                        const char* newName, const char* newPhone){
    free(label->phone);
    free(label->name);
    label->name = (char*)malloc(strlen(newName) * sizeof(char));
    label->phone = (char*)malloc(strlen(newPhone) * sizeof(char));
    for (int i = 0; i < strlen(newName); ++i) {
        label->name[i] = newName[i];
    }
    for (int i = 0; i < strlen(newPhone); i++) {
        label->phone[i] = newPhone[i];
    }
}