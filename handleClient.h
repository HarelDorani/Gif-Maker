#ifndef HANDLECLIENTH
#define HANDLECLIENTH

#define MAX_PATH 120
#define MAX_NAME 20
#define CV_IGNORE_DEBUG_BUILD_GUARD

#include <opencv2/imgcodecs/imgcodecs_c.h>
#include <opencv2/core/core_c.h>
#include <opencv2/highgui/highgui_c.h>
#include "linkedList.h"
#include <stdio.h>
#include <string.h>
#include "linkedList.h"
#include "view.h"
#include <stdbool.h>

/*
 * Function will get the information needed to create a new frame
 * Input: none
 * Output: a new frame struct
 */
FrameNode* getFrameData();

/*
 * This function will get a string and reduce its allocation
 * Input: the string and its max chars
 * Output: none
 */
void myFgets(char* str, int maxSize);

/*
* this function will make sure the name is in the list
* input: the first place as a pointer and the name to check
* output: if in list or not
*/
bool inList(FrameNode** first, char* name);

/*
* this function will make sure the path is an actual path
* input: the path th user put
* output: if the path is opened or not
*/
bool isPath(char* path);


#endif
