#include "headers/output.h"

void outputWelcomeMsg(){
    printf("\nWelcome to the Novel Library of Seven!");
    printf("\nThis is a magical place that gives you an overview over Sevens favorite Webnovels from webnovel.com!");
    printf("\nHere you have full control over all these Entries.");
    printf("\nChange, Delete, Save, Sort and Update all these methods have been unlocked for you!");
    printf("\nEnjoy your time and power while you can!");
    printf("\nZEHAHAHAHAHAHA!");
    printf("\n");
}

void outputPossibleActions(){
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

void outputPossibleSortBys(int value){
    printf("\n%d. To sort the List by the %s", value, mapTypeToString(value));
}