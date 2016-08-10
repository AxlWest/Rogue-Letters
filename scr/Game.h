#pragma once

class Player ;

class Game
{
	private :
	
	Player* player ;

	public :
	
	Game() ; //Constructor
	~Game() ; //Destructor
	int init() ; //Initilization method
	
	void run() ;
	
	int requestPlayerClass() ;
} ;
