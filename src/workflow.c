#include "headers/workflow.h"

void evaluateInput(novel_field *, int*);

/**
 * Init the workflow
 *
 */
void initialiseWorkflow(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    int input = -1;
    char password[30+1];
    novel_field field, *f = &field;

    initialiseList(f);
    outputWelcomeMsg();

    for(int i=0; i<3; i++){
        strcpy(password, "");
        printf("\nPlease enter the Password to continue:");
        printf("\n");
        fflush(stdin);
        while(password[0] == 0){
            SetConsoleTextAttribute(hConsole, 0x0);
            gets(password);
            SetConsoleTextAttribute(hConsole, 0x7);
        }
        encrypt(password);
        fflush(stdin);
        if(strcmp(password, PASSWORD)==0)break;
    }

    if(strcmp(password, PASSWORD)==0){
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
                printf("\n");
                inputInt(&input, ACTION);
            }
            evaluateInput(f, &input);
        }
    }
}

void evaluateInput(novel_field *f, int *input){
    int to_delete = 0;
    int to_edit = -1;
    int sortBy = 0;
    int order = -1;
    int multi = 0;
    int lower = 0;
    int upper = 0;
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
            while (true){
                for(int i = 0; i<5; i++){
                    inputString(value, i);
                    setTempVar(f, i,value);
                }
                addCurrent(f);
                inputInt(&multi, MULTI);
                if(!multi) break;
            }
            break;
        case 4:
            while(0>to_edit || to_edit>f->listLength){
                inputInt(&to_edit, EDIT);
            }
            editEntry(f, to_edit);
            break;
        case 5:
            inputInt(&to_delete,DELETER);
            deleteFromList(f, to_delete-1);
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
            quickSort(f, 0, f->listLength-1, order, sortBy);
            //bubbleSort(f, sortBy, order);
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