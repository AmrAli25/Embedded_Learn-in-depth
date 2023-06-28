/*
 * main.c
 *
 *  Created on: Jun 27, 2023
 *      Author: AmrAli
 */


#include "fifo.h"


void main()
{
	FIFO_Buf_t FIFO_Uart;
	element_type i, temp = 0;
	if(FIFO_Init(&FIFO_Uart, buffer1, 5) == FIFO_NO_ERROR )
		printf("<<<<<<<<<<FIFO_Init is done>>>>>>>>>\n");
	for(i = 0; i < 7; i++)
	{
		printf("FIFO_Enqueue(%x) \n", i);
		if(FIFO_Enqueue(&FIFO_Uart, i) == FIFO_NO_ERROR)
			printf("\t FIFO_Enqueue is done\n");
		else
			printf("\t FIFO_Enqueue failed\n");
	}

	FIFO_Print(&FIFO_Uart);
	if(FIFO_Dequeue(&FIFO_Uart, &temp) == FIFO_NO_ERROR)
		printf("FIFO_Dequeue %x  ------- done \n", temp);
	if(FIFO_Dequeue(&FIFO_Uart, &temp) == FIFO_NO_ERROR)
			printf("FIFO_Dequeue %x  ------- done \n", temp);
	FIFO_Print(&FIFO_Uart);

}
