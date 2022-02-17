#ifndef NOVEL_PROJECT_LIST_H
#define NOVEL_PROJECT_LIST_H

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
    int listLength;
    novel *curr;
    novel *start;
    novel *between;
}novel_field;

#endif //NOVEL_PROJECT_LIST_H