#include <stdio.h>
#include <stdlib.h>
#include "STD.h"
#include "SDB.h"


void SDB_APP()
{
    uint8 choice;
 while (1)
    {
        printf("choose an option from 1 to 8:\n\n");
        printf("To add entry, enter 1\n");
        printf("To get used size in database, enter 2\n");
        printf("To read student data, enter 3\n");
        printf("To get the list of all student IDs, enter 4\n");
        printf("To check is ID is existed, enter 5\n");
        printf("To delete student data, enter 6\n");
        printf("To check is database is full, enter 7\n");
        printf("To exit enter 0\n");




        scanf("%u", &choice);

        if (choice == 0)
            break;

        SDB_action(choice);
    }
}

void SDB_action(uint8 choice)
{
    unsigned int id;
    uint8 i;
    uint8 count;
    uint32 *l[10];


    switch (choice)
    {
        case 1:
        SDB_AddEntry();
        break;

        case 2:
        printf("the size of database is: %u\n", SDB_GetUsedSize());
        break;

        case 3:

        printf("Please enter student ID to read the data: ");
        scanf("%u", &id);
        if (!SDB_ReadEntry(id))
            {
            printf("this student ID not found in database.\n");
            }
        break;


        case 4:

            SDB_GetList(&count, l);
            printf("List of IDs:\n");
            for (i = 0; i < count; i++)
                {
                printf("%u\n", l[i]);
            }




        case 5:
        printf("Enter student ID to delete the data");
        scanf("%u", &id);


        if (SDB_IsIdExist(id))
            printf("Student ID exists in database.\n");
        else
            printf("Student ID does not exist in database.\n");
        break;


        case 6:
        printf("Enter student ID to delete: ");
        scanf("%u", &id);
        SDB_DeleteEntry(id);
        printf("student data deleted..\n");
        break;


        case 7:
        if (SDB_IsFull())
            printf("Database now full.\n");
        else
            printf("Database now is not full.\n");
        break;


        default:
        printf("you entered invalid choice.\n");
        break;



    }

}
