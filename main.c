/*********************************
Class: MAGSHIMIM C2 *
Week: *
Name: *
Credits: *
**********************************/

#include <stdio.h>
#include "view.h"
#include "options.h"
#include "linkedList.h"
#include "handleClient.h"

#pragma warning(disable:4996)//cancel the errors apear after change the debug to 64x instead of 84x

int main(void)
{
    int preChoice = 0; // this is the choice before the menu
    int i = 0;
    char buff[20];
    char str[] = "GIF MAKER";
    int choice = 0; // the specific choice
    FrameNode* first = NULL;
    char path[MAX_PATH];
    FILE* file;


    //display the opening
    for (i = 0; i < strlen(str) - 1; i++)
    {
        strncpy(buff, str, i);
        buff[i] = NULL;
        displayText(buff, 200, 2);
    }
    //display the full opening for more time
    displayText(str, 1500, 2);
    
    //get the pre choice
    preChoice = preMenuOption();
    if (preChoice == 0)
    {
        printf("Working on a new project.\n");
        //srart the menu - choice loop
        do
        {
            choice = printMenu();
            first = switchCase(&first, choice);
        } while (choice != 0);
    }
    else
    {
        //get the path
        printf("Enter the path of the project (including project name):\n");
        myFgets(path, MAX_PATH);
        file = fopen(path, "r");
        if (!file)
        {
            printf("Error!- cant open file, creating a new project\n");
        }
        else
        {
            //extract value from the file
            extractValue(file, &first);
        }
        //srart the menu - choice loop
        do
        {
            choice = printMenu();
            first = switchCase(&first, choice);
        } while (choice != 0);

    }
    printf("good bye hope you enjoy :)");

    //fee the memory
    freeMemo(first);

    getchar();
    return 0;
}
