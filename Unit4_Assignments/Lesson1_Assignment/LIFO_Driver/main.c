/*
 * main.c
 *
 *  Created on: Jun 27, 2023
 *      Author: AmrAli
 */

#include "lifo.h"
#include "stdio.h"
#include "stdlib.h"

unsigned int buffer1 [5];

void main()
{
	int i , temp = 0;
	LIFO_Buf_t uart_lifo, I2c_lifo;
	// static allocation
	LIFO_Init(&uart_lifo, buffer1, 5);
	// dynamic allocation
	unsigned int* buffer2 = (unsigned int*)malloc(5 * sizeof(unsigned int));
	LIFO_Init(&I2c_lifo, buffer2, 5);

	for(i = 0; i<5; i++)
	{
		if(LIFO_Add_Item(&uart_lifo, i) == LIFO_NO_ERROR)
			printf("UART_LIFO add : %d \n", i);
	}
	for(i = 0; i<5; i++)
	{
		if(LIFO_Get_Item(&uart_lifo, &temp) == LIFO_NO_ERROR)
			printf("UART_LIFO get : %d \n", temp);
	}


}

