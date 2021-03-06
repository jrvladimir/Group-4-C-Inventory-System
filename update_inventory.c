#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define DELIMITER "\";,\n"
#define true 0
#define false 1
#include <ctype.h>
#include "tools.h"

struct element{
    int id;
    char description[100];
    int quantity;
    char date[100];
    float price;
};

void* update_menu(){
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

count_inventory_three(){
	FILE* fp = fopen("Inventory_ST_NoBOM.csv", "r");
	 if (!fp) {
        // Error in file opening

    }
	char buffer[1024];
        int row = 0;
        while (fgets(buffer,1024, fp)) {
            row++;
        }
        fclose(fp);
        return row;
}

into_structure_three(struct element product[1000]){
	FILE* fp = fopen("Inventory_ST_NoBOM.csv", "r");
	 if (!fp) {
        // Error in file opening

    }
	char buffer[1024];
  
        int row = 0;
        int column = 0;

  
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;

  
            // Splitting the data
            char* value = strtok(buffer, DELIMITER);
  
            while (value) {
                // Column 1
                if (column == 0) {
                    product[row].id = strtol(value, NULL, 10);
                }
  
                // Column 2
                if (column == 1) {
                    strcpy(product[row].description,value);
                }
  
                // Column 3
                if (column == 2) {
                    product[row].quantity = strtol(value, NULL, 10);
                }
                
				// Column 4
                if (column == 3) {
                    strcpy(product[row].date,value);
                }
                
				// Column 5
                if (column == 4) {
                    product[row].price = strtof(value, NULL);
                }
                value = strtok(NULL, DELIMITER);
                column++;
            }        
            row++;
        }
        fclose(fp);

}


int* search_inventory_three(struct element product[1000], int s, int ID){
	int i;
	
	int z = false;
	printf("SEARCH ITEM\n\n");

	
    	for (i = 0; i < s; i++)
    {

	    	if( ID ==  product[i].id)
			{
			z = true;
			printf("\n");
			printf("===============================================================================================================");
			printf("\nID                  DESCRIPTION                       QUANTITY        EXPIRY DATE        PRICE        \n");
			printf("===============================================================================================================\n");
	        printf("%d\t     ", product[i].id);
	  		printf("%s\t\t ", product[i].description);
	  		printf("%d\t\t ", product[i].quantity);
	  		printf("%s\t\t ", product[i].date); 
	  		printf("%.2f\t\t ", product[i].price);
			printf("\n\n\nITEM FOUND!\n\n");
			break;
			} 
		
			 
	}
	if (z == false)
			{
				printf("\nItem ID %d does not exist!\n ", ID);
			}
	return z;	
}

copy_inventory(struct element product[1000], int s, int ID, int IDD, char DESCRIPTION[100], int QUANTITY, char DATE[100], float PRICE){
	int i;
	
    	for (i = 0; i < s; i++)
    {
	    	if( ID ==  product[i].id)
			{
	        product[i].id = IDD;
	  		strcpy(product[i].description,DESCRIPTION);
	  		product[i].quantity = QUANTITY;
	  		strcpy(product[i].date,DATE);
			product[i].price = PRICE;
			break;
			} 				 
	}
	
	int z;
	
	FILE* fp = fopen("Inventory_ST_NoBOM.csv", "w");
	if (!fp) {
        // Error in file opening

    }
    
    for ( z = 0; z < s; z++)
    {
    	fprintf(fp, "\"%05d\",\"%s\",\"%d\",\"%s\",\"%.2f\"\n", 
			product[z].id, product[z].description, product[z].quantity, product[z].date, product[z].price);
	}
}		


void* update_inventory(){
	
	int count = count_inventory_three();
	struct element list[1000];
	into_structure_three(list);
	
	int ID_three;
	
    int ID_check, DESC_check, QTY_check, DATE_check, PRICE_check;	
	
	int Day, Month;  
	
	float Price; 

	char addID[64], addDescription[64], addQuantity[64], addPrice[64], addMonth[64], addDay[64], addYear[64];
	
	int Quantity, ID_four;
	
	char Date[100];
	
	
	int x = 1;
	
	FILE* fp = fopen("Inventory_ST_NoBOM.csv", "r");
	 if (!fp) {
        // Error in file opening
        x = 0;
        printf("\nNo entries yet.\n\n");
        update_menu();
    }
    fclose(fp);
	
	if (x==1){
		printf("SEARCH INVENTORY \n");
	char searchID[64];
	printf("\nEnter the Inventory ID: ");
    fgets(searchID, 63, stdin);
	
	
	if ( ID_validity_checker(searchID) == 0 ){
    	printf("\nInvalid ID.\n");
		update_menu();
	}else{
		sscanf(searchID, "%d", &ID_three);
		if ( search_inventory_three(list,count,ID_three) == 1){
			update_menu();
		}else{
			
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

		
   		if ( Date_validity_checker(addMonth, addDay, addYear) == 0 ){
    		if (Expiry_date_checker(addMonth, addDay, addYear) == 1){
    			printf("\nNo Expiration.");
    			DATE_check = 1;
			}else{
				printf("\nInvalid date.");
				DATE_check = 0;
			}	
		}else{
			printf("\nValid Date.");
			DATE_check = 2;
			sscanf(addDay, "%d", &Day);
			sscanf(addMonth, "%d", &Month);
		}
	
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
		
		sscanf(addQuantity, "%d", &Quantity);
		sscanf(addID, "%d", &ID_four);
    
    	if ( ID_check == 0 || DESC_check == 0 || QTY_check == 0 || DATE_check == 0 || PRICE_check == 0){
    		update_menu();
		}else if ( ID_check == 1 && DESC_check == 1 && QTY_check == 1 && DATE_check == 1 && PRICE_check == 1){
    		printf("\nItem Updated.");
			copy_inventory(list,count,ID_three,ID_four,addDescription,Quantity,"-",Price);
			inventory_add();
		}else if ( ID_check == 1 && DESC_check == 1 && QTY_check == 1 && DATE_check == 2 && PRICE_check == 1){
    		printf("\nItem Updated.");
    		sprintf(Date, "%s-%02d-%02d", addYear, Month, Day);
			copy_inventory(list,count,ID_three,ID_four,addDescription,Quantity,Date,Price);
			inventory_add();
    	}
	}	
	}
	}
	
	
}