#include "headers/enums.h"

char* mapTypeToString(int type){
    switch(type){
        case NAME:
            return "Name";
            break;
        case DESCRIPTION:
            return "Description";
            break;
        case AUTHOR:
            return "Author";
            break;
        case RATING:
            return "Rating";
            break;
        case POWER:
            return "Power-Rating";
            break;
    }
}