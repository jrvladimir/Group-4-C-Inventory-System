#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tools.h"

int* Date_validity_checker(char monthInput[64], char dayInput[64], char yearInput[64]){
	int date_output;
	int day, month, year;
	int leap_year, year_leap = 0;

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




	sscanf(yearInput, "%d", &year_leap);
	if(year_leap % 4 == 0) {
		if( year_leap % 100 == 0) {
			if ( year_leap % 400 == 0) {
				leap_year = 1;
			}else{
			}
		}else {
			leap_year = 1;
	}
	}
	
	if( strlen(monthInput) < 2 || strlen(monthInput) > 3 ){
		//only accepts 1 & 2 digit integers and then null
		date_output = 0;
	}else if( strlen(dayInput) < 2 || strlen(dayInput) > 3 ){
		//only accepts 1 & 2 digit integers and then null 
		date_output = 0;
	}else if( strlen(yearInput) < 2 || strlen(yearInput) > 5 ){
		//only accepts 4 digit integers and then null 
		date_output = 0;
	}else if ( strlen(monthInput) != bilang_month_l){
	    date_output = 0;
	}else if ( strlen(dayInput) != bilang_day_l){
	    date_output = 0;
	}else if ( strlen(yearInput) != bilang_year_l){
	    date_output = 0;
	}else if ( sscanf(monthInput, "%02d", &month) != 1 ){
		//does not accept other data types
		date_output = 0;
	}else if ( sscanf(dayInput, "%02d", &day) != 1 ){
		//does not accept other data types
		date_output = 0;
	}else if ( sscanf(yearInput, "%d", &year) != 1 ){
		//does not accept other data types
		date_output = 0;
	}else if ( (month < 1) || (month > 12) || (day < 1) || (day > 31) || (year < 2021) ){
		date_output = 0;
	}else if( (day > 29) && (month == 2) ){
		date_output = 0;
	}else if( (day > 30) && (month == 4, 6, 9, 11) ){
		date_output = 0;
	}else if( day == 29 && month == 2 && leap_year == 0 ){
		date_output = 0;
	}else{
		date_output = 1;
	}
	return date_output;		
}
