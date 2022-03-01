#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tools.h"

int* Price_validity_checker(char PriceInput[64]){
	float num = 0;
	int z, flag = 0;
	int price_output;
	
	//checks if the input is .2 float
	while (PriceInput[z++] != '\0'){
		if (PriceInput[z] == '.'){
			if ( ( strlen(PriceInput) - z) > 4 ){
				flag = 1;
				break;
			}
		}
	}
	
	if( strlen(PriceInput) < 2 || strlen(PriceInput) > 11 ){
			//doesn't accept empty input or greater than 10 digits
			price_output = 0;
	}else if ( sscanf(PriceInput, "%f", &num ) != 1 ){
		//does not accept other data types
		price_output = 0;
	}else if ( num <= 0 || num > 1000000 || flag == 1 ){
		price_output = 0;
	}else{
		price_output = 1;
	}
	return price_output;		
}