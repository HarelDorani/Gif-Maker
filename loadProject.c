#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedList.h"
#include "loadProject.h"
#include "handleClient.h"

#pragma warning(disable:4996) // Suppress specific warnings (only for MSVC)

// Function to write values from the linked list to a file
void putValueInFile(char* filePath, FrameNode** first)
{
    FILE* file = NULL;
    FrameNode* curr = *first;

    // Open the file for writing
    file = fopen(filePath, "w");
    if (!file)
    {
        printf("Error! Cannot create file\n");
        return;
    }

    // In case of an empty list
    if (!(*first))
    {
        fclose(file);
        return;
    }

    // Run through the list
    while (curr)
    {
        // Write to the file with correct format specifiers
        fprintf(file, "%s,%d,%s\n", curr->frame->path, curr->frame->duration, curr->frame->name);
        // Move to the next frame
        curr = curr->next;
    }

    // Close the file
    fclose(file);
}

// Function to read values from a file and store them in a linked list

void extractValue(FILE* file, FrameNode** first)
{
    char* input;
    int fileSize;
    char* line;
    char* nextLine;
    FrameNode* curr;
    FrameNode* prev = NULL;

    // Move the file pointer to the end
    fseek(file, 0, SEEK_END);

    // Find the file size by checking the current index
    fileSize = ftell(file);

    // Put the file pointer back to the start
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the file content
    input = (char*)malloc(fileSize + 1);
    if (input == NULL) 
    {
        perror("Error allocating memory");
        return;
    }

    // Read the file content into the string
    fread(input, 1, fileSize, file);
    input[fileSize] = '\0';  //adding null in the end for it to be a string

    // Initialize line pointers
    line = input;
    nextLine = strchr(line, '\n');

    *first = NULL; // Initialize the head of the linked list

    // Run through the lines
    while (line) 
    {
        // Allocate memory for a new node
        curr = (FrameNode*)malloc(sizeof(FrameNode));
       

        // Allocate memory for the Frame and its fields
        curr->frame = (Frame*)malloc(sizeof(Frame));
        curr->frame->path = (char*)malloc(MAX_PATH * sizeof(char));
        curr->frame->name = (char*)malloc(MAX_NAME * sizeof(char));

        
        curr->next = NULL;

        // If there is a newline character, temporarily replace it with null terminator
        if (nextLine != NULL) 
        {
            *nextLine = '\0';
        }

        // Extract values using sscanf
        sscanf(line, "%119[^,],%u,%19[^\n]", curr->frame->path, &curr->frame->duration, curr->frame->name);

        // Add the new node to the linked list
        if (*first == NULL)//the first line case
        {
            *first = curr;
        }//the rest of the lines
        else
        {
            prev->next = curr;
        }
        prev = curr;
        line = nextLine + 1;
        nextLine = strchr(line, '\n');
        // Move to the next line
        if (nextLine != NULL) 
        {
            
            nextLine = strchr(line, '\n');
        }
        //in case arived to the end of the file
        else
        {
            line = NULL;
        }
        //in case of a wrong file
        if (!isPath(curr->frame->path))
        {
            printf("file doesnt contain real path");
            //frea the memory
            freeMemo(first);
            
            return;
        }
    }

    // Free allocated memory
    free(input);
}
