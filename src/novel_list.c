#include "headers/novel_list.h"
#include "headers/list_swap.h"

void printCurrentElement(novel_field *, int);

int list_length = 0;

void initialiseList(novel_field *f){
    f->start = 0;
    f->curr = 0;
    f->between = 0;
}

int getListLength(){
    return list_length;
}

//TODO create Type enum with values 0-4
void setTempVar(novel_field *f, int type, char* value){
    switch(type) {
        case 0:
            strcpy(f->name, value);
            break;
        case 1:
            strcpy(f->description, value);
            break;
        case 2:
            strcpy(f->author, value);
            break;
        case 3:
            strcpy(f->rating, value);
            break;
        case 4:
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
    list_length++;
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
    novel *counter = f->start;
    for(int i= 1; i<entry;i++){
        counter = counter->post;
    }
    for(int i = 0; i<5; i++){
        printCurrentElement(f, i);
        read_str_input(value, i);
        setTempVar(f, i,value);
    }
    updateCurrentEntry(f);
}

//Value without 0
void deleteFromList(novel_field *f, int i){
    novel *todelete = f->start;
    int counter = 1;
    while(todelete){
        if(counter==i){
            //Wenn das vorherige nicht existiert und das nächste Existiert setze den vorherigen des nächsten auf 0
            if(!todelete->pre && todelete->post){
                //First Element Case
                todelete->post->pre = 0;
                f->start = todelete->post;
            } else if(!todelete->post && todelete->pre){
                //Last Element case
                todelete->pre->post = 0;
                f->between = todelete->pre;
            }else if(!todelete->post && !todelete->pre){
                //Only Element Case
                free(todelete);
                initialiseList(f);
                break;
            }
            else {
                todelete->pre->post = todelete->post;
                todelete->post->pre = todelete->pre;
            }
            free(todelete);
            break;
        }
        todelete = todelete->post;
        counter++;
    }
}

void deleteFromListInRange(novel_field *f, int lower, int upper){
    for(int i = lower; i <= upper; i++){
        deleteFromList(f, lower);
    }
}

void removeDuplicates(novel_field *f){
    novel *dom, *sub;
    dom = f->start;
    bool toRemove = false;
    while(dom){
        sub = f->start;
        int i = 1;
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

void sortAlgorithm(novel_field *f, novel *first){
    if(first && first->post){
        if(strcmp(first->name, first->post->name)>0){
            swap_items(first, first->post, f);
        } else{
        }
    }
}

void bubbleSort(novel_field *f, int sortBy){
    for(int i = 0; i< list_length-1; i++){
        novel *current = f->start;
        while(current->post){
            sortAlgorithm(f, current);
            current = current->post;
        }
    }
}

void quickSort(novel_field *f, int left, int right){
    int index_left, index_right, median;
    index_left = left;
    index_right = right;
    median = (left+right)/2;
    while(index_left<index_right){
        while(strcmp(getNovel(f, index_left)->name, getNovel(f, median)->name)<0){
            index_left++;
        }
        while(strcmp(getNovel(f, median)->name, getNovel(f, index_right)->name)<0){
            index_right--;
        }
        swap_items(getNovel(f, index_left), getNovel(f, index_right), f);
        if(index_left==median){
            median = index_left;
        } else{
            if(index_right == median){
                median = index_right;
            }
        }
        if(index_left<=median){
            index_left++;
        }
        if(index_right>=median){
            index_right--;
        }
    }
    if(left < median){
        quickSort(f, left, median-1);
    }
    if(right > median){
        quickSort(f, median+1, right);
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
    while(current){
        printf("\n%d)", counter);
        printf("\n  Name: %-35s",current->name);
        printf("\n");
        printf("\n  Description: %s",current->description);
        printf("\n");
        printf("\n  Author: %-30s",current->author);
        printf("\n");
        printf("\n  Rating: %-50s",current->rating);
        printf("\n");
        printf("\n  Power Votes: %-6d",current->power);
        printf("\n");
        current = current->post;
        counter++;
    }
}

void printCurrentElement(novel_field *f, int type){
    switch(type){
        case 0:
            printf("\nCurrent Name: %30s", f->curr->name);
            break;
        case 1:
            printf("\nCurrent Description: %30s", f->curr->description);
            break;
        case 2:
            printf("\nCurrent Author: %30s", f->curr->author);
            break;
        case 3:
            printf("\nCurrent Rating: %30s", f->curr->rating);
            break;
        case 4:
            printf("\nCurrent Power-Rating: %30d", f->curr->power);
            break;
    }
}