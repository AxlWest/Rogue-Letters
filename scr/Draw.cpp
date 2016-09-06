#include "Draw.h"
#include <fstream>

using std::cout ;
using std::endl ;
using std::ifstream ;

Draw::Draw(void)
{
	cout << "created" << endl ;
}

Draw::~Draw(void)
{

}

int Draw::init(void)
{
	cout << "In the Function" << endl ;

	ifstream file ;
	file.open("../assets/ui.txt" , std::ios::in) ;
	
	cout << "Here" ;
	
	if(file.is_open())
	{
		string line ;
		while(getline(file , line))
		{
			cout << line ;
			this->screen += line ;
		}
		
		file.close() ;
		
		return 0 ;
	}
	
    return 7 ; //Return error
}

void Draw::drawScreen(void)
{
    cout << "Draw screen method" << endl ;
    cout << this->screen ;
}
