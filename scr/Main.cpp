#include "Game.h"

#include <stdlib.h>
#include <time.h>

#define NULL 0

int main(int argc , char* argv[])
{
	srand(time(NULL)) ;	
	
	Game* game = NULL ;
	game = new Game() ;

	game->run() ;

	if(game != NULL)
	{
		delete game ;
		game = NULL ;
	}

	return 0 ;
}
