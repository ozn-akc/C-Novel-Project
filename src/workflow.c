#include "headers/workflow.h"

void evaluate_input(novel_field *, int*);
void welcome_msg();
void request_input();
void read_int_input(int*, int);
void read_str_input(char*,int);

/**
 * Init the workflow
 *
 */
void workflow_init(){
    int input = -1;

    novel_field field, *f = &field;

    initialiseList(f);
    welcome_msg();

    while(input){
        request_input();
        read_int_input(&input, 0);
        while(input>UPPER || input<LOWER){
            printf("\nYour Input is out of Bound ");
            if(input>UPPER){
                printf("%d is bigger then %d", input, UPPER);
            } else{
                printf("%d is smaller then %d", input, LOWER);
            }
            read_int_input(&input, 0);
        }
        evaluate_input(f, &input);

    }
}

void welcome_msg(){
    printf("\nWelcome to the Novel Library of Seven!");
    printf("\nThis is a magical place that gives you an overview over Sevens favorite Webnovels from webnovel.com!");
    printf("\nHere you have full control over all these Entries.");
    printf("\nChange, Delete, Save, Sort and Update all these methods have been unlocked for you!");
    printf("\nEnjoy your time and power while you can!");
    printf("\nZEHAHAHAHAHAHA!");
    printf("\n");
}

void request_input(){
    printf("\nThere are many Action you can choose from:");
    printf("\n0. Your Job is done here and you want to stop");
    printf("\n1. Read the Data from the super secret file");
    printf("\n2. Show all The Entries");
    printf("\n3. Create a new Entry");
    printf("\n4. Update one of the Entries");
    printf("\n5. Delete one of the Entries");
    printf("\n6. Delete Entries in Range");
    printf("\n7. Sort the Entries");
    printf("\n8. Remove double Entries");
    printf("\n9. Execute Hexterminate.exe");
    printf("\n10. Save All Changes to the super secret file");
    printf("\n");
}

void evaluate_input(novel_field *f, int *input){
    int to_delete = 0;
    int lower = 0;
    int upper = 0;
    char* value;
    value = malloc(201*sizeof(char));
    switch(*input){
        case 1:
            readfile(f);
            break;
        case 2:
            listToString(f);
            break;
        case 3:
            for(int i = 0; i<5; i++){
                read_str_input(value, i);
                setTempVar(f, i,value);
            }
            addCurrent(f);
            break;
        case 4:
            read_int_input(input, 5);
            editEntry(f, *input);
            break;
        case 5:
            read_int_input(&to_delete,1);
            deleteFromList(f, to_delete);
            break;
        case 6:
            read_int_input(&lower,2);
            read_int_input(&upper,3);
            deleteFromListInRange(f, lower, upper);
            break;
        case 7:
            quickSort(f, 0, getListLength()-1);
            //bubbleSort(0);
            break;
        case 8:
            removeDuplicates(f);
            break;
        case 9:
            hexterminate(f);
            break;
        case 10:
            writefile(f);
            break;
        case 0:
            *input = 0;
            break;
        default:
            printf("Falsche Eingabe");
    }
}