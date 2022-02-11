#include "headers/writer.h"

void writefile(novel_field *f){
    FILE *file;
    file = fopen(DATAFILE,"w");
    char buffer[250+1];
    strcpy(buffer,"");
    if(!file){
        printf("Datei kann nicht geöffnet werden");
    } else{
        f->curr = f->start;
        while(f->curr){
            writeListElementToFile(file, f->curr);
            if(f->curr->post){
                fprintf(file, "\n");
            }
            f->curr = f->curr->post;
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