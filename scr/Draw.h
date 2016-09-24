#pragma once

#include <iostream>

class Player ;

using std::string ;

class Draw
{
	private :
	
		static const int SCREEN_WIDTH = 81 ;
		
		string screen ; //A string that stores the screen
	
	public :
	
		Draw(void) ; //Constructor
		~Draw(void) ; //Destructor
		int init(void) ; //Initilization method

		void drawScreen(void) ;
		void updatePlayerStats(Player* player) ;
} ;
