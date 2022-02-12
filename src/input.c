#include "headers/input.h"
#include "headers/project.h"

void readInt(int *input, int reason){
    switch(reason){
        case 0:
            printf("\nPlease choose an Action (0-10):");
            break;
        case 1:
            printf("\nPlease choose an Entry to Delete:");
            break;
        case 2:
            printf("\nPlease choose a lower bound for Entry to Delete:");
            break;
        case 3:
            printf("\nPlease choose a upper bound for Entry to Delete:");
            break;
        case 4:
            printf("\nPlease enter the Power-Rating of the Novel:");
            break;
        case 5:
            printf("\nPlease choose an Entry to Edit:");
            break;
    }
    fflush(stdin);
    scanf("%d", input);
    fflush(stdin);
}

void readString(char* input, int type){
    printf("\nPlease enter the %s of the Novel: ", mapTypeToString(type));
    fflush(stdin);
    gets(input);
    fflush(stdin);
}