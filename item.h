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
    uint8  productname[40],productcomp[40],c;
    uint32 productid;
    uint32 price;
    uint32 Qnt;
}NewItem;

extern FILE *new_data;
extern FILE *current_data;

/* Section : Macro Declarations */

#define _new        "new_data.txt"
#define _current    "current_data.txt"

/* Section : Macro Functions Declarations */

/* Section : Functions Declarations */

void add_item(void);
void delete_item(void);
void edit_item(void);
void search_item(void);
void items_list(void);

void gotoxy(uint8 x,uint8 y);

#endif // ITEM_H_INCLUDED
