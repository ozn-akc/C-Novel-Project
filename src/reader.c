#include "headers/reader.h"

void analyse_buffer(novel_field *f, char* buffer);
void remove_char(char*, char );
void remove_first_char(char* buffer, char rmchar);
void getType(int*, char* );
void getValue(char*, char* );

void readfile(novel_field *f){
    FILE *file;
    file = fopen(DATAFILE,"r");
    char buffer[250+1];
    strcpy(buffer,"");
    if(!file){
        printf("Datei kann nicht geöffnet werden");
    } else{
        while(!feof(file)){
            fgets(buffer, 250, file);
            buffer[strcspn(buffer, "\n")] = 0;
            analyse_buffer(f, buffer);
        }
    }
    fclose(file);
}

void analyse_buffer(novel_field *f, char* buffer){
    if(!(strcmp(buffer, "novel:")==0) && !(strcmp(buffer, "break;")==0)){
        int type = 0;
        char* value;
        value = malloc(250*sizeof(char));
        remove_char(buffer,'"');
        getType(&type, buffer);
        getValue(value, buffer);
        setTempVar(f, type, value);
    }
    if(strcmp(buffer, "break;")==0){
        addCurrent(f);
    }
}

void remove_char(char* buffer, char rmchar){
    char* value;
    value = malloc(sizeof(char));
    int space = 0;
    for(int i = 0; strlen(buffer); i++){
        if(buffer[i]!=rmchar){
            value = realloc(value,(space+2)*sizeof(char));
            value[space] = buffer[i];
            space++;
        }
        if(buffer[i]==0){
            break;
        }
    }
    strcpy(buffer, value);
}

void remove_first_char(char* buffer, char rmchar){
    char* value;
    value = malloc(sizeof(char));
    int space = 0;
    bool firstremoved = false;
    for(int i = 0; strlen(buffer); i++){
        if(buffer[i]!=rmchar || firstremoved){
            value = realloc(value,(space+2)*sizeof(char));
            value[space] = buffer[i];
            space++;
        }
        if(buffer[i]==rmchar){
            firstremoved = true;
        }
        if(buffer[i]==0){
            break;
        }
    }
    strcpy(buffer, value);
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
    remove_char(output, ':');
    while(output[0]==' ')
        remove_first_char(output, ' ');
}

