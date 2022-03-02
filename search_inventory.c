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

count_inventory_two(){
	FILE* fp = fopen("Inventory_ST_NoBOM.csv", "r");
	 if (!fp) {
        // Error in file opening
        printf("Can't open file\n");
    }
	char buffer[1024];
        int row = 0;
        while (fgets(buffer,1024, fp)) {
            row++;
        }
        fclose(fp);
        return row;
}

into_structure_two(struct element product[1000]){
	FILE* fp = fopen("Inventory_ST_NoBOM.csv", "r");
	 if (!fp) {
        // Error in file opening
        printf("Can't open file\n");
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


search_inventory_two(struct element product[1000], int s, int ID){
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
			printf("\n\n\nITEM FOUND!");
			break;
			} 
		
			 
	}
	if (z == false)
			{
				printf("\nItem ID %d does not exist!\n ", ID);
			}
		
}		


void* search_inventory(){
	
	int count = count_inventory_two();
	struct element list[1000];
	into_structure_two(list);
	
	printf("SEARCH INVENTORY \n");
	char addID[64];
	printf("\nEnter the Inventory ID: ");
    fgets(addID, 63, stdin);
	
	int ID_two;
	
	if ( ID_validity_checker(addID) == 0 ){
    	printf("Invalid ID.");
    	printf("SEARCH INVENTORY\n");
    	printf("*******************************\n");
    	printf("*[D] Search Inventory Again   *\n");
    	printf("*[M] Display Main Menu Again  *\n");
    	printf("*[X] Exit                     *\n");
    	printf("*******************************\n\n");
    	printf("Please input choice: ");
    	int module = 4;
    	choice(module);	
	}else{
		sscanf(addID, "%d", &ID_two);
		search_inventory_two(list,count,ID_two);
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
	

}