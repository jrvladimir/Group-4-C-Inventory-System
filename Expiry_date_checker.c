#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tools.h"

int* Expiry_date_checker(char monthInput[64], char dayInput[64], char yearInput[64]){
	int expiry_output = 0;
	int day, month, year;
	
	int y = 0; 
	int flag = 0;


	while (yearInput[y++] != '\0'){
		if ( (monthInput[y] >= '!' && monthInput[y] == '/') || (monthInput[y] >= ':' && monthInput[y] <= '~' )){
			flag = 1;
			break;
		}
		if ( (dayInput[y] >= '!' && dayInput[y] == '/') || (dayInput[y] >= ':' && dayInput[y] <= '~' )){
			flag = 1;
			break;
		}
		if ( (yearInput[y] >= '!' && yearInput[y] == '/') || (yearInput[y] >= ':' && yearInput[y] <= '~' )){
			flag = 1;
			break;
		}
	}
	
	
	sscanf(monthInput, "%d", &month);
	sscanf(dayInput, "%d", &day);
	sscanf(yearInput, "%d", &year);

	if ( flag == 1 ){
		expiry_output = 0;
	}else{
		if( day == 0 && month == 0 && year == 0 ){
			expiry_output = 1;
		}
	}
	

	return expiry_output;		
}