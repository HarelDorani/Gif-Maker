#include "view.h"
#include <stdio.h>

void play(FrameNode* list)
{
    cvNamedWindow("HAREL'S GIF MMAKER", CV_WINDOW_AUTOSIZE); // create a window
    FrameNode* head = list;
    int imgNum = 1, playCount = 0;
    IplImage* image;
    while (playCount < GIF_REPEAT)
    {
        while (list != NULL)
        {
            image = cvLoadImage(list->frame->path, 1);
            if (!image) // The image is empty - shouldn't happen since we checked already.
            {
                printf("Could not open or find image number %d", imgNum);
            }
            else
            {
                cvShowImage("HAREL'S GIF MMAKER", image); // display the image
                cvWaitKey(list->frame->duration); // wait
                list = list->next;
                cvReleaseImage(&image);
            }
            imgNum++;
        }
        list = head; // rewind
        playCount++;
    }
    cvDestroyWindow("HAREL'S GIF MMAKER");
}

void printList(FrameNode* first)
{
    FrameNode* curr;
    char str[150];
    if (!first)
    {
        printf("The list is empty.\n");
        return; // in case of an empty list
    }
    printf("Name\t\tDuration\tPath\n");
    curr = first;
    while (curr)
    {
        
        printf("%s\t\t% d ms\t\t%s\n", curr->frame->name, curr->frame->duration, curr->frame->path);
        //put the valuse in a string
        snprintf(str, sizeof(str), "name: %s     duration: %d ms     path: %s", curr->frame->name, curr->frame->duration, curr->frame->path);
        //desply this in a window
        displayText(str, 1500, 0.1);
        //move to the next frame
        curr = curr->next;
    }
}

void displayText(char* str, int wait, float size)
{

    int width = 0;
    int height = 0;
    if (strlen(str) < 12)
    {
        width = 500;
        height = 200;
    }
    else
    {
        width = 1600;
        height = 400;
    }
    IplImage* image = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 3);

    // Set the image
    cvSet(image, cvScalar(255, 173, 99, 230), NULL);

    // Define the text position and font
    CvPoint text_position = cvPoint(50, 80); 
    CvFont font;
    cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX, size, 1.0, 2, 2, 15);
    CvScalar text_color = CV_RGB(255, 255, 255);

    // Put the text on the image
    cvPutText(image, str, text_position, &font, text_color);

    // Create a window
    cvNamedWindow("HAREL'S GIF MMAKER", CV_WINDOW_AUTOSIZE);

    // Display the image with text
    cvShowImage("HAREL'S GIF MMAKER", image);

    // Wait for a key press
    cvWaitKey(wait);

    // Release the image and destroy the window
    cvReleaseImage(&image);
    cvDestroyWindow("HAREL'S GIF MMAKER");
}