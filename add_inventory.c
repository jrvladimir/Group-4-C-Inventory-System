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

void inventory_add(){
    printf("\n*******************************\n");
    printf("*[X] Exit                     *\n");
    printf("*******************************\n\n");
    printf("Please input choice: ");
    int module = 6;
	choice(module);	
}


void* add_inventory(){

	
	FILE* fp = fopen("Inventory_ST_NoBOM.csv", "a+");
	 if (!fp) {
        // Error in file opening
        printf("Can't open file\n");
        inventory_menu();
    }
    	
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
    
    int ID_check, DESC_check, QTY_check, DATE_check, PRICE_check;
    
    if ( ID_validity_checker(addID) == 0 ){
    	printf("\nInvalid ID.");
    	ID_check = 0;
	}else{
		if (ID_duplication_checker(addID) == 1){
			printf("\nDuplicate ID.");
			ID_check = 0;
		}else{
			printf("\nValid ID.");
			ID_check = 1;
		}
	}
	
	
	if ( Description_validity_checker(addDescription) == 0 ){
    	printf("\nInvalid Description.");
    	DESC_check = 0;
	}else{
		printf("\nValid Description.");
		DESC_check = 1;

	}
    
    if ( Quantity_validity_checker(addQuantity) == 0 ){
    	printf("\nInvalid Quantity.");
    	QTY_check = 0;
	}else{
		printf("\nValid Quantity.");
		QTY_check = 1;
	}
    
	int Day, Month;   
	
    if ( Date_validity_checker(addMonth, addDay, addYear) == 0 ){
    	if (Expiry_date_checker(addMonth, addDay, addYear) == 1){
    		printf("\nNo Expiration.");
    		DATE_check = 1;
		}else{
			printf("\nInvalid date.");
			DATE_check = 0;
		}	
	}else{
		printf("Valid Date.");
		DATE_check = 2;
		sscanf(addDay, "%d", &Day);
		sscanf(addMonth, "%d", &Month);
	}
	
	float Price;
	
	if ( Price_validity_checker(addPrice) == 0 ){
    	printf("\nInvalid Price.");
    	PRICE_check = 0;
	}else{
		printf("\nValid Price.");
		PRICE_check = 1;
		sscanf(addPrice, "%f", &Price);
	}
    
    addID[strlen(addID) - 1] = '\0';
    addDescription[strlen(addDescription) - 1] = '\0';
    addQuantity[strlen(addQuantity) - 1] = '\0';
    addYear[strlen(addYear) - 1] = '\0';

    
    if (ID_check == 0 || DESC_check == 0 || QTY_check == 0 || DATE_check == 0 || PRICE_check == 0){
    	inventory_menu();
	}else if (ID_check == 1 && DESC_check == 1 && QTY_check == 1 && DATE_check == 1 && PRICE_check == 1){
    	printf("\nItem Added.");
    	fprintf(fp, "\n%s,%s,%s,-,%.2f", 
			addID, addDescription, addQuantity, Price);
		inventory_add();
	}else if (ID_check == 1 && DESC_check == 1 && QTY_check == 1 && DATE_check == 2 && PRICE_check == 1){
    	printf("\nItem Added.");
    	fprintf(fp, "\n%s,%s,%s,%s-%02d-%02d,%.2f",
			addID, addDescription, addQuantity, addYear, Month, Day, Price);
		inventory_add();
    }
    fclose(fp);
} 


