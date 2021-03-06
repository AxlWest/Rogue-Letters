#pragma once

#include <iostream>

using std::string ;

class Player ;
class Draw ;
class Level ;
class Enemy ;

class Game
{
	private :
	
	static const char WALL = '+' ;
	static const char LEVEL_PROGRESS = 'E' ;
	static const char LEVEL_REGRESS = '^' ;
	static const char CLOSED_DOOR = 'D' ;
	static const char OPEN_DOOR = '_' ;
	static const char SIGN = 'S' ;
	static const char ITEM = 'I' ;
	
	Player* player ;
	Draw* draw ;
	Level* level ;
	
	Enemy* enemy ; //For Testing
	
	void handleKeyboardInput(string input) ;

	public :
	
	Game(void) ; //Constructor
	~Game(void) ; //Destructor
	int init(void) ; //Initilization method
	
	void run(void) ;
	void activateTile(int position) ;
	
	int requestPlayerClass(void) ;
	int blockedPath(char blockage) ;
	int* surroundingTileCount(int x , int y) ;
	int surroundingTileInput(int bitKey , int count) ;
	char getUserInput(void) ;
} ;
