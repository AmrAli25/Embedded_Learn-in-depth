/*
 * lifo.h
 *
 *  Created on: Jun 27, 2023
 *      Author: AmrAli
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "stdio.h"
#include "stdlib.h"

//type definitions
typedef struct {
	unsigned int length;
	unsigned int count;
	unsigned int* base;
	unsigned int* head;
} LIFO_Buf_t;

typedef enum {
	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFO_EMPTY,
	LIFO_ERROR,
	LIFO_NULL
}LIFO_Status;


//APIs
LIFO_Status LIFO_Add_Item(LIFO_Buf_t* lifo_buf, unsigned int item);
LIFO_Status LIFO_Get_Item(LIFO_Buf_t* lifo_buf, unsigned int* item);
LIFO_Status LIFO_Init(LIFO_Buf_t* lifo_buf, unsigned int* buf, unsigned int length);


#endif /* LIFO_H_ */
