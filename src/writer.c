#include "headers/writer.h"

void writeFile(novel_field *f){
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
        file = fopen(datafile,"w");
        if(!file || !strstr(datafile, ".txt")){
            printf("\nFile is not right\n");
        } else break;
    }
    novel *current = f->start;
    while(current){
        writeListElementToFile(file, current);
        if(current->post){
            fprintf(file, "\n");
        }
        current = current->post;
    }
    fclose(file);
}

void writeListElementToFile(FILE *file, novel *element){
    char str[250];
    snprintf(str, 250, "%s", "novel:");
    encrypt(str);
    fprintf(file, str);

    snprintf(str, 250, "    \"name\": \"%s\"", element->name);
    encrypt(str);
    fprintf(file,"\n%s", str);

    snprintf(str, 250, "    \"description\": \"%s\"", element->description);
    encrypt(str);
    fprintf(file, "\n%s",str);

    snprintf(str, 250, "\"author\": \"%s\"", element->author);
    encrypt(str);
    fprintf(file, "\n%s",str);

    snprintf(str, 250, "\"rating\": \"%s\"", element->rating);
    encrypt(str);
    fprintf(file, "\n%s",str);

    snprintf(str, 250,"\"power\": \"%d\"", element->power);
    encrypt(str);
    fprintf(file, "\n%s",str);

    snprintf(str, 250, "%s", "break;");
    encrypt(str);
    fprintf(file, "\n%s",str);
}