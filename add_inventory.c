#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tools.h"

void* add_inventory(){
    printf("ADD INVENTORY \n");
    printf("*******************************\n");
    printf("*[A] Add Inventory Again      *\n");
    printf("*[M] Display Main Menu Again  *\n");
    printf("*[X] Exit                     *\n");
    printf("*******************************\n\n");
    printf("Please input choice: ");
    int module = 1;
	choice(module);	
}