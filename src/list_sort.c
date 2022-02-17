#include "headers/list_sort.h"

void sortAlgorithm(novel_field *f, novel *first, int sortBy, int order){

    bool value = false;
    if(first && first->post){
        value = strCmp(order, sortBy, first, first->post);
        if(value){
            swap_items(first, first->post, f);
        } else{
        }
    }
}

void bubbleSort(novel_field *f, int sortBy, int order){
    for(int i = 0; i< f->listLength-1; i++){
        novel *current = f->start;
        while(current){
            if(!current->post)
                break;
            sortAlgorithm(f, current, sortBy, order);
            current = current->post;
        }
    }
}

int sort(novel_field *f, int left, int right, int order, int sortBy){
    int tempLeft = left;
    int tempRight = right;
    bool value = false;
    while(tempLeft<tempRight){
        while(strCmp(order, sortBy, getNovel(f, right), getNovel(f, tempLeft))){
            tempLeft++;
        }
        while(strCmp(order, sortBy, getNovel(f, tempRight), getNovel(f, right))){
            if(tempRight==tempLeft) break;
            tempRight--;
        }
        if(tempLeft<tempRight){
            swap_items(getNovel(f, tempLeft), getNovel(f, tempRight), f);
        }
    }
    if(strCmp(order, sortBy, getNovel(f, right), getNovel(f, tempLeft))){
        swap_items(getNovel(f, tempLeft), getNovel(f, right), f);
    }
    return tempLeft;
}

void quickSort(novel_field *f, int left, int right, int order, int sortBy){
    int med = 0;
    if(left<right){
        med = sort(f, left, right, order, sortBy);
        quickSort(f, left, med - 1, order, sortBy);
        quickSort(f, med+1, right, order, sortBy);
    }
}