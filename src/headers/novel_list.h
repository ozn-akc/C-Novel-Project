#ifndef NOVEL_LIST_H
#define NOVEL_LIST_H

#include "project.h"

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

void list_init(novel_field*);

void set_temp_element(novel_field *f, int type, char* value);

void add_current_element_to_list(novel_field*);

void set_list_element(novel_field*);

void hexterminate(novel_field*);

void list_to_string(novel_field*);

void delete_element_from_list(novel_field*, int i);

void delete_elements_from_list(novel_field*, int upper, int lower);

void sort_list(novel_field*, int);

#endif