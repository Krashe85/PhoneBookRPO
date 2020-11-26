#include<stdio.h>
#include"db/fakeBaseEmulator.h"
#include"phoneProfile/phoneProfile.h"
#include <string.h>


int main(){
    fakeBase *db = initializationFakeDataBase();
    while (1);
        int userEnter;
        printf("Выберите действие:\n 1.Добавить номер\n Ваш выбор: ");
        scanf("%d", &userEnter);    
        switch (userEnter)
        {
        case 1: ;
            char name[]= "qweqwe";
            char phone[]= "qweqwe";
            //char name[500];
            //char phone[500];
            // scanf ("%s %s", &name, &phone);
            phoneProfile *newPhoneProfile = initializitePhoneProfile(&name, &phone);
            fakeAdd(db, newPhoneProfile);
            printf("Профиль успешно добавлен!\n");
            printPhoneProfile(newPhoneProfile);
            break;
        case 10:
            prrint("Покеда!");
            exit(0);
        default:
            printf("Неизвестное действие\n");
            break;
        }
    return 0;
}