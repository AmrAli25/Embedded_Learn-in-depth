/*
 * fifo.h
 *
 *  Created on: Jun 27, 2023
 *      Author: AmrAli
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

// User configuration
// select the element type EX(uint8_t, uint16_t, uint32_t,.........)

#define element_type	uint8_t
// How to create buffer 1
#define width	5
element_type buffer1[width];

// FIFO data types

typedef struct{
	uint32_t length;
	uint32_t count;
	element_type* head;
	element_type* tail;
	element_type* base;
}FIFO_Buf_t;

typedef enum{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_NULL,
	FIFO_ERROR,
	FIFO_EMPTY
}FIFO_Buf_Status;

//FIFO APIs

FIFO_Buf_Status FIFO_Init(FIFO_Buf_t* fifo, element_type* buf, uint32_t length);
FIFO_Buf_Status FIFO_Enqueue(FIFO_Buf_t* fifo, element_type item);
FIFO_Buf_Status FIFO_Dequeue(FIFO_Buf_t* fifo, element_type* item);
FIFO_Buf_Status FIFO_Is_Full(FIFO_Buf_t* fifo);
void FIFO_Print(FIFO_Buf_t* fifo);





#endif /* FIFO_H_ */
