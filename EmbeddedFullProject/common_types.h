/*
 * common_types.h
 *
 * Created: 2/2/2022 10:05:57 AM
 *  Author: NourhanAlrefaei
 */ 

#ifndef COMMON_TYPES_H_
#define COMMON_TYPES_H_

#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#define TRUE					(1)
#define FALSE					(0)
#define NULL_POINTER			((void*) 0)
#define  ZERO_INIT              (0)

typedef unsigned char			bool_type;
typedef signed char 			sint8_type;
typedef unsigned char 			uint8_type;
typedef signed short 			sint16_type;
typedef unsigned short 			uint16_type;
typedef signed int 				sint32_type;
typedef unsigned int 			uint32_type;
typedef float 					float32_type;
typedef double 					float64_type;

typedef unsigned char*			ptr_bool_type;
typedef signed char* 			ptr_sint8_type;
typedef unsigned char* 			ptr_uint8_type;
typedef signed short* 			ptr_sint16_type;
typedef unsigned short* 		ptr_uint16_type;
typedef signed int* 			ptr_sint32_type;
typedef unsigned int* 			ptr_uint32_type;
typedef float*					ptr_float32_type;
typedef double* 				ptr_float64_type;

typedef enum{
	R_NOK,
	R_OK
}ret_status;

#endif /* COMMON_TYPES_H_ */