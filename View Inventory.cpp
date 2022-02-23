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

int main()
{
	struct element product[1000];
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
  			printf("id: %d ", product[row].id);
  			printf("description: %s ", product[row].description);
  			printf("quantity: %d ", product[row].quantity);
  			printf("date: %s ", product[row].date);
  			printf("price: %f ", product[row].price);
            printf("\n");
            row++;
        }
        fclose(fp);

}