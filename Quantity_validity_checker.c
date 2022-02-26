#include "stdio.h"
#include "string.h"

int main(){
	char userInput[64];
	int num = 0;
	int i, flag = 0;
	
	while (num == 0) {
		printf("Enter Quantity:");
		fgets(userInput, 63, stdin);
		
		if( strlen(userInput) < 2 || strlen(userInput) > 8 ){
			//doesn't accept empty input or greater than 7 digits
			printf("Invalid input.\n");
			continue;
		}
		
		if ( sscanf(userInput, "%d", &num) != 1 ){
			num = 0;
			//does not accept other data types
			printf("Invalid input.\n");
			continue;
		}
		
		
		
		while (userInput[i++] != '\0'){
			if (userInput[i] == '.'){
				flag = 1;
				break;
			}
		}
			
		
		if ( num < 1 || num > 1000000 || flag == 1 ){
			num = 0;
			printf("Invalid input.\n");
			continue;
		}else{
			printf("Valid Quantity:%d", num);
		}
	}
	
	return 0;	
}