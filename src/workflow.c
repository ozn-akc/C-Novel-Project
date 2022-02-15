#include "headers/workflow.h"

void evaluateInput(novel_field *, int*);
void welcomeMsg();
void requestInput();

/**
 * Init the workflow
 *
 */
void initialiseWorkflow(){
    int input = -1;

    novel_field field, *f = &field;

    initialiseList(f);
    outputWelcomeMsg();

    while(input){
        outputPossibleActions();
        inputInt(&input, ACTION);
        while(input>UPPER || input<LOWER){
            printf("\nYour Input is out of Bound ");
            if(input>UPPER){
                printf("%d is bigger then %d", input, UPPER);
            } else{
                printf("%d is smaller then %d", input, LOWER);
            }
            inputInt(&input, ACTION);
        }
        evaluateInput(f, &input);
    }
}

void evaluateInput(novel_field *f, int *input){
    int to_delete = 0;
    int to_edit = -1;
    int sortBy = 0;
    int order = -1;
    int lower = 0;
    int upper = 0;
    int multi = 0;
    char* value;
    value = malloc(201*sizeof(char));
    switch(*input){
        case 1:
            readFile(f);
            break;
        case 2:
            listToString(f);
            break;
        case 3:
            inputInt(&multi, MULTI);
            for(int j = 0; j<multi; j++){
                for(int i = 0; i<5; i++){
                    inputString(value, i);
                    setTempVar(f, i,value);
                }
                addCurrent(f);
            }
            break;
        case 4:
            while(0>=to_edit || to_edit>=getListLength()){
                inputInt(&to_edit, EDIT);
            }
            editEntry(f, to_edit);
            break;
        case 5:
            inputInt(&to_delete,DELETE);
            deleteFromList(f, to_delete);
            break;
        case 6:
            inputInt(&lower,DELETE_LOWER);
            inputInt(&upper,DELETE_UPPER);
            deleteFromListInRange(f, lower, upper);
            break;
        case 7:
            for(int i = 0; i<5; i++)
                outputPossibleSortBys(i);
            inputInt(&sortBy, SORT);
            inputInt(&order, ORDER);
            //quickSort(f, 0, getListLength()-1);
            bubbleSort(f, sortBy, order);
            break;
        case 8:
            removeDuplicates(f);
            break;
        case 9:
            hexterminate(f);
            break;
        case 10:
            writeFile(f);
            break;
        case 0:
            *input = 0;
            break;
        default:
            printf("Falsche Eingabe");
    }
}