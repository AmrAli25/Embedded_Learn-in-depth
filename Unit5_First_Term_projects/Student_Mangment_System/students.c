/*
 * students.c
 *
 *  Created on: Jul 11, 2023
 *      Author: AmrAli
 */

#include "students.h"
#define MAX 50

static void Show_student(Student_t* student)
{
	DPRINTF("Student first name: %s\n", student->fname);
	DPRINTF("Student last name: %s\n", student->lname);
	DPRINTF("Student roll number: %d\n", student->roll_num);
	DPRINTF("Student GPA: %0.2f\n", student->gpa);
	for(int j = 0; j <Course_Count; j++)
		DPRINTF("Student courses ID are: %d\n", student->sub_id[j]);
	DPRINTF("----------------------------------\n");
}
static Roll_Status Roll_Check(FIFO_Buf_t* buffer, int roll)
{
	Student_t* temp = buffer->tail;
	for( int i = 0; i < (buffer->count); i++ )
	{
		if(temp->roll_num == roll)
			return ROLL_FOUND;
		else
			temp++;
	}
	return ROLL_NOT_FOUND;
}

FIFO_Buf_Status DataBase_Init(FIFO_Buf_t* buffer, Student_t* students, int length)
{
	//check if there is no buffer
	if(!students || !buffer)
	{
		DPRINTF("[ERROR] Initialization of Queue failed\n");
		return FIFO_NULL;
	}
	buffer->base = students;
	buffer->head = students;
	buffer->tail = students;
	buffer->length = length;
	buffer->count = 0;
	return FIFO_NO_ERROR;
}

FIFO_Buf_Status Add_byFile(FIFO_Buf_t* buffer)
{
	//check if there is no buffer
	if(!buffer)
	{
		DPRINTF("[ERROR] Initialization of Queue failed\n");
		return FIFO_NULL;
	}
	// check if buffer is full
	if(buffer->count == buffer->length)
	{
		DPRINTF("[ERROR] The Queue is full\n");
		return FIFO_FULL;
	}
	FILE* student_dataFile;
	Student_t NStudent;

	student_dataFile = fopen("student_data.txt","r");
	if(!student_dataFile)
	{
		DPRINTF("[ERROR] File can't be opend\n");
		return FIFO_ERROR;
	}
	// loop over the file to input the data in it
	while(!feof(student_dataFile))
	{
		//check if Queue is full
		if(buffer->count == buffer->length)
		{
			DPRINTF("[ERROR] The Queue is full\n");
			return FIFO_FULL;
		}
		fscanf(student_dataFile,"%d",&NStudent.roll_num);
		//check if the roll number is duplicate or not
		if(Roll_Check(buffer, NStudent.roll_num) == ROLL_FOUND)
		{
			DPRINTF("[ERROR] This roll number %d already exists\n", NStudent.roll_num);
			fscanf(student_dataFile, "%*[^\n]");
			continue;
		}
		fscanf(student_dataFile,"%s",NStudent.fname);
		fscanf(student_dataFile,"%s",NStudent.lname);
		fscanf(student_dataFile,"%f",&NStudent.gpa);
		for(int i = 0; i<Course_Count; i++)
			fscanf(student_dataFile,"%d",&NStudent.sub_id[i]);
		//add the new data to the list
		*(buffer->head) = NStudent;
		if(buffer->head == (buffer->base + buffer->length-1))
			buffer->head = buffer->base;
		else
			buffer->head++;
		buffer->count++;
		DPRINTF("[INFO] Student with roll number %d added successfully\n", NStudent.roll_num);
	}
	fclose(student_dataFile);
	DPRINTF("[INFO]  Students added successfully\n");
	DPRINTF("----------------------------------\n");
	Total_Count(buffer);
	return FIFO_NO_ERROR;
}

