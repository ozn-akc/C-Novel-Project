#include "headers/crypt.h"

int key = -3;

void encrypt(char* value){
    int i = 0;
    bool j = true;
    while(true){
        if(value[i]!=0){
            if(j){
                value[i] += key;
            } else{
                value[i] -= key;
            }
        } else break;
        j = !j;
        i++;
    }
}

void decrypt(char* value){
    int i = 0;
    bool j = true;
    while(true){
        if(value[i]!=0){
            if(j){
                value[i] -= key;
            } else{
                value[i] += key;
            }
        } else break;
        j = !j;
        i++;
    }
}