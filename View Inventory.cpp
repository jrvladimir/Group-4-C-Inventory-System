#include <stdio.h>
#include <conio.h>>
#include <stdlib.h>
#include <string.h>
#define DELIMITER "\";,\n"



int main()
{

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
                    printf("Inventory ID : ");
                }
  
                // Column 2
                if (column == 1) {
                    printf("\tDescription : ");
                }
  
                // Column 3
                if (column == 2) {
                    printf("\tQuantity :");
                }
                
				// Column 4
                if (column == 3) {
                    printf("\tDate :");
                }
                
				// Column 5
                if (column == 4) {
                    printf("\tPrice :");
                }
  
                printf("%s", value);
                value = strtok(NULL, DELIMITER);
                column++;
            }
  
            printf("\n");
        }
        fclose(fp);

}