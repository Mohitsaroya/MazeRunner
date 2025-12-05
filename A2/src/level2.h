#ifndef LEVEL2_H
#define LEVEL2_H

/**
* @file level2.h
* @brief Public interface for making second maze level
*
* This file contains the public interface for level 2 maze functions.
*
* @author Evan Wong
* @date Dec.4, 2025
*/

/**
* @Brief second_level_maze makes the second level maze and general gameplay
* @param void
* @return void it returns global macros based on if the player wants to quit,menu,next or paue
*/
int second_level_maze(void);
/**
* @brief level2Phase calls for the level2 splash screen and the second_level_maze
* @param void
* @return void it return nglobal Macros based on if the player wants to quit,menu or next
*/
int level2Phase(void);

#endif