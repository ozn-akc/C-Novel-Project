#include "headers/string.h"

bool strCmp(int order, int sortBy, novel *first, novel *second){
    bool value =  false;
    switch(order){
        case 0:
            switch (sortBy) {
                case NAME:
                    value = strcasecmp(first->name, second->name)>0;
                    break;
                case DESCRIPTION:
                    value = strcasecmp(first->description, second->description)>0;
                    break;
                case AUTHOR:
                    value = strcasecmp(first->author, second->author)>0;
                    break;
                case RATING:
                    value = strcasecmp(first->rating, second->rating)>0;
                    break;
                case POWER:
                    value = first->power > second->power;
                    break;
            }
            break;
        case 1:
            switch (sortBy) {
                case NAME:
                    value = strcasecmp(first->name, second->name)<0;
                    break;
                case DESCRIPTION:
                    value = strcasecmp(first->description, second->description)<0;
                    break;
                case AUTHOR:
                    value = strcasecmp(first->author, second->author)<0;
                    break;
                case RATING:
                    value = strcasecmp(first->rating, second->rating)<0;
                    break;
                case POWER:
                    value = first->power < second->power;
                    break;
            }
            break;
    }
    return value;
}

void removeChar(char* buffer, char rmChar){
    char* value;
    value = malloc(sizeof(char));
    int space = 0;
    for(int i = 0; strlen(buffer); i++){
        if(buffer[i]!=rmChar){
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

void removeFirstChar(char* buffer, char rmChar){
    char* value;
    value = malloc(sizeof(char));
    int space = 0;
    bool firstRemoved = false;
    for(int i = 0; strlen(buffer); i++){
        if(buffer[i]!=rmChar || firstRemoved){
            value = realloc(value,(space+2)*sizeof(char));
            value[space] = buffer[i];
            space++;
        }
        if(buffer[i]==rmChar){
            firstRemoved = true;
        }
        if(buffer[i]==0){
            break;
        }
    }
    strcpy(buffer, value);
}
