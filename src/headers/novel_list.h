#ifndef NOVEL_LIST_H
#define NOVEL_LIST_H

#include "project.h"
#include "input.h"
#include "crypt.h"

typedef struct m_novel{
    char name[35+1];
    char description[200+1];
    char author[30+1];
    char rating[50+1];
    int power;
    struct m_novel *pre;
    struct m_novel *post;
} novel;

typedef struct{
    char name[35+1];
    char description[200+1];
    char author[30+1];
    char rating[50+1];
    int power;
    novel *curr;
    novel *start;
    novel *between;
}novel_field;

void initialiseList(novel_field *);

int getListLength();

void setTempVar(novel_field *, int, char*);

void setCurrentListElement(novel_field *);

void addCurrent(novel_field *);

void editEntry(novel_field *, int);

void deleteFromList(novel_field *, int i);

void deleteFromListInRange(novel_field *, int, int);

void removeDuplicates(novel_field *);

void bubbleSort(novel_field *, int, int);

void quickSort(novel_field *, int left, int right);

void hexterminate(novel_field *);

void listToString(novel_field *);

#endif