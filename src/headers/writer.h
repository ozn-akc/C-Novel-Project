#ifndef NOVEL_PROJECT_WRITER_H
#define NOVEL_PROJECT_WRITER_H

#include "project.h"
#include "list_function.h"

#define DATAFILE "../data/novel_data.txt"

void writeFile(novel_field*);

void writeListElementToFile(FILE*, novel*);

#endif //NOVEL_PROJECT_WRITER_H
