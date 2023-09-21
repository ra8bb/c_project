#include<stdio.h>
#include<stdlib.h>
#include "STD.h"
#include"SDB.h"

static uint8 numOfStudents = 0;

static student base[10];



void SDB_DeleteEntry(uint32 id)
{
    uint8 i;
    uint8 j;

    for  (i = 0; i < numOfStudents; i++)
    {
        if (base[i].Student_ID == id)
        {
            for (j = i; j < numOfStudents - 1; j++)
            {
                base[j] = base[j + 1];
            }
            numOfStudents--;
            break;
        }
    }
}


bool SDB_IsIdExist(uint32 id)
{
    uint8 i;
    uint32 l[10];


    for (i = 0; i < numOfStudents; i++)
    {
        if (base[i].Student_ID == id)
        {
            return true;
        }
    }
    return false;
}




bool SDB_ReadEntry(uint32 id)
{
    uint8 i;
    for (i = 0; i < numOfStudents; i++)
        {
        if (base[i].Student_ID == id)
        {
            printf("Student ID: %u\n", base[i].Student_ID);
            printf("Student Year: %u\n", base[i].Student_year);
            printf("Course1 ID: %u\n", base[i].Course1_ID);
            printf("Course1 Grade: %u\n", base[i].Course1_grade);
            printf("Course2 ID: %u\n", base[i].Course2_ID);
            printf("Course2 Grade: %u\n", base[i].Course2_grade);
            printf("Course3 ID: %u\n", base[i].Course3_ID);
            printf("Course3 Grade: %u\n", base[i].Course3_grade);


            return true;
        }
    }
    return false;
}

bool SDB_IsFull()
{
    return numOfStudents >= 10;
}


uint8 SDB_GetUsedSize()
{
    return numOfStudents;
}

bool SDB_AddEntry()
{
    if (SDB_IsFull())
        return false;

    student news;

    printf("Enter Student ID: ");
    scanf("%u", &news.Student_ID);

    printf("Enter Student Year: ");
    scanf("%u", &news.Student_year);

    printf("Enter Course1 ID: ");
    scanf("%u", &news.Course1_ID);

    printf("Enter Course1 Grade: ");
    scanf("%u", &news.Course1_grade);

    printf("Enter Course2 ID: ");
    scanf("%u", &news.Course2_ID);

    printf("Enter Course2 Grade: ");
    scanf("%u", &news.Course2_grade);

    printf("Enter Course3 ID: ");
    scanf("%u", &news.Course3_ID);

    printf("Enter Course3 Grade: ");
    scanf("%u", &news.Course3_grade);

    base[numOfStudents++] = news;
    return true;
}


void SDB_GetList(uint8 *count, uint32 *list)
{
    *count = numOfStudents;
    uint8 i;

    for (i = 0; i < numOfStudents; i++)
    {
        list[i] = base[i].Student_ID;
    }
}


