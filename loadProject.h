#ifdef LOADPROJECTH
#define LOADPROJECTH
#pragma warning(disable:4996)//cancel the errors apear after change the debug to 64x instead of 84x
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "loadProject.h"
#include "handleClient.h"
/*
* this function will put the information in the file
* input: the file path and the first place of  the list
* output: none
*/
void putValueInFile(char* filePath, FrameNode** first);
void extractValue(FILE* file, FrameNode** first);

#endif //LOADPROJECTH