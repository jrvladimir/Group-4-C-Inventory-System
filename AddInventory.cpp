#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct element{
    char description[100], id[100], quantity[100];
	char date[100], price[100];
	int day;
	int month;
	int year;
}product;

int main(void)
{
	struct element inventory;
    FILE* fp = fopen("Inventory_ST_NoBOM.csv", "a+");
    int num_id = -1,num_quantity = 0, 
	i, j, flagquantity = 0, flagprice = 0, valid = 0, leap_year = 0;
	float num_price = -1;
    char addID[64], addQuantity[64], addPrice[64], addMonth[64], addDay[64], addYear[64];
    
// Error in file opening
    if (!fp) {
		
		printf("Can't open file\n");
	}
// Asking user input for the
// new record to be added
	printf("Add Inventory\n");
	printf("New Inventory Information\n");

//Product ID
    while( num_id == -1)
	{
		printf("\nEnter the Inventory ID: ");
		fgets(addID, 63, stdin);
				
		if( strlen(addID) != 6 ){
			//only accepts 5 digit integers and then null 
			printf("Invalid input.\n");
			continue;
		}
		
		if ( sscanf(addID, "%d", &num_id) != 1 ){
			num_id = -1;
			//does not accept other data types
			printf("Invalid input.\n");
			continue;
		}
		if ( num_id < 0 || num_id > 99999 ){
			num_id = -1;
			printf("Invalid input.\n");
			continue;
		}
		else if ( num_id >= 0 && num_id <= 9){
			sprintf(inventory.id, "0000%d", num_id);	
		}
		else if ( num_id >= 10 && num_id <= 99){
			sprintf(inventory.id, "000%d", num_id);
	
		}
		else if ( num_id >= 100 && num_id <= 999){
			sprintf(inventory.id, "00%d", num_id);
		}
		else if ( num_id >= 1000 && num_id <= 9999){
			sprintf(inventory.id, "0%d", num_id);
		}
		else{
			sprintf(product.id, "%d", num_id);
		}
	}

//Description 
	printf("\nEnter the Description: ");
    fflush(stdin);
    fgets(product.description,100,stdin);

    for(int x=0 ; x<100 ; x++)
    {
    if(product.description[x] == '\n')
        product.description[x] = '\0';
    }
    
//Quantity  
    while( num_quantity == 0)
	{
	printf("\nEnter the Quantity of the Product: ");
	fgets(addQuantity, 63, stdin);
		
		if( strlen(addQuantity) < 2 || strlen(addQuantity) > 8 ){
			//doesn't accept empty input or greater than 7 digits
			printf("Invalid input.\n");
			continue;
		}
		
		if ( sscanf(addQuantity, "%d", &num_quantity) != 1 ){
			num_quantity = 0;
			//does not accept other data types
			printf("Invalid input.\n");
			continue;
		}
		
		//checks if the input is float
		while (addQuantity[i++] != '\0'){
			if (addQuantity[i] == '.'){
				flagquantity = 1;
				break;
			}
		}
		
		if ( num_quantity < 1 || num_quantity > 1000000 || flagquantity == 1 ){
			num_quantity = 0;
			flagquantity = 0;
			printf("Invalid input.\n");
			continue;
		}else{
			sprintf(product.quantity, "%d", num_quantity);
		}

	}
		
//Expiration Date	
	while (valid == 0) {
		printf("\nEnter the Expiry Date of the Product:");
		printf("\t\nEnter the Month:");
		fgets(addMonth, 63, stdin);
		printf("\t\nEnter the Day:");
		fgets(addDay, 63, stdin);
		printf("\t\nEnter the Year:");
		fgets(addYear, 63, stdin);
				
		if(strlen(addMonth) < 2 || strlen(addMonth) > 3 ){
			//only accepts 1 & 2 digit integers and then null
			printf("Invalid input.\n");
			continue;
		}
		
		if(strlen(addDay) < 2 || strlen(addDay) > 3 ){
			//only accepts 1 & 2 digit integers and then null 
			printf("Invalid input.\n");
			continue;
		}
		
		if(strlen(addYear) < 2 || strlen(addYear) > 5 ){
			//only accepts 1 & 2 digit integers and then null 
			printf("Invalid input.\n");
			continue;
		}		
		
		if (sscanf(addMonth, "%d", &product.month) != 1 ){
			//does not accept other data types
			printf("Invalid input.\n"); 
			continue;
		}
		
		if (sscanf(addDay, "%d", &product.day) != 1 ){
			//does not accept other data types
			printf("Invalid input.\n");
			continue;
		}
		
		if (sscanf(addYear, "%d", &product.year) != 1 ){
			//does not accept other data types
			printf("Invalid input.\n");
			continue;
		}
		
		if(product.year % 4 == 0) {
			if( product.year % 100 == 0) {
				if ( product.year % 400 == 0) {
					leap_year = 1;
				}else{
				}
			}else {
				leap_year = 1;
			}
		}else {
		}
		
		if (product.month < 1 || product.month > 12 || product.day < 1 || product.day > 31 || product.year < 2021){
			printf("Invalid input.\n");
			continue;
		}else if( (product.day > 29) && (product.month = 2) ){
			printf("Invalid input.\n");
			continue;
		}else if( (product.day > 30) && (product.month = 4, 6, 9, 11) ){
			printf("Invalid input.\n");
			continue;
		}else if(product.day == 29 && product.month == 2 && leap_year == 0 )
		{
			printf("Invalid input.\n");
			continue;	
		}
		else
		{
			sprintf(product.date, "%d-%02d-%02d", product.year, product.month, product.day);
			printf("%s", product.date);
			valid = 1;
		}
	}
	
//Price 	
	while (num_price == -1) 
	{
	printf("\nEnter the Price: ");
	fgets(addPrice, 63, stdin);
		
		if( strlen(addPrice) < 2 || strlen(addPrice) > 11 )
		{
			//doesn't accept empty input or greater than 10 digits
			printf("Invalid input.\n");
			continue;
		}

		//checks if the input is .2 float
		while (addPrice[j++] != '\0'){
			if (addPrice[j] == '.'){
				if ( ( strlen(addPrice) - j) > 4 ){
					flagprice = 1;
					break;
				}
			}
		}
		
		if ( sscanf(addPrice, "%f", &num_price) != 1 )
		{
			num_price = -1;
			//does not accept other data types
			printf("Invalid input!\n");
			continue;
		}	
		

		if ( num_price <= 0 || num_price > 1000000 || flagprice == 1 )
		{
			num_price = -1;
			flagprice = 0;
			printf("Invalid input price.\n");
			continue;
		}
		else
		{
			sprintf(product.price, "%.2f", num_price);
		}
	}

//Saving data on CSV File
	fprintf(fp, "\n%s, %s, %s, %s, %s",
			product.id,product.description,product.quantity,product.date, product.price);

	printf("\nNew Account added to record");
	fclose(fp);	
}

