#include "headers/enums.h"

char* mapTypeToString(int type){
    char* str;
    switch(type){
        case NAME:
            strcpy(str, "Name");
            break;
        case DESCRIPTION:
            strcpy(str, "Description");
            break;
        case AUTHOR:
            strcpy(str, "Author");
            break;
        case RATING:
            strcpy(str, "Rating");
            break;
        case POWER:
            strcpy(str, "Power-Rating");
            break;
    }
    return str;
}