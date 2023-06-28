/*
 * fifo.c
 *
 *  Created on: Jun 27, 2023
 *      Author: AmrAli
 */


#include "fifo.h"

FIFO_Buf_Status FIFO_Init(FIFO_Buf_t* fifo, element_type* buf, uint32_t length)
{
	if(buf == NULL )
		return FIFO_NULL;
	fifo->base = buf;
	fifo->head = buf;
	fifo->tail = buf;
	fifo->length = length;
	fifo->count = 0;

	return FIFO_NO_ERROR;
}

FIFO_Buf_Status FIFO_Enqueue(FIFO_Buf_t* fifo, element_type item)
{
	if(!fifo->base || !fifo->tail || !fifo->head)
		return FIFO_NULL;
	if(FIFO_Is_Full(fifo) == FIFO_FULL)
		return FIFO_FULL;
	*(fifo->head) = item;
	fifo->count++;
//circler fifo
	if(fifo->head == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->head = fifo->base;
	else
		fifo->head++;

	return FIFO_NO_ERROR;
}

FIFO_Buf_Status FIFO_Dequeue(FIFO_Buf_t* fifo, element_type* item)
{
	if(!fifo->base || !fifo->tail || !fifo->head)
		return FIFO_NULL;
	if(fifo->count == 0)
		return FIFO_EMPTY;

	*item = *(fifo->tail);
	fifo->count--;
	if(fifo->tail == (fifo->base + (fifo->length * sizeof(element_type))))
			fifo->tail = fifo->base;
		else
			fifo->tail++;
	return FIFO_NO_ERROR;
}

FIFO_Buf_Status FIFO_Is_Full(FIFO_Buf_t* fifo)
{
	if(!fifo->base || !fifo->tail || !fifo->head)
			return FIFO_NULL;
	if(fifo->count == fifo->length)
		return FIFO_FULL;
	return FIFO_NO_ERROR;

}
void FIFO_Print(FIFO_Buf_t* fifo)
{
	element_type* temp;
	int i;
	if(fifo->count == 0)
		printf("fifo is empty \n");
	else
	{
		temp = fifo->tail;
		printf("\n<<<<<<<<<<<<fifo print>>>>>>>>>>>>\n");
		for(i = 0; i<fifo->count; i++)
		{
			printf("\t %x \n", *temp);
			temp++;
		}
	}
}
