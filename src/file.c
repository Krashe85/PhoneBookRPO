#include "file.h"


FILE_NAME = "phone_book.txt"; // Глобальная переменная, обозначающая название файла

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


// Считывание данных с файла
char* fileRead(){
    FILE *file;
    char *dump;
    file = fopen(FILE_NAME, "r"); 


}