#include "stdio.h"
#include "string.h"

int main(){
	char monthInput[64];
	int month = 0;
	char dayInput[64];
	int day = 0;
	char yearInput[64];
	int year = 0;
	int leap_year = 0;
	char date[100];
	int valid = 0;
	
	while (valid == 0) {
		printf("Month:");
		fgets(monthInput, 63, stdin);
		printf("Day:");
		fgets(dayInput, 63, stdin);
		printf("Year:");
		fgets(yearInput, 63, stdin);
				
		if( strlen(monthInput) < 2 || strlen(monthInput) > 3 ){
			//only accepts 1 & 2 digit integers and then null
			printf("Invalid input.\n");
			continue;
		}
		
		if( strlen(dayInput) < 2 || strlen(dayInput) > 3 ){
			//only accepts 1 & 2 digit integers and then null 
			printf("Invalid input.\n");
			continue;
		}
		
		if( strlen(yearInput) < 2 || strlen(yearInput) > 5 ){
			//only accepts 1 & 2 digit integers and then null 
			printf("Invalid input.\n");
			continue;
		}		
		
		if ( sscanf(monthInput, "%d", &month) != 1 ){
			//does not accept other data types
			printf("Invalid input.\n"); 
			continue;
		}
		
		if ( sscanf(dayInput, "%d", &day) != 1 ){
			//does not accept other data types
			printf("Invalid input.\n");
			continue;
		}
		
		if ( sscanf(yearInput, "%d", &year) != 1 ){
			//does not accept other data types
			printf("Invalid input.\n");
			continue;
		}
		
		if(year % 4 == 0) {
			if( year % 100 == 0) {
				if ( year % 400 == 0) {
					leap_year = 1;
				}else{
				}
			}else {
				leap_year = 1;
			}
		}else {
		}
		
		if ( month < 1 || month > 12 || day < 1 || day > 31 || year < 2021){
			printf("Invalid input.\n");
			continue;
		}else if( (day > 29) && (month = 2) ){
			printf("Invalid input.\n");
			continue;
		}else if( (day > 30) && (month = 4, 6, 9, 11) ){
			printf("Invalid input.\n");
			continue;
		}else if( day == 29 && month == 2 && leap_year == 0 ){
			printf("Invalid input.\n");
			continue;	
		}else{
			sprintf(date, "%d-%d-%d", year, month, day);
			printf("%s", date);
			valid = 1;
		}
	}
	return 0;	
}