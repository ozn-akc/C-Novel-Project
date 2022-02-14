#include "headers/writer.h"

void writeFile(novel_field *f){
    FILE *file;
    file = fopen(DATAFILE,"w");
    if(!file){
        printf("Datei kann nicht geöffnet werden");
    } else{
        novel *current = f->start;
        while(current){
            writeListElementToFile(file, current);
            if(current->post){
                fprintf(file, "\n");
            }
            current = current->post;
        }
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