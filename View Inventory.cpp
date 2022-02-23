#include <stdio.h>
#include <conio.h>>
#include <stdlib.h>
#include <string.h>
#define DELIMITER "\";,\n"

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

display_inventory(struct element product[1000], int s){
	int i;
    for (i = 0; i < s; i++)
    {
        printf("id: %d ", product[i].id);
  		printf("description: %s ", product[i].description);
  		printf("quantity: %d ", product[i].quantity);
  		printf("date: %s ", product[i].date);
  		printf("price: %f ", product[i].price);
        printf("\n");  
    } 

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
}


int main()
{
	int count = count_inventory();
	struct element list[1000];
	into_structure(list);
	sort_inventory(list,count);
	display_inventory(list,count);
}