#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tools.h"

void* search_inventory(){
    printf("SEARCH INVENTORY\n");
    printf("*******************************\n");
    printf("*[D] Search Inventory Again   *\n");
    printf("*[M] Display Main Menu Again  *\n");
    printf("*[X] Exit                     *\n");
    printf("*******************************\n\n");
    printf("Please input choice: ");
    int module = 4;
    choice(module);
}