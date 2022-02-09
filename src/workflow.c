#include "headers/workflow.h"
#include "headers/reader.h"

void evaluate_input(int*, novel_field*);
void welcome_msg();
void request_input();
void read_input(int*, int);

/**
 * Init the workflow
 *
 */
void workflow_init(){
    novel_field field, *f = &field;
    int input = -1;

    //init the list
    list_init(f);
    welcome_msg();

    while(input){
        request_input();
        read_input(&input, 0);
        while(input>UPPER || input<LOWER){
            read_input(&input, 0);
        }
        evaluate_input(&input, f);

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
    printf("\n9. Save All Changes to the super secret file");
    printf("\n");
}

void read_input(int *input, int reason){
    switch(reason){
        case 0:
            printf("\nPlease choose an Action (0-9):");
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
    }
    fflush(stdin);
    scanf("%d",input);
    fflush(stdin);
    printf("\n");
}

void evaluate_input(int *input, novel_field *f){
    int to_delete = 0;
    int lower = 0;
    int upper = 0;
    switch(*input){
        case 1:
            readfile(f);
            break;
        case 2:
            list_to_string(f);
            break;
        case 3:
            hexterminate(f);
            break;
        case 4:
            f->curr = f->start;
            sort_list(f, 0);
            break;
        case 5:
            read_input(&to_delete,1);
            delete_element_from_list(f,to_delete);
            break;
        case 6:
            read_input(&lower,2);
            read_input(&upper,3);
            delete_elements_from_list(f, upper, lower);
            break;
        case 7:
            sort_list(f, 0);
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 0:
            *input = 0;
            break;
        default:
            printf("Falsche Eingabe");
    }
}