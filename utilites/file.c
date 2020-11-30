#include "file.h"
#include "dynamicString.h"


const char *FILE_NAME = "phone_book.txt"; // Глобальная переменная, обозначающая название файла

// Запись данных в файл
int fileDump(const char fileInfo){
    FILE *file;
    file = fopen(FILE_NAME, "w"); 
    // Проверка удалось ли открыть файл если нет то возваращем 0
    if (!file){
        return 0;
    }
    fprintf(file, "%s ", fileInfo);
    fflush(file);
    fclose(file);
    return 1;
}


//// Считывание данных с файла
//DynamicString* fileRead(){
//    FILE *file;
//    DynamicString *dump = generateString();
//    file = fopen(FILE_NAME, "r");
//    if (!file){
//        fclose(file);
//        return dump;
//    }
//    char buf = fgetc(file);
//    while(buf != EOF){
//        addToString(dump, buf);
//    }
//    fclose(file);
//    return dump;
//}