#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tools.h"

void* menu(){
    printf("MAIN MENU \n");
    printf("*******************************\n");
    printf("*[A] Add Inventory            *\n");
    printf("*[B] Update Inventory         *\n");
    printf("*[C] View Inventory           *\n");
    printf("*[D] Search Inventory         *\n");
    printf("*[M] Display Main Menu Again  *\n");
    printf("*[X] Exit                     *\n");
    printf("*******************************\n\n");
    printf("Please input choice: ");
    int module = 0;
    choice(module);
}