FIFO_Buf_Status Add_manually(FIFO_Buf_t* buffer)
{
	//check if there is no buffer
	if(!buffer)
	{
		DPRINTF("[ERROR] Initialization of Queue failed\n");
		return FIFO_NULL;
	}
	// check if buffer is full
	if(buffer->count == buffer->length)
	{
		DPRINTF("[ERROR] The Queue is full\n");
		return FIFO_FULL;
	}
	Student_t NStudent;
	int temp_roll;
	// adding data
	DPRINTF("Enter the roll number: ");
	scanf("%d", &temp_roll);
	// check if roll exists or not
	if(Roll_Check(buffer, temp_roll) == ROLL_FOUND)
	{
		DPRINTF("[ERROR] the roll number you entered already exist in the data base\n");
		return FIFO_ERROR;
	}
	NStudent.roll_num = temp_roll;
	DPRINTF("Enter the first name of student: ");
	gets(NStudent.fname);
	DPRINTF("Enter the last name of student: ");
	gets(NStudent.lname);
	DPRINTF("Enter the GPA the student obtained: ");
	scanf("%f", &NStudent.gpa);
	DPRINTF("Enter the course ID for every course\n");
	for(int i = 0; i<Course_Count; i++)
	{
		DPRINTF("Course %d ID: ", i+1);
		scanf("%d", &NStudent.sub_id[i]);
	}
	*(buffer->head) = NStudent;
	buffer->count++;
	// circular queue
	if(buffer->head == (buffer->base + buffer->length-1))
		buffer->head = buffer->base;
	else
		buffer->head++;
	DPRINTF("[INFO]  Students added successfully\n");
	DPRINTF("----------------------------------\n");
	Total_Count(buffer);
	return FIFO_NO_ERROR;
}

FIFO_Buf_Status Find_byRoll(FIFO_Buf_t* buffer)
{
	//check if there is no buffer
	if(!buffer)
	{
		DPRINTF("[ERROR] Initialization of Queue failed\n");
		return FIFO_NULL;
	}
	if(buffer->count == 0)
	{
		DPRINTF("[ERROR] The Queue is empty\n");
		return FIFO_EMPTY;
	}
	int temp_roll;
	Student_t *temp = buffer->tail;
	DPRINTF("Enter the roll number of the student: ");
	scanf("%d", &temp_roll);
	for(int i = 0; i < buffer->count; i++)
	{
		if(temp->roll_num == temp_roll)
		{
			DPRINTF("[INFO] The student details are:\n");
			Show_student(temp);
			return FIFO_NO_ERROR;
		}
		else
			temp++;
	}
	DPRINTF("----------------------------------\n");
	DPRINTF("[ERROR] Roll number %d not found in the database\n", temp_roll);
	return FIFO_ERROR;

}
FIFO_Buf_Status Find_byFn(FIFO_Buf_t* buffer)
{
	//check if there is no buffer
	if(!buffer)
	{
		DPRINTF("[ERROR] Initialization of Queue failed\n");
		return FIFO_NULL;
	}
	if(buffer->count == 0)
	{
		DPRINTF("[ERROR] The Queue is empty\n");
		return FIFO_EMPTY;
	}
	char temp_name[15];
	int flag=0;
	Student_t *temp = buffer->tail;
	DPRINTF("Enter the first name of the student: ");
	gets(temp_name);
	for(int i = 0; i < buffer->count; i++)
	{
		if(strcmpi(temp->fname, temp_name) == 0)
		{
			DPRINTF("[INFO] The student details are:\n");
			Show_student(temp);
			flag++;
		}
		if(temp == (buffer->base + buffer->length - 1))
			temp = buffer->base;
		else
			temp++;
	}
	if(flag == 0)
	{
		DPRINTF("----------------------------------\n");
		DPRINTF("[ERROR] First name %s not found in the database\n", temp_name);
	}
	return FIFO_NO_ERROR;

}

