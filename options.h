#ifndef OPTIONSH
#define OPTIONSH

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "view.h"
#include "handleClient.h"
#include "loadProject.h"

// Enum for menu choices
typedef enum {
    ADD_FRAME = 1,
    REMOVE_FRAME,
    CHANGE_INDEX,
    CHANGE_DURATION,
    SET_DURATION,
    PRINT_FRAME_LIST,
    PLAY_MOVIE,
    ADD_EXISTING_FRAME,
    SAVE_MOVIE
} Choices;

/*
 * Function will prompt the user if they want to use an existing project or create a new one.
 * Input: none
 * Output: 0 for a new project, 1 to load an existing one
 */
int preMenuOption();

/*
 * Function will print the menu and get the user's choice.
 * Input: none
 * Output: the choice as an integer
 */
int printMenu();

/*
 * Function to handle the user's menu choice.
 * Input: pointer to the first frame node, user's choice
 * Output: updated list of frame nodes
 */
FrameNode* switchCase(FrameNode** first, int choice);

#endif // OPTIONSH
