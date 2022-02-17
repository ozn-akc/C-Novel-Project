#ifndef NOVEL_PROJECT_STRING_H
#define NOVEL_PROJECT_STRING_H

#include "project.h"
#include "list.h"
#include "enums.h"

bool strCmp(int order, int sortBy, novel *first, novel *second);
void removeChar(char*, char );
void removeFirstChar(char* buffer, char rmchar);

#endif //NOVEL_PROJECT_STRING_H
