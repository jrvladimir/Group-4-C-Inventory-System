#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tools.h"

int* Expiry_date_checker(char monthInput[64], char dayInput[64], char yearInput[64]){
	int expiry_output = 0;
	int day, month, year;
	
	int bilang_month, bilang_day, bilang_year;
	char number_month[64], number_day[64], number_year[64];
	int bilang_month_l, bilang_day_l, bilang_year_l;
	
	sscanf(monthInput, "%d", &bilang_month);
	sprintf(number_month, "%d", bilang_month);
	
	sscanf(dayInput, "%d", &bilang_day);
	sprintf(number_day, "%d", bilang_day);
	
	sscanf(yearInput, "%d", &bilang_year);
	sprintf(number_year, "%d", bilang_year);
	
	
	bilang_month_l = strlen(number_month) + 1;
	bilang_day_l = strlen(number_day) + 1;
	bilang_year_l = strlen(number_year) + 1;
	
	
	sscanf(monthInput, "%d", &month);
	sscanf(dayInput, "%d", &day);
	sscanf(yearInput, "%d", &year);

	if ( strlen(monthInput) != bilang_month_l || strlen(dayInput) != bilang_day_l || strlen(yearInput) != bilang_year_l){
		expiry_output = 0;
	}else{
		if( day == 0 && month == 0 && year == 0 ){
			expiry_output = 1;
		}
	}
	

	return expiry_output;		
}