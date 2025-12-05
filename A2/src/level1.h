#ifndef LEVEL1_H
#define LEVEL1_H

/**
* @file level1.h
* @brief Public interface for makeing level 1 maze
*
* This file contains the public interface for level 1 maze functions.
*
* @author Evan wong
* @date Dec.4,2025
*/

/**
* @brief first_level_maze makes the level 1 maze and general gameplay
* @param void
* @return it return global  macros based on if the player wants to quit,menu,next or  pause
*/
int first_level_maze(void);

/**
* @brief level1Phase calls for the level 1 splash screen and calls for first_level_maze
* @param void
* @return it return global macros based on if the player wants to quit,menu, or next
*/
int level1Phase(void);

#endif
