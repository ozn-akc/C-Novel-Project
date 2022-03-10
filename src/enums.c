#include "headers/enums.h"

char* mapTypeToString(int type){
    switch(type){
        case NAME:
            return "Name";
        case DESCRIPTION:
            return "Description";
        case AUTHOR:
            return "Author";
        case RATING:
            return "Rating";
        case POWER:
            return "Power-Rating";
    }
}