FIFO_Buf_Status Find_byCourse(FIFO_Buf_t* buffer)
{
	//check if there is no buffer
	if(!buffer)
	{
		DPRINTF("[ERROR] Initialization of Queue failed\n");
		return FIFO_NULL;
	}
	if(buffer->count == 0)
	{
		DPRINTF("[ERROR] The Queue is empty\n");
		return FIFO_EMPTY;
	}
	int temp_subId;
	int flag = 0;
	Student_t *temp = buffer->tail;
	DPRINTF("Enter the Course ID for the student: ");
	scanf("%d", &temp_subId);
	for(int i = 0; i < buffer->count; i++)
	{
		for(int j = 0; j < Course_Count; j++)
		{
			if(temp->sub_id[j] == temp_subId)
			{
				DPRINTF("[INFO] The student details are:\n");
				Show_student(temp);
				flag++;
				break;
			}
		}
		if(temp == (buffer->base + buffer->length - 1))
			temp = buffer->base;
		else
			temp++;
	}
	if(flag == 0)
	{
		DPRINTF("----------------------------------\n");
		DPRINTF("[ERROR] Course ID %d not found in the database\n", temp_subId);
	}
	else
		DPRINTF("[INFO] Number of students in course %d is: %d\n", temp_subId, flag);

	return FIFO_NO_ERROR;
}
void Total_Count(FIFO_Buf_t* buffer)
{
	DPRINTF("[INFO] The total number of students is %d\n", buffer->count);
	DPRINTF("[INFO] You can add up to %d students \n", MAX);
	DPRINTF("[INFO] You can add up to %d more students \n", MAX - buffer->count);
}
FIFO_Buf_Status Delete_student(FIFO_Buf_t* buffer)
{
	if(!buffer)
	{
		DPRINTF("[ERROR] Initialization of Queue failed\n");
		return FIFO_NULL;
	}
	if(buffer->count == 0)
	{
		DPRINTF("[ERROR] The Queue is empty\n");
		return FIFO_EMPTY;
	}
	int del_roll, done = 0;
	Student_t* current = buffer->tail;
	Student_t* next = buffer->tail + 1;

	DPRINTF("Enter the roll number which you want to delete: \n");
	scanf("%d", &del_roll);
	// loop to find the wanted roll number
	for(int i = 0; i< buffer->count; i++)
	{
		if(current->roll_num == del_roll)
		{
			current = next;
			done = 1;
		}
		if(current == (buffer->base + buffer->length - 1))
			current = buffer->base;
		else
			current++;
		if(next == (buffer->base + buffer->length - 1))
			next = buffer->base;
		else
			next++;
	}
	if(done)
	{
		DPRINTF("[INFO] The roll number is deleted successfully\n");
		buffer->count--;
	}
	else
		DPRINTF("[ERROR] This roll number not found\n");

	return FIFO_NO_ERROR;
}

FIFO_Buf_Status Update_student(FIFO_Buf_t* buffer)
{
	if(!buffer)
	{
		DPRINTF("[ERROR] Initialization of Queue failed\n");
		return FIFO_NULL;
	}
	if(buffer->count == 0)
	{
		DPRINTF("[ERROR] The Queue is empty\n");
		return FIFO_EMPTY;
	}
	int temp_roll, n;
	DPRINTF("Enter the roll number which you want to update:");
	scanf("%d", &temp_roll);
	Student_t* temp = buffer->tail;
	int U_Roll;
	for(int i = 0; i < buffer->count; i++)
	{
		if(temp->roll_num == temp_roll)
		{
			DPRINTF("Choose what you want to change or update\n");
			DPRINTF("1. first name\n");
			DPRINTF("2. last name\n");
			DPRINTF("3. roll number\n");
			DPRINTF("4. GPA\n");
			DPRINTF("5. Courses\n");
			scanf("%d", &n);

			switch (n)
			{
			case 1:
				DPRINTF("Enter the new first name: ");
				gets(temp->fname);
				break;
			case 2:
				DPRINTF("Enter the new last name: ");
				gets(temp->lname);
				break;
			case 3:

				DPRINTF("Enter the new roll number: ");
				scanf("%d", &U_Roll);
				if(Roll_Check(buffer, U_Roll) == ROLL_FOUND)
				{
					DPRINTF("[ERROR] The roll number already exists \n");
					return FIFO_ERROR;
				}
				else
				{
					temp->roll_num = U_Roll;
					break;
				}
			case 4:
				DPRINTF("Enter the new GPA: ");
				scanf("%f", temp->gpa);
				break;
			case 5:
				for(int i = 0; i<Course_Count; i++)
				{
					DPRINTF("Enter %d Course ID: ", i+1);
					scanf("%d", temp->sub_id[i]);
				}
				break;
			}
		}
		if(temp == (buffer->base + buffer->length - 1))
			temp = buffer->base;
		else
			temp++;
	}
	DPRINTF("[INFO] Updated successfully\n");
	return FIFO_NO_ERROR;
}
FIFO_Buf_Status Show_all(FIFO_Buf_t* buffer)
{
	if(!buffer)
	{
		DPRINTF("[ERROR] Initialization of Queue failed\n");
		return FIFO_NULL;
	}

	if(buffer->count == 0)
	{
		DPRINTF("[ERROR] The Queue is empty\n");
		return FIFO_EMPTY;
	}
	int i = 0;
	Student_t *temp = buffer->tail;
	DPRINTF("[INFO] Showing all the database\n");
	while(i < buffer->count)
	{
		Show_student(temp);
		i++;
		temp++;
	}
	return FIFO_NO_ERROR;
}

