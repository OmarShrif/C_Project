/*
 * File:   main.h
 * Author: Omar Shrif Mohamed
 * https://www.linkedin.com/in/omar-shrif-982413213/
 * Created on 08, 17, 2024, 07:10 PM
 */

#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED


/* Section : Includes */

#include "item.h"

/* Section : Macro Declarations */

#define USERNAME    "user"
#define PASSWORD    "pass"

#define USERNAME_LENGTH     4
#define PASSWORD_LENGTH     4

#define WRONG       0
#define CORRECT     1

#define TRIELS      3

/* Section : Functions Declarations */
void _time(uint8 *t);
void frame(void);
void wel_come(void);
uint8 login(void);
void menu(void);


#endif // MAIN_H_INCLUDED
