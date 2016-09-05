#pragma once

class Player ;
class Draw ;

class Game
{
	private :
	
	Player* player ;
	Draw* draw ;

	public :
	
	Game() ; //Constructor
	~Game() ; //Destructor
	int init() ; //Initilization method
	
	void run() ;
	
	int requestPlayerClass() ;
} ;
