#include <stdio.h>
#include <conio.h>>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
	printf("VIEW INVENTORY\n");
	printf("ID     DESCRIPTION                      QTY    DATE          PRICE\n");
	
    for (i = 0; i < s; i++)
    {
        printf("%d", product[i].id);
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

void Menu();
void Add_Inventory();
void Update_Inventory();
void View_Item();
void Search_Item();

void Choice(int mod){
	char choice;
    char userInput[64];
    while ( choice != 'x'){  	
    	fgets(userInput, 63, stdin);
    	if(strlen(userInput) != 2){
    		printf("\nError! Wrong Number/Character is Entered\nPlease Try Again\n\n");
    		printf("Please input choice: ");
    		continue;
		}
    	if (sscanf(userInput, "%c", &choice) != 1){
    		printf("\nError! Wrong Number/Character is Entered\nPlease Try Again\n\n");
    		printf("Please input choice: ");
    		continue;
		}
		choice=tolower(choice); 
    	switch(choice){
        	case 'a':
        		if (mod == 0 || mod == 1){
        			//Add_Inventory();
        			printf("\n");
       				Add_Inventory();
       				break;
				}else{
					printf("\nError! Wrong Number/Character is Entered\nPlease Try Again\n\n");
      				printf("Please input choice: ");
					continue;
				}
    		case 'b':
    			if (mod == 0 || mod == 2){
      				//Update_Inventory();
        			printf("\n");
      				Update_Inventory();
        			break;
        		}else{
        			printf("\nError! Wrong Number/Character is Entered\nPlease Try Again\n\n");
      				printf("Please input choice: ");
					continue;
				}
    		case 'c':
    			if (mod == 0 || mod == 3){
      				//View_Inventory();
      				printf("\n");
      				View_Item();
       				break;  
       			}else{
       				printf("\nError! Wrong Number/Character is Entered\nPlease Try Again\n\n");
      				printf("Please input choice: ");
					continue;
				}	
			case 'd':
				if (mod == 0 || mod == 4){
      				//Search_Inventory();
       				printf("\n");
      				Search_Item();
       				break;
       			}else{
       				printf("\nError! Wrong Number/Character is Entered\nPlease Try Again\n\n");
      				printf("Please input choice: ");
					continue;
				}
       		case 'm':
      			//Menu();
      			printf("\n");
      			Menu();
       			break;
			case 'x':
      			printf("\n*** Thanks for using the program! Goodbye. *");
                exit(1); 
       			break;  
    		default:
      			printf("\nError! Wrong Number/Character is Entered\nPlease Try Again\n\n");
      			printf("Please input choice: ");
        		continue;
   		}
	}
}

int main()
{
    int a;
    for(a=0;;a++){
       Menu();
    }
    return 0;
}
void Menu()      
{
    printf("MAIN MENU \n");
    printf("*******************************\n");
    printf("*[A] Add Inventory Item       *\n");
    printf("*[B] Update Inventory Item    *\n");
    printf("*[C] View Item List           *\n");
    printf("*[D] Search Item List         *\n");
    printf("*[M] Display Main Menu Again  *\n");
    printf("*[X] Exit                     *\n");
    printf("*******************************\n\n");
    printf("Please input choice: ");
    int module = 0;
    Choice(module);
}
void Add_Inventory(){
    printf("ADD INVENTORY \n");
    printf("*******************************\n");
    printf("*[A] Add Inventory Item Again *\n");
    printf("*[M] Display Main Menu Again  *\n");
    printf("*[X] Exit                     *\n");
    printf("*******************************\n\n");
    printf("Please input choice: ");
    int module = 1;
	Choice(module);	
}
void Update_Inventory()      
{
    printf("UPDATE INVENTORY \n");
    printf("************************************\n");
    printf("*[B] Update Inventory Item Again   *\n");
    printf("*[M] Display Main Menu Again       *\n");
    printf("*[X] Exit                          *\n");
    printf("************************************\n\n");
    printf("Please input choice: ");
    int module = 2;
    Choice(module);
}
void View_Item()      
{
	FILE* fp = fopen("Inventory_ST_NoBOM.csv", "r");
	if (!fp) {
        // Error in file opening
        printf("File is not available\n");
    }else{
    	int count = count_inventory();
		struct element list[1000];
		into_structure(list);
		sort_inventory(list,count);
		display_inventory(list,count);
	}
    printf("VIEW INVENTORY \n");
    printf("*******************************\n");
    printf("*[C] View Item List Again     *\n");
    printf("*[M] Display Main Menu Again  *\n");
    printf("*[X] Exit                     *\n");
    printf("*******************************\n\n");
    printf("Please input choice: ");
    int module = 3;
    Choice(module);
}
void Search_Item()      
{
    printf("SEARCH ITEM\n");
    printf("*******************************\n");
    printf("*[D] Search Item              *\n");
    printf("*[M] Display Main Menu Again  *\n");
    printf("*[X] Exit                     *\n");
    printf("*******************************\n\n");
    printf("Please input choice: ");
    int module = 4;
    Choice(module);
}