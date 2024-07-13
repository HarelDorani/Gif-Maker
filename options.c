#include "options.h"
#include "handleClient.h"
#include "view.h"
#include <stdio.h>
#include "linkedList.h"
#include "loadProject.h"

int preMenuOption()
{
    int choice = 0;
    printf("Welcome to Magshimim Movie Maker! What would you like to do?\n");
    // Asking for a choice as long as the choice is not 0 or 1
    do
    {
        printf(" [0] Create a new project\n");
        printf(" [1] Load existing project\n");
        scanf_s("%d", &choice);
        getchar(); // Clean the buffer
        if (choice != 1 && choice != 0)
        {
            printf("Invalid choice, try again:\n");
        }
    } while (choice != 1 && choice != 0);

    return choice; // Return the choice
}

int printMenu()
{
    int choice = 0;
    printf("What would you like to do?\n");
    do
    {
        printf(" [0] Exit\n");
        printf(" [1] Add new Frame\n");
        printf(" [2] Remove a Frame\n");
        printf(" [3] Change frame index\n");
        printf(" [4] Change frame duration\n");
        printf(" [5] Change duration of all frames\n");
        printf(" [6] List frames\n");
        printf(" [7] Play movie!\n");
        printf(" [8] Add existing Frame at the end of the list\n");
        printf(" [9] Save project\n");
        
        scanf_s("%d", &choice);
        getchar();
        if (choice > 9 || choice < 0)
        {
            printf("You should type one of the options - 0-8!\n\n");
        }
    } while (choice > 9 || choice < 0);

    return choice;
}

FrameNode* switchCase(FrameNode** first, int choice)
{
    //variables to use for all cases (that is whay the names are not specific)
    char frameName[MAX_NAME];
    char str[] = "nigzin";
    char path[MAX_PATH];
    FrameNode* frame = NULL;
    int newNum = 0;
    switch (choice)
    {
    //in case the user chooce to add frame:
    case ADD_FRAME:
        frame = getFrameData();
        //make sure the path is an actual path
        if (!isPath(frame->frame->path))
        {
            printf("Could not open the path\n  ");
            break;
        }
        addFrame(first, frame);
        break;
    //in case the user chooce to remove frame: 
    case REMOVE_FRAME:

        //get the name to remove
        printf("Enter the name of the frame to remove: ");
        myFgets(frameName, MAX_NAME);
        //in case the name doesnt exist the program will not continue in this option
        if (!inList(first, frameName))
        {
            printf("The frame does not exist\n");
            break;
        }
        //remove the frame
        removeFrame(first, frameName);
        break;
    //in case the user chooce to print the list
    case PRINT_FRAME_LIST:

        //print the list
        printList(*first);
        break;
    //in case the user chooce to change a frame index
    case(CHANGE_INDEX):

        //get the name of the frame
        printf("Enter the name of the frame\n");
        myFgets(frameName, MAX_NAME);
        //in case the name doesnt exist the program will not continue in this option
        if (!inList(first, frameName))
        {
            printf("The frame does not exist\n");
            break;
        }
        //get the new index
        printf("Enter the new index in the movie you wish to place the frame\n");
        scanf_s("%d", &newNum);

        //change the index
        changeIndex(first, frameName, newNum - 1);
        break;
    //in case the user chooce to change a frame duration
    case CHANGE_DURATION:
        //get the name
        printf("enter the name of the frame\n");
        myFgets(frameName, MAX_NAME);
        //in case the name doesnt exist the program will not continue in this option
        if (!inList(first, frameName))
        {
            printf("The frame does not exist\n");
            break;
        }
        //get the new duration
        printf("Enter the new duration\n");
        scanf_s("%d", &newNum);
        getchar();//clean the buffer

        //change the duration
        changeDuration(first, frameName, newNum);
        break;
    //in case the user chooce to set the duration
    case SET_DURATION:

        //get the duration
        printf("Enter the duration for all frames:\n");
        scanf_s("%d", &newNum);
        getchar();//clean the buffer
        //set all duration
        setDuration(first, newNum);
        break;
    //in case the user chooce to play the gif
    case PLAY_MOVIE:
        //play the movie
        play(*first);
        break;
    case ADD_EXISTING_FRAME:
        //get the name of the frame
        printf("Enter the name of the frame\n");
        myFgets(frameName, MAX_NAME);
        if (!inList(first, frameName))
        {
            printf("The frame does not exist\n");
            break;
        }
        addExistFrame(first, frameName);
        break;
    case SAVE_MOVIE:
        printf("Where to save the project? enter a full path and file name\n");
        myFgets(path, MAX_PATH);
        putValueInFile(path, first);
        break;
    default:
        break;
    }
    return *first;
}
