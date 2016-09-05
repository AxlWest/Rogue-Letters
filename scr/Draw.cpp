#include "Draw.h"
#include <fstream>

using std::cout ;
using std::ifstream ;

Draw::Draw(void)
{

}

Draw::~Draw(void)
{

}

int Draw::init(void)
{
	ifstream file ;
	file.open("../assets/ui.txt" , std::ios::in) ;
	
	if(file.is_open())
	{
		string line ;
		while(getline(file , line))
		{
			this->screen += line ;
		}
		
		file.close() ;
		
		return 0 ;
	}
	
	return -1 ; //Return error
}

void Draw::drawScreen(void)
{
	cout << screen ;
}