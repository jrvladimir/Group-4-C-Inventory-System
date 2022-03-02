#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void* choice(int mod);
void* menu();
void* add_inventory();
void* update_inventory();
void* view_inventory();
void* search_inventory();
int* Quantity_validity_checker(char userInput[64]);
int* Price_validity_checker(char PriceInput[64]);
int* Date_validity_checker(char monthInput[64], char dayInput[64], char yearInput[64]);
int* Expiry_date_checker(char monthInput[64], char dayInput[64], char yearInput[64]);
int* ID_validity_checker(char userInput[64]);
int* Description_validity_checker(char userInput[64]);
int* ID_duplication_checker(char userInput[64]);
