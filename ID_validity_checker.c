#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tools.h"

int* ID_validity_checker(char userInput[64]){
	int num = -1;
	int ID_output = 0;
	int flag = 0;
	int y = 0;


	while (userInput[y++] != '\0'){
		if ( (userInput[y] >= '!' && userInput[y] == '/') || (userInput[y] >= ':' && userInput[y] <= '~' )){
			flag = 1;
			break;
		}
	}
	

	if( strlen(userInput) != 6 ){
		//only accepts 5 digit integers and then null 
		ID_output = 0;
	}else if ( flag == 1){
	    ID_output = 0;
	}else if ( sscanf(userInput, "%d", &num) != 1 ){
		//does not accept other data types
		ID_output = 0;
	}else if ( num < 0 || num > 99999 ){
		ID_output = 0;
	}else{
		ID_output = 1;
	}			
		
	return ID_output;	
}