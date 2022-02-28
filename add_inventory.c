#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tools.h"

void inventory_menu(){
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


void* add_inventory(){
    printf("ADD INVENTORY \n");
    
    char addID[64], addDescription[64], addQuantity[64], addPrice[64], addMonth[64], addDay[64], addYear[64];
    
    printf("\nEnter the Inventory ID: ");
    fgets(addID, 63, stdin);
    
    printf("\nEnter the Description: ");
    fgets(addDescription, 63, stdin);
    
    printf("\nEnter the Quantity of the Product: ");
    fgets(addQuantity, 63, stdin);
    
    printf("\nEnter the Expiry Date.");
    printf("\n(Input 0 to Month, Day, Year if no Expiry Date.)");
    printf("\nEnter the Expiry Month: ");
    fgets(addMonth, 63, stdin);
    printf("\nEnter the Expiry Day: ");
    fgets(addDay, 63, stdin);
    printf("\nEnter the Expiry Year: ");
    fgets(addYear, 63, stdin);
    
    printf("\nEnter the Price: ");
    fgets(addPrice, 63, stdin);
    
    if (Quantity_validity_checker(addQuantity) == 0){
    	printf("Invalid Quantity.");
    	
    	inventory_menu();
	}
    
	inventory_menu();
}

