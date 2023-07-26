/*
 * students.h
 *
 *  Created on: Jul 11, 2023
 *      Author: AmrAli
 */

#ifndef STUDENTS_H_
#define STUDENTS_H_

#define DPRINTF(...)	{fflush(stdout); \
						fflush(stdin); \
						printf(__VA_ARGS__); \
						fflush(stdout); \
						fflush(stdin);}

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

#define Course_Count 5

// Data types used
typedef struct{
	char fname[50];
	char lname[50];
	int roll_num;
	int sub_id[Course_Count];
	float gpa;
}Student_t;


typedef struct{
	int length;
	int count;
	Student_t* head;
	Student_t* tail;
	Student_t* base;
}FIFO_Buf_t;

typedef enum{
	ROLL_FOUND,
	ROLL_NOT_FOUND
}Roll_Status;

typedef enum{
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_NULL,
	FIFO_ERROR,
	FIFO_EMPTY
}FIFO_Buf_Status;


// APIs prototypes

FIFO_Buf_Status DataBase_Init(FIFO_Buf_t* buffer, Student_t* students, int length);
FIFO_Buf_Status Add_byFile(FIFO_Buf_t* buffer);
FIFO_Buf_Status Add_manually(FIFO_Buf_t* buffer);
FIFO_Buf_Status Find_byRoll(FIFO_Buf_t* buffer);
FIFO_Buf_Status Find_byFn(FIFO_Buf_t* buffer);
FIFO_Buf_Status Find_byCourse(FIFO_Buf_t* buffer);;
void Total_Count(FIFO_Buf_t* buffer);
FIFO_Buf_Status Delete_student(FIFO_Buf_t* buffer);
FIFO_Buf_Status Update_student(FIFO_Buf_t* buffer);
FIFO_Buf_Status Show_all(FIFO_Buf_t* buffer);


#endif /* STUDENTS_H_ */
