/*
 * File:   std_types.h
 * Author: Omar Shrif Mohamed
 * https://www.linkedin.com/in/omar-shrif-982413213/
 * Created on 08, 17, 2024, 07:12 PM
 */

#ifndef _STD_TYPES_H
#define	_STD_TYPES_H

/* Section : Includes */

/* Section : Data Type Declarations */
typedef unsigned char   uint8   ;
typedef unsigned short  uint16  ;
typedef unsigned long   uint32  ;

typedef signed char     sint8   ;
typedef signed short    sint16  ;
typedef signed long     sint32  ;

typedef float           float32 ;
typedef double          float64 ;

typedef enum
{
    R_NOK,
    R_OK
} Std_ReturnType;

/* Section : Macro Declarations */

#define ENTER   (uint8)13
#define SPACE   (uint8)32

/* Section : Macro Functions Declarations */

/* Section : Functions Declarations */

#endif	/* _STD_TYPES_H */

