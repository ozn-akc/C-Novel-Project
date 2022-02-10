#include "headers/input.h"
#include "headers/project.h"

void read_int_input(int *input, int reason){
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
    scanf("%d",input);
    fflush(stdin);
}

void read_str_input(char* input, int reason){
    switch(reason){
        case 0:
            printf("\nPlease enter the Name of the Novel:");
            break;
        case 1:
            printf("\nPlease enter the Description of the Novel:");
            break;
        case 2:
            printf("\nPlease enter the Author of the Novel:");
            break;
        case 3:
            printf("\nPlease enter the Rating of the Novel:");
            break;
        case 4:
            printf("\nPlease enter the Power-Rating of the Novel:");
            break;
    }
    fflush(stdin);
    scanf("%s",input);
    fflush(stdin);
}