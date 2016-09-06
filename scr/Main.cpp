#include "Game.h"

//#include "Draw.h"

#define NULL 0

int main(int argc , char* argv[])
{
	Game* game = NULL ;
	game = new Game() ;

	game->run() ;

	if(game != NULL)
	{
		delete game ;
		game = NULL ;
	}

    //Draw* draw = new Draw() ;
    //draw->init() ;

    //delete draw ;

	return 0 ;
}
