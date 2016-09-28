#pragma once

#include <iostream>

using std::string ;

class Player ;
class Draw ;
class Level ;

class Game
{
	private :
	
	Player* player ;
	Draw* draw ;
	Level* level ;
	
	void handleKeyboardInput(string input) ;

	public :
	
	Game(void) ; //Constructor
	~Game(void) ; //Destructor
	int init(void) ; //Initilization method
	
	void run(void) ;
	
	int requestPlayerClass(void) ;
} ;
