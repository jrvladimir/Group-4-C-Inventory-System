#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tools.h"

int* Description_validity_checker(char userInput[64]){
	int description_output = 0;
	
	if ( strlen(userInput) < 2 || strlen(userInput) > 30 ){
		description_output = 0;
	}else if (userInput[0] == ' '){
		description_output = 0;
	}else{
		description_output = 1;
	}
	return description_output;
}
	
	
	
	
	
	
	
	
