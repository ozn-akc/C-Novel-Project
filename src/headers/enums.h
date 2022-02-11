#ifndef NOVEL_PROJECT_ENUMS_H
#define NOVEL_PROJECT_ENUMS_H

#include <string.h>


enum type{NAME = 0, DESCRIPTION, AUTHOR, RATING, POWER};

char* mapTypeToString(int type);

#endif //NOVEL_PROJECT_ENUMS_H
