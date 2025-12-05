#ifndef LEVEL2_H
#define LEVEL2_H
/**********************************
* @File level2.h
* @Brief Public interface for making second maze level
* @Author Evan Wong
* @Date Dec.4, 2025
*******************************/

/**
* @Brief second_level_maze makes the second level maze and general gameplay
* @Param void
* @Return it returns global macros based on if the player wants to quit,menu,next or paue
*/
int second_level_maze(void);
/**
* @Brief level2Phase calls for the level2 splash screen and the second_level_maze
* @Param void
* @Return it return nglobal Macros based on if the player wants to quit,menu or next
*/
int level2Phase(void);

#endif
