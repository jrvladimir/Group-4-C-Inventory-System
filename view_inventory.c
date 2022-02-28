#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tools.h"


void* view_inventory(){
    printf("VIEW INVENTORY \n");
    printf("*******************************\n");
    printf("*[C] View Inventory Again     *\n");
    printf("*[M] Display Main Menu Again  *\n");
    printf("*[X] Exit                     *\n");
    printf("*******************************\n\n");
    printf("Please input choice: ");
    int module = 3;
    choice(module);
}