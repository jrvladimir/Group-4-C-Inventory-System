#include <stdio.h>
#include <conio.h>>
#include <stdlib.h>
#include <string.h>
#define DELIMITER "\";,\n"
#define true 0
#define false 1

struct element{
    int id;
    char description[100];
    int quantity;
    char date[100];
    float price;
};

count_inventory(){
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

}
int checkID(){
	char userInput[64];
	int num = -1;
	char inventory_id[64];
	
	while (num == -1) {
		printf("Inventory ID (Enter a five digit interger):");
		fgets(userInput, 63, stdin);
				
		if( strlen(userInput) != 6 ){
			//only accepts 5 digit integers and then null 
			printf("Invalid input.\n");
			continue;
		}
		
		if ( sscanf(userInput, "%d", &num) != 1 ){
			num = -1;
			//does not accept other data types
			printf("Invalid input.\n");
			continue;
		}
		
		if ( num < 0 || num > 99999 ){
			num = -1;
			printf("Invalid input.\n");
			continue;
		}
	}
	

}

search_inventory(struct element product[1000], int s){
	int i,ID;
	
	int z = false;
	printf("\t\t\t\t\t\tSEARCH ITEM\n\n");
	ID = checkID();
	
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


 

int main()
{
	int count = count_inventory();
	struct element list[1000];
	into_structure(list);
	//sort_inventory(list,count);
	//display_inventory(list,count);
	search_inventory(list,count);
}
