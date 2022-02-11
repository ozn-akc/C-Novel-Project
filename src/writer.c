#include "headers/writer.h"

void writeFile(novel_field *f){
    FILE *file;
    file = fopen(DATAFILE,"w");
    char buffer[250+1];
    strcpy(buffer,"");
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
    fprintf(file, "novel:");
    fprintf(file, "\n    \"name\": \"%s\"", element->name);
    fprintf(file, "\n    \"description\": \"%s\"", element->description);
    fprintf(file, "\n    \"author\": \"%s\"", element->author);
    fprintf(file, "\n    \"rating\": \"%s\"", element->rating);
    fprintf(file, "\n    \"power\": \"%d\"", element->power);
    fprintf(file, "\nbreak;");
}