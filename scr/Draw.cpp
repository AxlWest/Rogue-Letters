#include "Draw.h"
#include "Player.h"
#include <fstream>
#include <sstream>
#include <string>

using std::cout ;
using std::endl ;
using std::ifstream ;
using std::ostringstream ;

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
	if(player->getHealthPoints() > 9)
	{
		ostringstream convert ;
		
		convert << player->getHealthPoints() ;
		
		string value = convert.str() ;
		
		this->screen[(this->SCREEN_WIDTH * 4) + 66] = value.c_str()[0] ;
		this->screen[(this->SCREEN_WIDTH * 4) + 67] = value.c_str()[1] ;
	}
	else
	{
		ostringstream convert ;
		
		convert << player->getHealthPoints() ;
		
		string value = convert.str() ;
		
		this->screen[(this->SCREEN_WIDTH * 4) + 67] = value.c_str()[0] ;
	}

    if(player->changeHP(0) > 9)
	{
		ostringstream convert ;
		
		convert << player->changeHP(0) ;
		
		string value = convert.str() ;
		
		this->screen[(this->SCREEN_WIDTH * 4) + 69] = value.c_str()[0] ;
		this->screen[(this->SCREEN_WIDTH * 4) + 70] = value.c_str()[1] ;
	}
	else
	{
		ostringstream convert ;
		
		convert << player->changeHP(0) ;
		
		string value = convert.str() ;
		
		this->screen[(this->SCREEN_WIDTH * 4) + 69] = value.c_str()[0] ;
	}
	
	if(player->changeMP(0) > 9)
	{
		ostringstream convert ;
		
		convert << player->changeMP(0) ;
		
		string value = convert.str() ;
		
		this->screen[(this->SCREEN_WIDTH * 4) + 72] = value.c_str()[0] ;
		this->screen[(this->SCREEN_WIDTH * 4) + 73] = value.c_str()[1] ;
	}
	else
	{
		ostringstream convert ;
		
		convert << player->changeMP(0) ;
		
		string value = convert.str() ;
		
		this->screen[(this->SCREEN_WIDTH * 4) + 73] = value.c_str()[0] ;
	}
	
	if(player->getMana() > 9)
	{
		ostringstream convert ;
		
		convert << player->getMana() ;
		
		string value = convert.str() ;
		
		this->screen[(this->SCREEN_WIDTH * 4) + 75] = value.c_str()[0] ;
		this->screen[(this->SCREEN_WIDTH * 4) + 76] = value.c_str()[1] ;
	}
	else
	{
		ostringstream convert ;
		
		convert << player->getMana() ;
		
		string value = convert.str() ;
		
		this->screen[(this->SCREEN_WIDTH * 4) + 75] = value.c_str()[0] ;
	}
	
	if(player->changeDodgeChance(0) > 9)
	{
		ostringstream convert ;
		
		convert << player->changeDodgeChance(0) ;
		
		string value = convert.str() ;
		
		this->screen[(this->SCREEN_WIDTH * 7) + 68] = value.c_str()[0] ;
		this->screen[(this->SCREEN_WIDTH * 7) + 69] = value.c_str()[1] ;
	}
	else
	{
		ostringstream convert ;
		
		convert << player->changeDodgeChance(0) ;
		
		string value = convert.str() ;
		
		this->screen[(this->SCREEN_WIDTH * 7) + 69] = value.c_str()[0] ;
	}
	
	if(player->changeChanceToHit(0) > 9)
	{
		ostringstream convert ;
		
		convert << player->changeChanceToHit(0) ;
		
		string value = convert.str() ;
		
		this->screen[(this->SCREEN_WIDTH * 7) + 74] = value.c_str()[0] ;
		this->screen[(this->SCREEN_WIDTH * 7) + 75] = value.c_str()[1] ;
	}
	else
	{
		ostringstream convert ;
		
		convert << player->changeChanceToHit(0) ;
		
		string value = convert.str() ;
		
		this->screen[(this->SCREEN_WIDTH * 7) + 75] = value.c_str()[0] ;
	}
	
	if(player->changeSpeed(0) > 9)
	{
		ostringstream convert ;
		
		convert << player->changeSpeed(0) ;
		
		string value = convert.str() ;
		
		this->screen[(this->SCREEN_WIDTH * 10) + 68] = value.c_str()[0] ;
		this->screen[(this->SCREEN_WIDTH * 10) + 69] = value.c_str()[1] ;
	}
	else
	{
		ostringstream convert ;
		
		convert << player->changeSpeed(0) ;
		
		string value = convert.str() ;
		
		this->screen[(this->SCREEN_WIDTH * 10) + 69] = value.c_str()[0] ;
	}
	
	if(player->changeST(0) > 9)
	{
		ostringstream convert ;
		
		convert << player->changeST(0) ;
		
		string value = convert.str() ;
		
		this->screen[(this->SCREEN_WIDTH * 10) + 72] = value.c_str()[0] ;
		this->screen[(this->SCREEN_WIDTH * 10) + 73] = value.c_str()[1] ;
	}
	else
	{
		ostringstream convert ;
		
		convert << player->changeST(0) ;
		
		string value = convert.str() ;
		
		this->screen[(this->SCREEN_WIDTH * 10) + 73] = value.c_str()[0] ;
	}
	
	if(player->getStamina() > 9)
	{
		ostringstream convert ;
		
		convert << player->getStamina() ;
		
		string value = convert.str() ;
		
		this->screen[(this->SCREEN_WIDTH * 10) + 75] = value.c_str()[0] ;
		this->screen[(this->SCREEN_WIDTH * 10) + 76] = value.c_str()[1] ;
	}
	else
	{
		ostringstream convert ;
		
		convert << player->getStamina() ;
		
		string value = convert.str() ;
		
		this->screen[(this->SCREEN_WIDTH * 10) + 76] = value.c_str()[0] ;
	}
}
