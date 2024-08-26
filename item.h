/*
 * File:   item.h
 * Author: Omar Shrif Mohamed
 * https://www.linkedin.com/in/omar-shrif-982413213/
 * Created on 08, 17, 2024, 07:24 PM
 */

#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

/* Section : Includes */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>

#include "std_types.h"

/* Section : Data Type Declarations */

typedef struct
{
    uint8 name[18];
    uint8 company[18];
    uint8 id[10];
    uint32 price;
    uint32 quantity;
}NewItem;

extern FILE *new_data;
extern FILE *current_data;

/* Section : Macro Declarations */

#define _new        "new_data.txt"
#define _current    "current_data.txt"

#define NOT_FOUND   0
#define FOUND       1

/* Section : Macro Functions Declarations */

/* Section : Functions Declarations */

uint8 add_item(void (*fram)(void));
void delete_item(void (*fram)(void));
void edit_item(void (*fram)(void));
void search_item(void (*fram)(void));
void items_list(void (*fram)(void));

void gotoxy(uint8 x,uint8 y);

#endif // ITEM_H_INCLUDED
