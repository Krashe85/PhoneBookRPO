#include <stdio.h>
#include <stdlib.h>
#include"db/fakeBaseEmulator.h"
#include"phoneProfile/phoneProfile.h"
#include "utilites/dynamicString.h"


void menuAdd(fakeBase *db){
    DynamicString* name = (DynamicString*)initString();
    DynamicString* phone = (DynamicString*)initString();
    printf("Введите имя и телефон\n");
    readToString(name);
    readToString(phone);
    phoneUserLabel *userPhone = buildPhoneProfile(name->string, phone->string);
    fakeAdd(db, userPhone);
    printPhoneProfile(userPhone);
    printf("Успешно!\n");
    freeString(name);
    freeString(phone);
}

void menuPrintAll(struct fakeBase *db){
    for (int i = 0; i < db->size; ++i){
        printPhoneProfile(db->elements[i]);
    }
}


int main(){
    fakeBase *db;
    db = initializationFakeDataBase();
    for (;;) {
        int userEnter;
        printf("Выберете дейстиве:\n 1.Добавить номер\n 2.Вывести весь список\n 10.Выйти\n Ваш выбор: ");
        scanf("%d", &userEnter);
        switch (userEnter) {
            case 1:
                menuAdd(db);
                break;
            case 2:
                menuPrintAll(db);
                break;
            case 10:
                printf("Пока!\n");
                exit(0);
            default:
                printf("Неизвестное действие\n");
                break;
        }

    }
    return 0;
}