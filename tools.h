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