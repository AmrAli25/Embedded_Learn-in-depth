/*
 * main.c
 *
 *  Created on: Jul 11, 2023
 *      Author: AmrAli
 */

#include "students.h"
#define MAX 50


Student_t Students_Data[MAX];
FIFO_Buf_t Queue_DB;

int main()
{
	DataBase_Init(&Queue_DB, Students_Data, MAX);
	char text[3];
	while(1)
	{
		DPRINTF("\n	============================\n") ;
		DPRINTF("\tChoose on the following options\n\n") ;
		DPRINTF(" 1 : Add Students From File \n") ;
		DPRINTF(" 2 : Add Student Manually \n") ;
		DPRINTF(" 3 : Find by Roll Number \n") ;
		DPRINTF(" 4 : Find by First Name \n") ;
		DPRINTF(" 5 : Find by CourseID \n") ;
		DPRINTF(" 6 : Number OF Students \n") ;
		DPRINTF(" 7 : Delete Student \n") ;
		DPRINTF(" 8 : Update Student \n") ;
		DPRINTF(" 9 : Show All Students \n") ;
		DPRINTF("10 : Exit  \n") ;
		DPRINTF("Enter your Choice : ") ;
		gets(text) ;
		DPRINTF("\n	============================\n") ;
		switch(atoi(text))
		{
		case 1:
			Add_byFile(&Queue_DB);
			break;
		case 2:
			Add_manually(&Queue_DB);
			break;
		case 3:
			Find_byRoll(&Queue_DB);
			break ;
		case 4:
			Find_byFn(&Queue_DB);
			break ;
		case 5:
			Find_byCourse(&Queue_DB);
			break ;
		case 6:
			Total_Count(&Queue_DB);
			break ;
		case 7:
			Delete_student(&Queue_DB);
			break ;
		case 8:
			Update_student(&Queue_DB);
			break ;
		case 9:
			Show_all(&Queue_DB);
			break ;
		case 10:
			return 0;
			break ;
		default :
			DPRINTF("wrong choice\n") ;
		}
	}
	return 0;
}
