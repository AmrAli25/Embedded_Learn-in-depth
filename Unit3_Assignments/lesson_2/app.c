
#include "uart.h"

unsigned char String_Buffer[100] = "Learn_in_depth >>>> Amr_Ali_Ahmed";


void main(void)
{
	UART_Send_String(String_Buffer);
}