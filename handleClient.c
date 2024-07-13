#include "handleClient.h"
#include <stdlib.h>
#include <stdio.h>
#pragma warning(disable:4996)//cancel the errors apear after change the debug to 64x instead of 84x
FrameNode* getFrameData()
{
    FrameNode* newNode = (FrameNode*)malloc(sizeof(FrameNode));
    Frame* frame = (Frame*)malloc(sizeof(Frame));

    printf("*** Creating new frame ***\n");

    // Get the frame path
    printf("Please insert frame path:\n");
    frame->path = (char*)malloc(MAX_PATH * sizeof(char));
    myFgets(frame->path, MAX_PATH);

    // Get the frame duration
    printf("Please insert frame duration (in milliseconds):\n");
    scanf_s("%d", &(frame->duration));
    getchar(); // consume the leftover newline character

    // Get the frame name
    printf("Please choose a name for the frame:\n");
    frame->name = (char*)malloc(MAX_NAME * sizeof(char));
    myFgets(frame->name, MAX_NAME);

    newNode->frame = frame;
    newNode->next = NULL;
   
    return newNode;
}

void myFgets(char* str, int maxSize)
{
    fgets(str, maxSize, stdin);//get the name
    str[strcspn(str, "\n")] = '\0';//cancel \n
}

bool inList(FrameNode** first, char* name)
{
    FrameNode* curr = *first;
    //run through the list
    while (curr)
    {
        
        //check if the name matches the current frame name
        if (!strcmp(name, curr->frame->name))
        {
            return true;//if tes return true
        }
        curr = curr->next;// if not move to the next frame
    }
    return false;//if all frame desnt match return false
}

bool isPath(char* path)
{
    IplImage* image;
    image = cvLoadImage(path, 1);
    if (!image) // The image is empty 
    {
        return false;
    }
    return true;
}

