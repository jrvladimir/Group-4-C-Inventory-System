#include "stdio.h"
#include "string.h"

int main(){
	char userInput[64];
	int num = 0;
	
	while (num == 0) {
		printf("Inventory ID (Enter a five digit interger):");
		fgets(userInput, 63, stdin);
				
		if( strlen(userInput) != 6 ){
			//only accepts 5 digit integers and then null 
			printf("Invalid input.\n");
			continue;
		}
		
		if ( sscanf(userInput, "%d", &num) != 1 ){
			num = 0;
			//does not accept other data types
			printf("Invalid input.\n");
			continue;
		}
		
		if ( num < 10000 || num > 99999 ){
			num = 0;
			printf("Invalid input.\n");
			continue;
		}else{
			printf("Valid Inventory ID:%d", num);
		}
	}
	
	return 0;	
}