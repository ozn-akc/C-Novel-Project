#ifndef NOVEL_PROJECT_WRITER_H
#define NOVEL_PROJECT_WRITER_H

#include "project.h"
#include "novel_list.h"

#define DATAFILE "../data/novel_data.txt"

void writefile(novel_field*);

void writeListElementToFile(FILE*, novel*);

#endif //NOVEL_PROJECT_WRITER_H
