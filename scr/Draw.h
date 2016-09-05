#pragma once

#include <iostream>

using std::string ;

class Draw
{
	private :
	
		string screen ; //A string that stores the screen
	
	public :
	
		Draw(void) ; //Constructor
		~Draw(void) ; //Destructor
		int init(void) ; //Initilization method

		void drawScreen(void) ;
} ;
