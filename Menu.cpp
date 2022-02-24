#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



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
    printf("VIEW ITEM LIST \n");
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

