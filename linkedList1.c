#include "linkedList.h"
#include <string.h>
#include "handleClient.h"
#pragma warning(disable:4996) // Suppress specific warnings (only for MSVC)


void addFrame(FrameNode** first, FrameNode* newFrame)
{
    FrameNode* temp = *first;
    //in case of an empty list the first is the new frame
    if (*first == NULL)
    {
        *first = newFrame;
        return;
    }
    // run through the list to arive the last frame
    while (temp->next)
    {
        temp = temp->next;
    }
    //put the new frame after the last one
    temp->next = newFrame;
}

void freeMemo(FrameNode* head)
{
    FrameNode* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp->frame->name);//free the name
        free(temp->frame->path);//free the path
        free(temp->frame);//free the frame
        free(temp);//free the frame node
    }
}

void removeFrame(FrameNode** first, char* nameToRemove)
{
    
    FrameNode* p = *first;
    FrameNode* dNode = NULL;
    //make sure the list is not empty
    if (*first)
    {
        //if the name to remove is the name of the first frame
        if (strcmp((*first)->frame->name, nameToRemove) == 0)
        {
            *first = (*first)->next;
            free(p);
        }

        else
        {
            //go to the frame the user  asked to remove
            while (p->next && 0 != strcmp(p->next->frame->name, nameToRemove))
            {
                p = p->next;
            }
            //remove the frame
            if (p->next)
            {
                dNode = p->next;
                p->next = dNode->next;
                free(dNode);
            }
        }
    }

}
void changeIndex(FrameNode** first, char* name, int newInd)
{
    FrameNode* curr = *first;
    FrameNode* prev = NULL;
    FrameNode* toChange = NULL;
    FrameNode* beforeNewInd = NULL;
    int oldInd = 0;
    int i;

    //find the node to change and remove it from the list
    while (curr)
    {
        if (strcmp(name, curr->frame->name) == 0)
        {
            toChange = curr;
            break;
        }
        prev = curr;
        curr = curr->next;
        oldInd++;
    }

    //if toChange is not found, or newInd is less than 0, do nothing
    if (!toChange || newInd < 0) 
    {
        return;
    }

    //remove toChange from its current position
    if (prev) 
    {
        prev->next = toChange->next;
    }
    else 
    {
        *first = toChange->next; //update first if toChange was the first node
    }

    //find the node before newInd
    curr = *first;
    for (i = 0; i < newInd && curr; i++)
    {
        beforeNewInd = curr;
        curr = curr->next;
    }

    //insert toChange after beforeNewInd
    if (beforeNewInd)
    {
        toChange->next = beforeNewInd->next;
        beforeNewInd->next = toChange;
    }
    else //before NewInd is NULL, meaning toChange should be the new first node
    {
        toChange->next = *first;
        *first = toChange;
    }
}


void changeDuration(FrameNode** first, char* name, int newDuration)
{
    FrameNode* curr = *first;
    //run through the list
    while (curr)
    {
        //check if the current frame is the frame the user wants to change
        if (strcmp(curr->frame->name, name))
        {
            curr->frame->duration = newDuration;//change and exit the loop
            return;
        }
        curr = curr->next;//move to the next frame
    }
}
void setDuration(FrameNode** first, int newDuration)
{
    FrameNode* curr = *first;
    //run through the list
    while (curr)
    {
        //change the curr duration
        curr->frame->duration = newDuration;
        curr = curr->next;
    }
}

void addExistFrame(FrameNode** first, char* name) {
    FrameNode* curr = *first;
    FrameNode* toAdd = NULL;
    FrameNode* newNode = NULL;

    // run through the list
    while (curr) 
    {
        //if the current frame is the one the user want to put at the end
        if (!strcmp(curr->frame->name, name)) 
        {
            toAdd = curr;
            break;
        }
        curr = curr->next;
    }

    // allocate memory for the new frame node and its contents
    newNode = (FrameNode*)malloc(sizeof(FrameNode));
    newNode->frame = (Frame*)malloc(sizeof(Frame));
    newNode->frame->name = (char*)malloc(sizeof(char) * MAX_NAME);
    newNode->frame->path = (char*)malloc(sizeof(char) * MAX_PATH);

    // move the frame data from the found frame to the new node
    strcpy(newNode->frame->name, toAdd->frame->name);
    strcpy(newNode->frame->path, toAdd->frame->path);
    newNode->frame->duration = toAdd->frame->duration;
    
    //get the frame new name
    printf("What would you want the new name of the frame to be?\n");
    myFgets(newNode->frame->name, MAX_NAME);
    //put the last node's first with NULL to prevent an error
    newNode->next = NULL;

    // add the frame at the end of the list
    addFrame(first, newNode);
}