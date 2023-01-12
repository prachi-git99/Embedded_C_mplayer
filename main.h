/*******************************************************************************
  File Name: main.h
  Author:Prachi Verma
  License:
*******************************************************************************/

#ifndef __MPLAYERLIB__
#define __MPLAYERLIB__

/* include files */
#include<stdio.h>

/* hash define*/
#define PLAYER_SOURCE_LEN 128

/* enum define*/
typedef enum {
    AKEY_STOP,
    AKEY_START,
    AKEY_INVALID
}PlayerKey_e;

typedef enum {
    ASTATE_INIT,
    ASTATE_IDLE,
    ASTATE_PLAYING
} PlayerState_e;

/* structure define */
struct PlayerSource_st {
    char strSource[PLAYER_SOURCE_LEN];
    int nCurrentOffset;
};

struct Player_st {
    PlayerState_e eCurrentState;
    struct PlayerSource_st stPlayerSource;
};

/* global function */
/*******************************************************************************
** Syntax           : Player_st *PlayerInit(void);                            **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     :Player_st*                                               **
**                                                                            **
** Description      : Initialize mplayer                                      **
**                                                                            **
*******************************************************************************/
struct Player_st *PlayerInit(void);



/*******************************************************************************
**                                                                            **
** Syntax           :struct Player_st *PlayerSelectSource( struct Player_st   **
**                   *pstPlayer, char *strSource)                             **
**Parameters (in)  : Player pointer, source file name.                        **
**Parameters (out) : it will print which source source file is selected       **
**Return value     : return error                                             **
**Description      : the function will take player structure and file name and** 
**                   assigne it to strSource variable of stPlayerSource       **
**                   struct                                                   **
*******************************************************************************/
int PlayerSelectSource(
     struct Player_st *pstPlayer, 
     char *strSource);
/*******************************************************************************
**                                                                            **
** Syntax           : void PlayerSMHandle(struct Player_st *pstPlayer,        **
**                      PlayerKey_e eKeyPressed)                              **
** Parameters (in)  : player_st structure and eKeyPressed                     **
** Parameters (out) : based on the key user pressed it will print wether song **
**                    is playing or it is paused.                             **
** Return value     : error (0=success)                                       **
** Description      : This function will take player_st structure and key     **
** pressed by user and it will asssign this state                             **
** eCurrentState depending upon what state user gave.                         **
**                                                                            **
*******************************************************************************/

int PlayerSMHandle(struct Player_st *pstPlayer,    
                   PlayerKey_e eKeyPressed);
/*******************************************************************************
**                                                                            **
** Syntax           : void PlayerDeInit(struct Player_st * pstPlayer)         **  
** Parameters (in)  : pstPlayer structure                                     **
** Parameters (out) : none                                                    **
** Return value     : void                                                    **
** Description      : this function will free the player structure memory     **  
**                                 allocasted when we called init function.   **
**                                                                            **         
*******************************************************************************/
void PlayerDeInit(struct Player_st *pstPlayer);


#endif  /* __MPLAYERLIB__ */
