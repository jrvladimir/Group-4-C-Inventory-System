#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tools.h"

int* Quantity_validity_checker(char userInput[64]){
	int num = -1;
	int i, flag = 0;
	int quantity_output = 0;
	
	//checks if the input is float
	while (userInput[i++] != '\0'){
		if (userInput[i] == '.'){
			flag = 1;
			break;
		}
	}
	
	int bilang;
	char number[64];
	sscanf(userInput, "%d", &bilang);
	sprintf(number, "%d", bilang);
	int bilang_l;
	bilang_l = strlen(number) + 1;

	
	if( strlen(userInput) < 2 || strlen(userInput) > 8 ){
		//doesn't accept empty input or greater than 7 digits
		quantity_output = 0;
	}else if ( strlen(userInput) != bilang_l){
	    quantity_output = 0;	
	}else if ( sscanf(userInput, "%d", &num ) != 1 ){
		//does not accept other data types
		quantity_output = 0;
	}else if ( num < 0 || num > 30000 || flag == 1 ){
		quantity_output = 0;
	}else{
		quantity_output = 1;
		}
	return quantity_output;		
}			
	
