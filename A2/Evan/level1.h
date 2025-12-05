#ifndef LEVEL1_H
#define LEVEL1_H
/***************************************
* @File level1.h
* @Brief Public interface for makeing level 1 maze
* @Author Evan wong
* @Date Dec.4,2025
*************************************/

/**
* @Brief first_level_maze makes the level 1 maze and general gameplay
* @param void
* @return it return global  macros based on if the player wants to quit,menu,next or  pause
*/
int first_level_maze(void);

/**
* @Brief level1Phase calls for the level 1 splash screen and calls for first_level_maze
* @param void
* @return it return global macros based on if the player wants to quit,menu, or next
*/
int level1Phase(void);

#endif
