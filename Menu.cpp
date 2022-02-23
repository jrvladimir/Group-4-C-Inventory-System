#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void Menu();
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
    char choice;
    printf("MAIN MENU \n");
    printf("****************************\n");
    printf("*[A] Add Inventory Item    *\n");
    printf("*[B] Update Inventory Item *\n");
    printf("*[C] View Item List        *\n");
    printf("*[D] Search Item List      *\n");
    printf("*[X] Exit                  *\n");
    printf("****************************\n\n");
    printf("Please input choice: ");
    scanf("%d", &choice); 
    while((choice = getchar())!=('x'&&'X'))
    {
        //Ignore whitespace
        choice=tolower(choice); 
        if (choice == '\n')
            continue;
        else
        {
        	switch(choice){
        		case 'a':
       				 //Add_Inventory();
       				 break;
    			case 'b':
      				 //Update_Inventory();
        			 break;
    			case 'c':
      				 //View_Inventory();
       				 break; 
				 case 'd':
      				 //View_Inventory();
       				 break;
				case 'x':
      				 printf("\n*** Thanks for using the program! Goodbye. *");
                     exit(1); 
       				 break;  
    			default:
      			     printf("\nError! Wrong Number/Character is Entered\nPlease Try Again\n\n");
        			 break;
   						 }			
		}
	}
}
