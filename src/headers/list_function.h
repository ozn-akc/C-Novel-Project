#ifndef NOVEL_LIST_H
#define NOVEL_LIST_H

#include "project.h"
#include "input.h"
#include "crypt.h"
#include "string.h"
#include "list.h"
#include "list_swap.h"

void initialiseList(novel_field *);
novel* getNovel(novel_field*, int);
void setTempVar(novel_field*, int, char*);
void setCurrentListElement(novel_field*);
void addCurrent(novel_field*);
void editEntry(novel_field*, int);
void deleteFromList(novel_field*, int);
void deleteFromListInRange(novel_field*, int, int);
void removeDuplicates(novel_field*);
void bubbleSort(novel_field*, int, int);
void quickSort(novel_field*, int, int, int, int);
void hexterminate(novel_field *);
void listToString(novel_field *);

#endif