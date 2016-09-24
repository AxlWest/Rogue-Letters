#include "Draw.h"
#include "Player.h"
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
	ifstream file ;
	file.open("assets/ui.txt" , std::fstream::in) ;
	
	if(file.is_open())
	{
		string line ;
		while(getline(file , line))
		{
			//cout << line ;
			this->screen += line ;
			this->screen += "\n" ;
		}
		
		file.close() ;
		
		return 0 ;
	}
	else
	{
		return -2 ; //Return error
	}
	
    return -1 ; //Return error
}

void Draw::drawScreen(void)
{
    cout << this->screen ;
}

void Draw::updatePlayerStats(Player* player)
{
    if(player->changeHP(0) > 9)
	{
        this->screen[(this->SCREEN_WIDTH * 4) + 69] = player->changeHP(0) ;
	}
	else
	{
        this->screen[(this->SCREEN_WIDTH * 4) + 69] = player->changeHP(0) ;
	}
}
