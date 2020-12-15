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

void menuDelete(fakeBase *db){
    DynamicString* name = (DynamicString*)initString();
    printf("Введите имя\n");
    readToString(name);
    int searchResult = fakeLikeSearch(db, name->string);
    if (searchResult == -1){
        printf("Не удалось найти пользователя по указанным данным\n");
    }
    phoneUserLabel *label = db->elements[searchResult];
    fakeDelete(label, db);
    printf("Успешно удалено!\n");
    freeString(name);
}

void menuEditPhoneLabel(fakeBase* db){
    DynamicString* name = (DynamicString*)initString();
    printf("Введите имя\n");
    readToString(name);
    int searchResult = fakeLikeSearch(db, name->string);
    if (searchResult == -1){
        printf("Не удалось найти пользователя по указанным данным\n");
    }
    phoneUserLabel *label = db->elements[searchResult];
    DynamicString* newName = (DynamicString*)initString();
    DynamicString* newPhone = (DynamicString*)initString();
    printf("Введите новое имя и телефон\n");
    readToString(newName);
    readToString(newPhone);
    fakeEditPhoneLabel(db, label, newName->string, newPhone->string);
    freeString(newName);
    freeString(newPhone);
    freeString(name);
    printf("Успешно!\n");
}

void menuFile(fakeBase* db){
    printf("Дейстивя с файлом:\n 1.Загрузить базу из файла\n 2.Загрузить базу в файл\n");
    int userEnter, result;
    scanf("%d", &userEnter);
    DynamicString *filePath = initString();
    printf("Введите путь к файу:\n :::");
    readToString(filePath);
    switch (userEnter) {
        case 1:
            dumpBaseFromFile(db, filePath->string);
            printf("Успешно!\n");
            break;
        case 2:
            result = dumpBaseToFile(db, filePath->string);
            if (result == 0){
                printf("Произошла ошибка!\n");
            } else {
                printf("Успешно!\n");
                printf("Пока!\n");
                exit(0);
            }
            break;
    }
}

int main(){
    fakeBase *db;
    db = initializationFakeDataBase();
    for (;;) {
        int userEnter;
        printf("Выберете дейстиве:\n 1.Добавить номер\n 2.Вывести весь список\n 3.Удаление\n 4.Редактирование\n 5.Работа с файлом\n 10.Выйти\n Ваш выбор: ");
        scanf("%d", &userEnter);
        switch (userEnter) {
            case 1:
                menuAdd(db);
                break;
            case 2:
                menuPrintAll(db);
                break;
            case 3:
                menuDelete(db);
                break;
            case 4:
                menuEditPhoneLabel(db);
                break;
            case 5:
                menuFile(db);
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