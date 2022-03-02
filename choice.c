#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tools.h"

void* choice(int mod){
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
       				add_inventory();
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
      				update_inventory();
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
      				view_inventory();
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
      				search_inventory();
       				break;
       			}else{
       				printf("\nError! Wrong Number/Character is Entered\nPlease Try Again\n\n");
      				printf("Please input choice: ");
					continue;
				}
       		case 'm':
       			if (mod != 6){
      				//Menu();
      				printf("\n");
      				menu();
       				break;
       			}else{
       				printf("\nError! Wrong Number/Character is Entered\nPlease Try Again\n\n");
      				printf("Please input choice: ");
					continue;
				}
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