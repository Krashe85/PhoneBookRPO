#include"fakeBaseEmulator.h"

fakeBase *initializationFakeDataBase(){
    fakeBase *base = (fakeBase*)malloc(sizeof(fakeBase));
    base->elements = (phoneProfile**)malloc(sizeof(phoneProfile*));
    base->size = 1;
    return base;
}

void fakeAdd(fakeBase *base, const phoneProfile* label){
    int searchResult = fakeSearchProfileId(base, label);
    if (searchResult > -1){
        phoneProfile *oldProfile = base->elements[searchResult];
        freePhoneProfile(oldProfile);
        base->elements[searchResult] = label;
        return NULL;
    }
    int currentSize = base->size;
    base->elements = (phoneProfile**)realloc(base->elements, sizeof(phoneProfile*)*(++currentSize));
    base->elements[currentSize] = label;
    base->size = ++currentSize;
}

int fakeSearchProfileId(fakeBase *base, const phoneProfile *label){
    // при наождение похожего профиля возвращает 1, иначе 0
    for (int element=0; element < base->size; ++element){
        phoneProfile *currentProfile = base->elements[element];
        if (currentProfile->phone == label->phone || currentProfile->name == label->name){
            return element;
        }
    }
    return -1;
}

int fakeDelete(fakeBase *base, const phoneProfile* label){
    int searchResult = fakeSearchProfileId(base, label);
    if (searchResult == -1){
        return 0;
    }
    phoneProfile* deleteProfile = base->elements[searchResult];
    freePhoneProfile(deleteProfile);
    return 1;   
}

