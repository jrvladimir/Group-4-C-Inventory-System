#include "stdio.h"
#include "string.h"

int main(){
	char userInput[64];
	int num = -1;
	char inventory_id[64];
	
	while (num == -1) {
		printf("Inventory ID (Enter a five digit interger):");
		fgets(userInput, 63, stdin);
				
		if( strlen(userInput) != 6 ){
			//only accepts 5 digit integers and then null 
			printf("Invalid input.\n");
			continue;
		}
		
		if ( sscanf(userInput, "%d", &num) != 1 ){
			num = -1;
			//does not accept other data types
			printf("Invalid input.\n");
			continue;
		}
		
		if ( num < 0 || num > 99999 ){
			num = -1;
			printf("Invalid input.\n");
			continue;
		}else if ( num >= 0 && num <= 9){
			sprintf(inventory_id, "0000%d", num);
			printf("Valid Inventory ID:%s", inventory_id);
		}else if ( num >= 10 && num <= 99){
			sprintf(inventory_id, "000%d", num);
			printf("Valid Inventory ID:%s", inventory_id);	
		}else if ( num >= 100 && num <= 999){
			sprintf(inventory_id, "00%d", num);
			printf("Valid Inventory ID:%s", inventory_id);
		}else if ( num >= 1000 && num <= 9999){
			sprintf(inventory_id, "0%d", num);
			printf("Valid Inventory ID:%s", inventory_id);
		}else{
			sprintf(inventory_id, "%d", num);
			printf("Valid Inventory ID:%s", inventory_id);
		}
	}
	
	return 0;	
}