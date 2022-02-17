#include "headers/reader.h"

void analyseBuffer(novel_field *f, char* buffer);
void getType(int*, char* );
void getValue(char*, char* );

void readFile(novel_field *f){
    FILE *file;
    char datafile[40+1];
    while(true){
        strcpy(datafile, "");
        printf("\nPlease enter the name of the File you want to read from Format(name.txt): ");
        fflush(stdin);
        while(datafile[0] == 0){
            gets(datafile);
        }
        fflush(stdin);
        file = fopen(datafile,"r");
        if(!file || !strstr(datafile, ".txt")){
            printf("\nFile is not right\n");
        } else break;
    }
    file = fopen(datafile,"r");
    char buffer[250+1];
    strcpy(buffer,"");
    while(!feof(file)){
        fgets(buffer, 250, file);
        buffer[strcspn(buffer, "\n")] = 0;
        decrypt(buffer);
        analyseBuffer(f, buffer);
    }
    fclose(file);
}

void analyseBuffer(novel_field *f, char* buffer){
    if(!(strcmp(buffer, "novel:")==0) && !(strcmp(buffer, "break;")==0)){
        int type = 0;
        char* value;
        value = malloc(250*sizeof(char));
        removeChar(buffer,'"');
        getType(&type, buffer);
        getValue(value, buffer);
        setTempVar(f, type, value);
    }
    if(strcmp(buffer, "break;")==0){
        addCurrent(f);
    }
}

void getType(int *result, char* buffer){
    char* value;
    value = malloc(50*sizeof(char));
    int space = 0;
    for(int i = 0; i < strlen(buffer); i++){
        if(buffer[i]!=':' && buffer[i]!=' '){
            value = realloc(value,(space+2)*sizeof(char));
            value[space] = buffer[i];
            space++;
        }
        if(buffer[i]==':'){
            break;
        }
    }
    value[space] = 0;

    //Die Switch wird nur verwendet, weil ich sonst den Text nicht bekomme(gegen ende)
    if(strcmp(value,"name")==0) {
        *result = 0;
    } else if(strcmp(value,"description")==0) {
        *result = 1;
    }else if(strcmp(value,"author")==0) {
        *result = 2;
    }else if(strcmp(value,"rating")==0) {
        *result = 3;
    }else if(strcmp(value,"power")==0) {
        *result = 4;
    }
}

void getValue(char* output, char* buffer){
    strcpy(output, strchr(buffer, ':'));
    removeChar(output, ':');
    while(output[0]==' ')
        removeFirstChar(output, ' ');
}