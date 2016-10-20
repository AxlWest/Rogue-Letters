#pragma once

#include <iostream>

class Player ;

using std::string ;

class Level
{

	private :
		
		static const int SURROUNDING_TILE_MAX = 8 ;
		
		int currentLevel ; //Stores the current level
		int mapHeight ; //Stores number of lines in the map
		char* surroundingTilesStore ;
		
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
		void toggleSurroundingTiles(int bitKey , int x , int y) ;
} ;
