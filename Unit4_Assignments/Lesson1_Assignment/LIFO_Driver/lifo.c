/*
 * lifo.c
 *
 *  Created on: Jun 27, 2023
 *      Author: AmrAli
 */

#include "lifo.h"

LIFO_Status LIFO_Init(LIFO_Buf_t* lifo_buf, unsigned int* buf, unsigned int length)
{
	if(buf == NULL)
		return LIFO_NULL;

	lifo_buf->base = buf;
	lifo_buf->head = buf;
	lifo_buf->length = length;
	lifo_buf->count = 0;
	return LIFO_NO_ERROR;
}

LIFO_Status LIFO_Add_Item(LIFO_Buf_t* lifo_buf, unsigned int item)
{
	// check if lifo is valid
	if( !lifo_buf->base || !lifo_buf->head )
		return LIFO_NULL;
	// check if lifo is full or not
	if(lifo_buf->count == lifo_buf->length)
		return LIFO_FULL;
	*(lifo_buf->head) = item;
	lifo_buf->head++;
	lifo_buf->count++;

	return LIFO_NO_ERROR;
}

LIFO_Status LIFO_Get_Item(LIFO_Buf_t* lifo_buf, unsigned int* item)
{
	// check if lifo is valid
	if( !lifo_buf->base || !lifo_buf->head )
		return LIFO_NULL;
	// check if lifo is empty
	if(lifo_buf->count == 0)
		return LIFO_EMPTY;

	lifo_buf->head--;
	*item = *(lifo_buf->head);
	lifo_buf->count--;

	return LIFO_NO_ERROR;

}
