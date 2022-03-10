#include "headers/list_function.h"

void printCurrentElement(novel_field *, int);


void initialiseList(novel_field *f){
    f->start = 0;
    f->curr = 0;
    f->between = 0;
    f->listLength = 0;
}

void setTempVar(novel_field *f, int type, char* value){
    switch(type) {
        case NAME:
            strcpy(f->name, value);
            break;
        case DESCRIPTION:
            strcpy(f->description, value);
            break;
        case AUTHOR:
            strcpy(f->author, value);
            break;
        case RATING:
            strcpy(f->rating, value);
            break;
        case POWER:
            f->power = atoi(value);
            break;
        default:
            break;
    }
}

novel* getNovel(novel_field *f, int pos){
    novel *counter = f->start;
    int value = 0;
    while(value!=pos && counter->post){
        counter = counter->post;
        value++;
    }
    return counter;
}


void setCurrentListElement(novel_field *f){
    strcpy(f->curr->name,f->name);
    strcpy(f->curr->description,f->description);
    strcpy(f->curr->author,f->author);
    strcpy(f->curr->rating,f->rating);
    f->curr->power  =               f->power;
}

void addCurrent(novel_field *f){
    f->curr = (novel*) malloc(sizeof(novel));
    setCurrentListElement(f);
    f->curr->pre = f->between;
    f->curr->post = 0;
    if(!f->between){
        f->start = f->curr;
    } else{
        f->between->post = f->curr;
    }
    f->between = f->curr;
    f->listLength++;
}

void updateCurrentEntry(novel_field *f){
    strcpy(f->curr->name, f->name);
    strcpy(f->curr->description, f->description);
    strcpy(f->curr->author, f->author);
    strcpy(f->curr->rating, f->rating);
    f->curr->power = f->power;
}

void editEntry(novel_field *f, int entry){
    char* value;
    value = malloc(201*sizeof(char));
    f->curr = getNovel(f, entry);
    for(int i = 0; i<5; i++){
        printCurrentElement(f, i);
        inputString(value, i);
        setTempVar(f, i, value);
    }
    updateCurrentEntry(f);
}

void deleteFromList(novel_field *f, int i){
    novel *todelete = getNovel(f, i);
    if(todelete){
        //Wenn das vorherige nicht existiert und das nächste Existiert setze den vorherigen des nächsten auf 0
        if(!todelete->pre && todelete->post){
            //First Element Case
            todelete->post->pre = 0;
            f->start = todelete->post;
            free(todelete);
        } else if(!todelete->post && todelete->pre){
            //Last Element case
            todelete->pre->post = 0;
            f->between = todelete->pre;
            free(todelete);
        }else if(!todelete->post && !todelete->pre){
            //Only Element Case
            free(todelete);
            initialiseList(f);
        }
        else {
            todelete->pre->post = todelete->post;
            todelete->post->pre = todelete->pre;
            free(todelete);
        }
        f->listLength--;
    }
}

void deleteFromListInRange(novel_field *f, int lower, int upper){
    for(int i = lower; i <= upper; i++){
        deleteFromList(f, lower-1);
    }
}

void removeDuplicates(novel_field *f){
    novel *dom, *sub;
    dom = f->start;
    bool toRemove = false;
    while(dom){
        sub = f->start;
        int i = 0;
        while(sub){
            if(sub != dom){
                if(
                        strcmp(sub->name, dom->name) == 0 &&
                        strcmp(sub->description, dom->description) == 0 &&
                        strcmp(sub->author, dom->author) == 0 &&
                        strcmp(sub->rating, dom->rating) == 0 &&
                                sub->power == dom->power
                        ){
                    toRemove = true;
                }
            }
            sub = sub->post;
            if(toRemove){
                deleteFromList(f, i);
                i--;
                toRemove = false;
            }
            i++;
        }
        dom = dom->post;
    }
}


void hexterminate(novel_field *f){
    novel *counter = f->start;
    while(counter){
        printf("\n%-35s ",counter->name);
        printf("Previous   : %8X ",counter->pre);
        printf("Currents   : %8X ",counter);
        printf("Following  : %8X",counter->post);
        counter = counter->post;
    }
    printf("\n");
}

void listToString(novel_field *f){
    novel *current = f->start;
    int counter = 1;
    int answer = 0;
    while(current){
        if(counter/10 == 0){
            printf("\n%d%-4s", counter, ")");
        } else if(counter/10 == 1){
            printf("\n%d%-3s", counter, ")");
        }else if(counter/10 == 2){
            printf("\n%d%-2s", counter, ")");
        }else{
            printf("\n%d%-1s", counter, ")");
        }
        printf("Name: %-35s",current->name);
        printf("\n     Description: %s",current->description);
        printf("\n     Author: %-30s",current->author);
        printf("\n     Rating: %-50s",current->rating);
        printf("\n     Power Votes: %-6d",current->power);
        printf("\n");
        current = current->post;
        counter++;
        if(!current) break;
        if(counter%5==1){
            printf("\nWillst du weiter machen Y(1)/N(0)\n");
            scanf("%d", &answer);
            if(answer==0)
            break;
        }
    }
}

void printCurrentElement(novel_field *f, int type){
    switch(type){
        case NAME:
            printf("\nCurrent Name: %30s", f->curr->name);
            break;
        case DESCRIPTION:
            printf("\nCurrent Description: %30s", f->curr->description);
            break;
        case AUTHOR:
            printf("\nCurrent Author: %30s", f->curr->author);
            break;
        case RATING:
            printf("\nCurrent Rating: %30s", f->curr->rating);
            break;
        case POWER:
            printf("\nCurrent Power-Rating: %30d", f->curr->power);
            break;
    }
}