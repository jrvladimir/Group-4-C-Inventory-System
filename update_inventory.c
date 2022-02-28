#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tools.h"

void* update_inventory(){
    printf("UPDATE INVENTORY \n");
    printf("************************************\n");
    printf("*[B] Update Inventory Again        *\n");
    printf("*[M] Display Main Menu Again       *\n");
    printf("*[X] Exit                          *\n");
    printf("************************************\n\n");
    printf("Please input choice: ");
    int module = 2;
    choice(module);
}