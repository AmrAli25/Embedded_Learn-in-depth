/*
 * main.c
 *
 *  Created on: Jun 28, 2023
 *      Author: AmrAli
 */


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

#define DPRINTF(...)	{fflush(stdout); \
						fflush(stdin); \
						printf(__VA_ARGS__); \
						fflush(stdout); \
						fflush(stdin);}

struct Sdata_t{
	char name[40];
	int ID;
	float hight;
};

//linked_list node
struct SStudent{
	struct Sdata_t student;
	struct SStudent* pNextStudent;
};

struct SStudent* gpFirstStudent = NULL;

// Add new record of data
void Add_Student()
{
	struct SStudent* pNewStudent;
	struct SStudent* pLastStudent;
	char text[40];

	// if list is empty
	if(gpFirstStudent == NULL)
	{
		// create new record
		pNewStudent = (struct SStudent *) malloc(sizeof(struct SStudent));
		// assign the head to the new recored
		gpFirstStudent = pNewStudent;
	}
	else
	{
		pLastStudent = gpFirstStudent;
		while(pLastStudent->pNextStudent)
			pLastStudent = pLastStudent->pNextStudent;
		// create new record
		pNewStudent = (struct SStudent *) malloc(sizeof(struct SStudent));
		pLastStudent->pNextStudent = pNewStudent;
	}
	// fill the record
	DPRINTF("\n Enter the student ID: ");
	gets(text);
	pNewStudent->student.ID = atoi(text);

	DPRINTF("\n Enter the student full name: ");
	gets(pNewStudent->student.name);

	DPRINTF("\n Enter the student hight: ");
	gets(text);
	pNewStudent->student.hight = atof(text);


	pNewStudent->pNextStudent = NULL;
};

int Delete_Student()
{
	char text[40];
	unsigned int student_ID;
	// get the id the user wants to delete
	DPRINTF("\n Enter the student ID to be deleted : ");
	gets(text);
	student_ID = atoi(text);
	// check if list is not empty
	if(gpFirstStudent)
	{
		struct SStudent* pSelectedStudent = gpFirstStudent;
		struct SStudent* pPrevStudent = NULL;
		// check the list for the selected ID
		while(pSelectedStudent)
		{
			if(pSelectedStudent->student.ID == student_ID)
			{
				if(pPrevStudent)//if the selected is not the first node
				{
					pPrevStudent->pNextStudent = pSelectedStudent->pNextStudent;
				}
				else // if the selected is the first node
				{
					gpFirstStudent = pSelectedStudent->pNextStudent;

				}
				free(pSelectedStudent);
				return 1;
			}
			pPrevStudent = pSelectedStudent;
			pSelectedStudent = pSelectedStudent->pNextStudent;
		}
	}
	DPRINTF("\n Can't find the selected student ID");
	return 0;
}

void View_Students()
{
	struct SStudent* pCurrentStudent = gpFirstStudent;
	int count = 1;
	if(gpFirstStudent == NULL)
	{
		DPRINTF("\n Empty list");
	}
	else
	{
		while(pCurrentStudent)
		{
			DPRINTF("\n Record number %d ", count);
			DPRINTF("\n \t ID: %d ", pCurrentStudent->student.ID);
			DPRINTF("\n \t Name: %s ", pCurrentStudent->student.name);
			DPRINTF("\n \t Hight: %f ", pCurrentStudent->student.hight);
			pCurrentStudent = pCurrentStudent->pNextStudent;
			count++;
		}
	}
}

void Delete_all()
{
	struct SStudent* pCurrentStudent = gpFirstStudent;
	if(gpFirstStudent == NULL)
	{
		DPRINTF("\n Empty list");
	}
	else
	{
		while(pCurrentStudent)
		{
			struct SStudent* pTempStudent = pCurrentStudent;
			pCurrentStudent = pCurrentStudent->pNextStudent;
			free(pTempStudent);
		}
		gpFirstStudent = NULL;
	}
}

