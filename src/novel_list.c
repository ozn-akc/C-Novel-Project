#include "headers\novel_list.h"

void list_init(novel_field *f){
    f->start = 0;
    f->curr = 0;
    f->between = 0;
}

void set_temp_element(novel_field *f, int type, char* value){
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

void add_current_element_to_list(novel_field *f){
    f->curr = (novel*) malloc(sizeof(novel));
    set_list_element(f);
    f->curr->pre = f->between;
    f->curr->post = 0;
    if(!f->between){
        f->start = f->curr;
    } else{
        f->between->post = f->curr;
    }
    f->between = f->curr;
}

void set_list_element(novel_field *f){
    strcpy(f->curr->name,           f->name);
    strcpy(f->curr->description,    f->description);
    strcpy(f->curr->author,         f->author);
    strcpy(f->curr->rating,         f->rating);
    f->curr->power  =               f->power;
}

void hexterminate(novel_field *f){
    f->curr = f->start;
    while(f->curr){
        printf("\n%-35s ",f->curr->name);
        printf("Currents   : %8X ",f->curr);
        printf("Previous   : %8X ",f->curr->pre);
        printf("Following  : %8X",f->curr->post);
        f->curr = f->curr->post;
    }
    printf("\n");
}

void list_to_string(novel_field *f){
    f->curr = f->start;
    int counter = 1;
    while(f->curr){
        printf("\n%d)", counter);
        printf("\n  Name: %-35s",f->curr->name);
        printf("\n");
        printf("\n  Description: %s",f->curr->description);
        printf("\n");
        printf("\n  Author: %-30s",f->curr->author);
        printf("\n");
        printf("\n  Rating: %-50s",f->curr->rating);
        printf("\n");
        printf("\n  Power Votes: %-6d",f->curr->power);
        printf("\n");
        f->curr = f->curr->post;
        counter++;
    }
}

void delete_element_from_list(novel_field *f, int i){
    f->curr = f->start;
    int counter = 1;
    while(f->curr){
        if(counter==i){
            //Wenn das vorherige nicht existier und das nächste Existiert setze den vorherigen des nächsten auf 0
            if(!f->curr->pre && f->curr->post){
                //First Element Case
                f->curr->post->pre = 0;
                f->start = f->curr->post;
            } else if(!f->curr->post && f->curr->pre){
                //Last Element case
                f->curr->pre->post = 0;
            }else if(!f->curr->post && !f->curr->pre){
                //Only Element Case
                free(f->curr);
                list_init(f);
                break;
            }
            else {
                f->curr->pre->post = f->curr->post;
                f->curr->post->pre = f->curr->pre;
            }
            free(f->curr);
            break;
        }
        f->curr = f->curr->post;
        counter++;
    }
}

void delete_elements_from_list(novel_field *f, int upper, int lower){
    for(int i = lower; i <= upper; i++){
        delete_element_from_list(f, lower);
    }
}

void sort_list(novel_field *f, int sortBy){
    //TODO Sorting Algorithm
}