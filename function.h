/*******************************************************************************
  File Name: function.h
  Author:Prachi Verma
  License:
*******************************************************************************/

struct Player_st *PlayerInit(void)
{
	struct Player_st *pstPlayer;
	pstPlayer = malloc(sizeof(struct Player_st)); 

	pstPlayer->eCurrentState = ASTATE_INIT ;
	pstPlayer->stPlayerSource.strSource;
    pstPlayer->stPlayerSource.nCurrentOffset=0;
    
	pstPlayer->eCurrentState = ASTATE_IDLE ;

	return pstPlayer;
}


int PlayerSelectSource(
     struct Player_st *pstPlayer, 
     char *strSource)
{
    if(pstPlayer != NULL || strSource != NULL)
    {
        if(strstr(strSource,".mp3")!=NULL)
        {
    	  printf("File is:%s\n",strSource);
    	  strcpy(pstPlayer->stPlayerSource.strSource,strSource);
    	  return 0;
    	}
    	else
    	{
    	    printf("please choose a mp3 file only");
    	    exit(0);
    	}   
    }
    return -1;
}

int PlayerSMHandle(struct Player_st *pstPlayer,    
                   PlayerKey_e eKeyPressed)
{
    
	if(eKeyPressed==AKEY_START)
	{
	    pstPlayer->eCurrentState = ASTATE_PLAYING;
	    printf("Song is Playing\n");
	}
	else if(eKeyPressed==AKEY_STOP)
	{
	   pstPlayer->eCurrentState = ASTATE_IDLE;
	   printf("Song is Paused\n"); 
	}
	else if(eKeyPressed==AKEY_INVALID)
	{
	    printf("Player Stopped... Wrong Choice");
	    exit(0);
	}
	return 0;

}

void PlayerDeInit(struct Player_st *pstPlayer)
{
	free(pstPlayer);
}
