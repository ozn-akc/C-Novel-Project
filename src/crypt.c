#include "headers/crypt.h"

int key = -12;

void encrypt(char* value){
    int i = 0;
    while(true){
        if(value[i]!=0){
            value[i] += key;
        } else break;
        i++;
    }
}

void decrypt(char* value){
    int i = 0;
    while(true){
        if(value[i]!=0){
            value[i] -= key;
        } else break;
        i++;
    }
}