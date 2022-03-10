#ifndef NOVEL_PROJECT_ENUMS_H
#define NOVEL_PROJECT_ENUMS_H

#include <string.h>

enum type{NAME = 0, DESCRIPTION = 1, AUTHOR = 2, RATING = 3, POWER = 4, ACTION = 5, DELETER = 6, DELETE_LOWER = 7, DELETE_UPPER = 8, POWER_REASON = 9, EDIT = 10, SORT = 11, ORDER = 12, MULTI = 13};

char* mapTypeToString(int type);

#endif //NOVEL_PROJECT_ENUMS_H