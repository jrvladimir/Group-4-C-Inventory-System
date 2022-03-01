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



int count_inventory1(){
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

into_structure1(struct element product[1000]){
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


int duplicate_check(struct element product[1000], int s, int p){
	int z = 0;
	int duplicate=0;
		
		while (z < s){
			if (p == product[z].id){
				duplicate = 1;
				break;
			}
			z++;
		}
		return duplicate;
}

int* ID_duplication_checker(char userInput[64]){
    	int count = count_inventory1();
		struct element list[1000];
		into_structure1(list);
		int duplicate_output = 0;
		int num = 0;
		sscanf(userInput, "%d", &num);


		if ( duplicate_check(list,count,num) == 1){
			duplicate_output = 1;
		}
		
		
		return duplicate_output;

	}




