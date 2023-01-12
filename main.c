/*******************************************************************************
  File Name: mplayer
  Author:Prachi Verma 
  License:
*******************************************************************************/

/* include files */
#include "main.h"
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include "function.h"

/* hash define*/
#define PLAYER_SOURCE_LEN 128


/* local enum define*/

/* local structure define */

/* local function */

int main(void){
    struct Player_st *pstPlayer;
    int32_t choose_state;
    int32_t usePlayer;
    char myFile[PLAYER_SOURCE_LEN];
    pstPlayer = PlayerInit();
    while(1){
	        
            printf("Enter 1 if you want to use player or 0 to Exit the program\n");
            scanf("%d",&usePlayer);
	        switch(usePlayer){
			case 1: printf("Choose a .mp3 File to play:");
                    scanf("%s",myFile);
                    PlayerSelectSource(pstPlayer,myFile);
			case 2: while(1){
                	    printf("=>Press 1 to Play\n=>Press 2 to Stop:\n");
                	    scanf("%d",&choose_state);
                	    switch(choose_state){
                	        case 1:PlayerSMHandle(pstPlayer,AKEY_START);break;
                	        case 2:PlayerSMHandle(pstPlayer,AKEY_STOP);break;
                	        default:PlayerSMHandle(pstPlayer,AKEY_INVALID);break;
                	    }  
                	  }
			case 3: PlayerDeInit(pstPlayer);break;
			default: printf("Invalid choice\n");
				     break;
		}

	}
    
    return 0;
    
}
