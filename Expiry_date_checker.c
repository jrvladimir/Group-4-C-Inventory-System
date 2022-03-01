#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tools.h"

int* Expiry_date_checker(char monthInput[64], char dayInput[64], char yearInput[64]){
	int expiry_output = 0;
	int day, month, year;
	sscanf(monthInput, "%d", &month);
	sscanf(dayInput, "%d", &day);
	sscanf(yearInput, "%d", &year);

	if( day == 0 && month == 0 && year == 0 ){
		expiry_output = 1;
	}else{
	}	
	return expiry_output;		
}