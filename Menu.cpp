#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void Menu();
void Menu_Choice();
void Add_Inventory();
void Add_Inventory_Choice();
void Update_Inventory();
void Update_Inventory_Choice();
void View_Item();
void View_Item_Choice();
void Search_Item();
void Search_Item_Choice();


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
    Menu_Choice();
    
}

void Menu_Choice(){
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
        		//Add_Inventory();
        		printf("\n");
       			Add_Inventory();
       			break;
    		case 'b':
      			//Update_Inventory();
        		printf("\n");
      			Update_Inventory();
        		break;
    		case 'c':
      			//View_Inventory();
      			printf("\n");
      			View_Item();
       			break;  
			case 'd':
      			//View_Inventory();
       			printf("\n");
      			Search_Item();
       			break;
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

void Add_Inventory(){
    printf("ADD INVENTORY \n");
    printf("*******************************\n");
    printf("*[A] Add Inventory Item Again *\n");
    printf("*[M] Display Main Menu Again  *\n");
    printf("*[X] Exit                     *\n");
    printf("*******************************\n\n");
    printf("Please input choice: ");
	Add_Inventory_Choice();
	
}

void Add_Inventory_Choice(){
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
        		printf("\n");
       			Add_Inventory();
       			break;
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
void Update_Inventory()      
{
    printf("UPDATE INVENTORY \n");
    printf("************************************\n");
    printf("*[B] Update Inventory Item Again   *\n");
    printf("*[M] Display Main Menu Again       *\n");
    printf("*[X] Exit                          *\n");
    printf("************************************\n\n");
    printf("Please input choice: ");
    Update_Inventory_Choice();
}
void Update_Inventory_Choice(){
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
    		case 'b':
      			//Update_Inventory();
      			printf("\n");
      			Update_Inventory();
        		break;
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
void View_Item()      
{
    printf("VIEW ITEM LIST \n");
    printf("*******************************\n");
    printf("*[C] View Item List Again     *\n");
    printf("*[M] Display Main Menu Again  *\n");
    printf("*[X] Exit                     *\n");
    printf("*******************************\n\n");
    printf("Please input choice: ");
    View_Item_Choice();
    
}

void View_Item_Choice(){
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
    		case 'c':
      			printf("\n");
      			View_Item();
       			break; 
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
void Search_Item()      
{
    printf("SEARCH ITEM\n");
    printf("*******************************\n");
    printf("*[D] Search Item              *\n");
    printf("*[M] Display Main Menu Again  *\n");
    printf("*[X] Exit                     *\n");
    printf("*******************************\n\n");
    printf("Please input choice: ");
    Search_Item_Choice();
    
}

void Search_Item_Choice(){
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
			case 'd':
      			//Search_Inventory();
      			printf("\n");
      			Search_Item();
       			break;
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