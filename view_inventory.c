#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define DELIMITER "\";,\n"
#include <ctype.h>
#include "tools.h"

struct element{
    int id;
    char description[100];
    int quantity;
    char date[100];
    float price;
};

int count_inventory(){
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

into_structure(struct element product[1000]){
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
	return 0;
}

display_inventory(struct element product[1000], int s){
	int i;
	printf("VIEW INVENTORY\n");
	printf("ID     DESCRIPTION                      QTY    DATE          PRICE\n");
	
    for (i = 0; i < s; i++)
    {
        printf("%05d", product[i].id);
  		printf("  %s", product[i].description);
  		printf("   %d", product[i].quantity);
  		if (product[i].quantity < 10){
  			printf("   ");
		}else if (product[i].quantity < 100){
  			printf("  ");
		}else if (product[i].quantity < 1000){
  			printf(" ");
		}
  		printf("   %s", product[i].date);
  		if (strlen(product[i].date) < 3){
  			printf("         ");
		}
  		printf("    %.2f", product[i].price);
        printf("\n\n");  
    } 
	return 0;
}

sort_inventory(struct element product[1000], int s)
{
    int i, j;
    struct element temp;
    
    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1-i); j++)
        {
            if (product[j].id > product[j + 1].id)
            {
                temp = product[j];
                product[j] = product[j + 1];
                product[j + 1] = temp;
            } 
        }
    }
    return 0;
}

void* view_inventory(){
	FILE* fp = fopen("Inventory_ST_NoBOM.csv", "r");
	if (!fp) {
        // Error in file opening
        printf("File is not available\n\n");
        printf("VIEW INVENTORY\n");
    	printf("*******************************\n");
   		printf("*[C] View Inventory Again     *\n");
    	printf("*[M] Display Main Menu Again  *\n");
    	printf("*[X] Exit                     *\n");
    	printf("*******************************\n\n");
   		printf("Please input choice: ");
    	int module = 3;
    	choice(module);
    }else{
    	int count = count_inventory();
		struct element list[1000];
		into_structure(list);
		sort_inventory(list,count);
		display_inventory(list,count);
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
}



