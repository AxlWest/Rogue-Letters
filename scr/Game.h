#pragma once

class Player ;
class Draw ;

class Game
{
	private :
	
	Player* player ;
	Draw* draw ;

	public :
	
	Game(void) ; //Constructor
	~Game(void) ; //Destructor
	int init(void) ; //Initilization method
	
	void run(void) ;
	
	int requestPlayerClass(void) ;
} ;