void Get_Nth()
{
	char text[40];
	DPRINTF("\n Enter the index: ");
	gets(text);
	int index = atoi(text);
	int count = 0;
	struct SStudent* pCurrentStudent = gpFirstStudent;
	// check if the list is empty
	if(gpFirstStudent == NULL)
	{
		DPRINTF("\n Empty list");
	}
	else
	{
		while(pCurrentStudent)
		{
			if(count == index)
			{
				DPRINTF("\n Record number %d ", count+1);
				DPRINTF("\n \t ID: %d ", pCurrentStudent->student.ID);
				DPRINTF("\n \t Name: %s ", pCurrentStudent->student.name);
				DPRINTF("\n \t Hight: %f ", pCurrentStudent->student.hight);
			}
			count++;
			pCurrentStudent = pCurrentStudent->pNextStudent;
		}
	}
}

int Get_Length(struct SStudent* head)
{
	if(head == NULL)
		return 0;
	else
		return (1+Get_Length(head->pNextStudent));
}

void Reverse()
{
	struct SStudent* pPrev = NULL;
	struct SStudent* pNext = NULL;
	struct SStudent* pCurrent = gpFirstStudent;
	while(pCurrent)
	{
		pNext = pCurrent->pNextStudent; // store the next node
		pCurrent->pNextStudent = pPrev; // reverse the pointer
		// move the pointers one position ahead
		pPrev = pCurrent;
		pCurrent = pNext;
	}
	gpFirstStudent = pPrev;

	int count = 1;
	pCurrent = gpFirstStudent;
	if(gpFirstStudent == NULL)
	{
		DPRINTF("\n Empty list");
	}
	else
	{
		while(pCurrent)
		{
			DPRINTF("\n Record number %d ", count);
			DPRINTF("\n \t ID: %d ", pCurrent->student.ID);
			DPRINTF("\n \t Name: %s ", pCurrent->student.name);
			DPRINTF("\n \t Hight: %f ", pCurrent->student.hight);
			pCurrent = pCurrent->pNextStudent;
			count++;
		}
	}
}

void Get_Nth_NodefromEnd()
{
	char text[40];
	DPRINTF("\n Enter the number of selected node: ");
	gets(text);
	int num = atoi(text);
	struct SStudent* pMain = gpFirstStudent;
	struct SStudent* pRef = gpFirstStudent;
	int count = 0;
	// loop to put the ref_ptr in distance n from main_ptr
	while(count != num)
	{
		pRef = pRef->pNextStudent;
		count++;
	}
	while(pRef)
	{
		pMain = pMain->pNextStudent;
		pRef = pRef->pNextStudent;
	}
	// print the nth node
	DPRINTF("\n Record number %d ", num);
	DPRINTF("\n \t ID: %d ", pMain->student.ID);
	DPRINTF("\n \t Name: %s ", pMain->student.name);
	DPRINTF("\n \t Hight: %f ", pMain->student.hight);
}

void main()
{
	char text[40];
	while(1)
	{
		DPRINTF("\n ============================ ");
		DPRINTF("\n \t Choose one of the following options \n");
		DPRINTF("\n 1: Add_Student ");
		DPRINTF("\n 2: Delete_Student ");
		DPRINTF("\n 3: View_Students ");
		DPRINTF("\n 4: Delete_all ");
		DPRINTF("\n 5: Get_Nth ");
		DPRINTF("\n 6: Get_Length ");
		DPRINTF("\n 7: Reverse ");
		DPRINTF("\n 8: Get_Nth_NodefromEnd ");
		DPRINTF("\n Enter option number: ");
		gets(text);
		DPRINTF("\n ============================ ");
		switch(atoi(text))
		{
		case 1:
			Add_Student();
			break;
		case 2:
			Delete_Student();
			break;
		case 3:
			View_Students();
			break;
		case 4:
			Delete_all();
			break;
		case 5:
			Get_Nth();
			break;
		case 6:
			DPRINTF("\n The length of the list is %d", Get_Length(gpFirstStudent));
			break;
		case 7:
			Reverse();
			break;
		case 8:
			Get_Nth_NodefromEnd();
			break;
		default:
			DPRINTF("\n Wrong option ");
			break;
		}
	}
}
