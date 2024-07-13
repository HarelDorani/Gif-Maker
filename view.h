/*********************************
Class: MAGSHIMIM Final Project *
Play function declaration *
**********************************/
#ifndef VIEWH
#define VIEWH
#define CV_IGNORE_DEBUG_BUILD_GUARD

#include <opencv2/imgcodecs/imgcodecs_c.h>
#include <opencv2/core/core_c.h>

#include <opencv2/highgui/highgui_c.h>
#include "linkedList.h"
#include "handleClient.h"
#include "options.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define BUTTON_WIDTH 100
#define BUTTON_HEIGHT 50

#define GIF_REPEAT 5
/*
* this function will play  the gif
* input: a first place for a list of frames
* output: none
*/
void play(FrameNode* list);

/*
* this function will print the list
* input: the first place of the list
* output: none
*/
void printList(FrameNode* first);


/*
* this function will display a string in a window
* input: the string, the display time, the font size
* output: none
*/
void displayText(char* str, int wait, float size);
#endif
