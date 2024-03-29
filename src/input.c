#include "headers/input.h"
#include "headers/project.h"

void inputInt(int *input, int reason){
    switch(reason){
        case ACTION:
            printf("\nPlease choose an Action (0-10):");
            break;
        case DELETER:
            printf("\nPlease choose an Entry to Delete:");
            break;
        case DELETE_LOWER:
            printf("\nPlease choose a lower bound for Entry to Delete:");
            break;
        case DELETE_UPPER:
            printf("\nPlease choose a upper bound for Entry to Delete:");
            break;
        case POWER_REASON:
            printf("\nPlease enter the Power-Rating of the Novel:");
            break;
        case EDIT:
            printf("\nPlease choose an Entry to Edit:");
            break;
        case SORT:
            printf("\nPlease choose a Category to sort by:");
            break;
        case ORDER:
            printf("\nPlease choose in which order you want the List to be sorted Asc(0) or Desc(1):");
            break;
        case MULTI:
            printf("\nDo you want to create a new Entry Yes(1) No(0): ");
            break;
    }
    fflush(stdin);
    scanf("%d", input);
    fflush(stdin);
}

void inputString(char* input, int type){
    strcpy(input, "");
    printf("\nPlease enter the %s of the Novel: ", mapTypeToString(type));
    fflush(stdin);
    while(input[0] == 0){
        gets(input);
    }
    fflush(stdin);
}