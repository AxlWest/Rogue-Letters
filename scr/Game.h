#pragma once

#include <iostream>

using std::string ;

class Player ;
class Draw ;
class Level ;

class Game
{
	private :
	
	static const char WALL = '+' ;
	static const char LEVEL_PROGRESS = 'E' ;
	static const char LEVEL_REGRESS = '^' ;
	static const char CLOSED_DOOR = 'D' ;
	static const char OPEN_DOOR = '_' ;
	static const char SIGN = 'S' ;
	
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
	
	int blockedPath(char blockage) ;
} ;
