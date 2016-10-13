#pragma once

#include <iostream>

class Player ;

using std::string ;

class Level
{

	private :
		
		int currentLevel ; //Stores the current level
		int mapHeight ; //Stores number of lines in the map
		
		string levelMap[500] ; //An array of strings containing the levels map
		
		int loadMap(void) ;
	
	public :
	
		Level(void) ; //Constructor
		~Level(void) ; //Destructor
		
		void loadLevel(int modifier , Player* player) ;
		
		int getMapHeight(void) ;
		string* getMap(void) ;
		char getMapTile(int xLoc , int yLoc) ;
		void toggleDoor(int x , int y) ;
} ;
