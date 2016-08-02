#include "Game.h"

int main(int argc , char* argv[])
{
	Game* game = NULL ;
	game = new game() ;
	
	game->init() ;

	game->run() ;

	if(game != NULL)
	{
		delete game ;
		game = NULL ;
	}

	return 0 ;
}
