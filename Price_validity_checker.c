#include "stdio.h"
#include "string.h"

int main(){
	char userInput[64];
	float num = -1;
	int i, flag = 0;
	
	while (num == -1) {
		printf("Enter Quantity:");
		fgets(userInput, 63, stdin);
		
		if( strlen(userInput) < 2 || strlen(userInput) > 11 ){
			//doesn't accept empty input or greater than 10 digits
			printf("Invalid input.\n");
			continue;
		}

		//checks if the input is .2 float
		while (userInput[i++] != '\0'){
			if (userInput[i] == '.'){
				if ( ( strlen(userInput) - i) > 4 ){
					flag = 1;
					break;
				}
			}
		}
		
		if ( sscanf(userInput, "%f", &num) != 1 ){
			num = -1;
			//does not accept other data types
			printf("Invalid input.\n");
			continue;
		}	
		

		if ( num <= 0 || num > 1000000 || flag == 1 ){
			num = -1;
			flag = 0;
			printf("Invalid input.\n");
			continue;
		}else{
			printf("Valid Quantity:%.2f", num);
		}
	}
	
	return 0;	
}