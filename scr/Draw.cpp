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

}

Draw::~Draw(void)
{

}

int Draw::init(void)
{
	ifstream file ;
	file.open("assets/ui/ui.txt" , std::fstream::in) ;
	
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
		
		this->screen[(this->SCREEN_WIDTH * 4) + 66] = ' ' ;
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
		this->screen[(this->SCREEN_WIDTH * 4) + 70] = ' ' ;
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
		
		this->screen[(this->SCREEN_WIDTH * 4) + 72] = ' ' ;
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
		this->screen[(this->SCREEN_WIDTH * 4) + 76] = ' ' ;
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
		
		this->screen[(this->SCREEN_WIDTH * 7) + 68] = ' ' ;
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
		
		this->screen[(this->SCREEN_WIDTH * 7) + 74] = ' ' ;
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
		
		this->screen[(this->SCREEN_WIDTH * 10) + 68] = ' ' ;
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
		
		this->screen[(this->SCREEN_WIDTH * 10) + 72] = ' ' ;
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
		
		this->screen[(this->SCREEN_WIDTH * 10) + 75] = value.c_str()[0] ;
		this->screen[(this->SCREEN_WIDTH * 10) + 76] = ' ' ;
	}
}

void Draw::updateMap(string* map , int mapHeight , int playerX , int playerY)
{
	//Clear the map section of the screen
	for(int i = 1 ; i < 63 ; i++)
	{
		for(int k = 1 ; k < 15 ; k++)
		{
			this->screen[(this->SCREEN_WIDTH * k) + i] = ' ' ;
		}
	}

	//Update the map section of the screen
	for(int i = 1 ; i < 63 ; i++)
	{
		if(((i - 31) + playerX) >= 0)
		{					
			for(int k = 1 ; k < 15 ; k++)
			{
				if(((k - 7) + playerY) >= 0)
				{
					if(((i - 31) + playerX) < map[((k - 7) + playerY)].length())
					{
						if(((k - 7) + playerY) < mapHeight)
						{
							this->screen[(this->SCREEN_WIDTH * k) + i] = map[((k - 7) + playerY)][((i - 31) + playerX)] ;
						}
					}
				}
			}
		}
	}
	
	this->screen[(this->SCREEN_WIDTH * 7) + 31] = 'P' ;
}

void Draw::addMessage(string message)
{
	this->messageBoard[0] = this->messageBoard[1] ;
	this->messageBoard[1] = this->messageBoard[2] ;
	this->messageBoard[2] = this->messageBoard[3] ;
	this->messageBoard[3] = this->messageBoard[4] ;
	this->messageBoard[4] = message ;
	
	for(int i = 17 ; i < 22 ; i++)
	{
		for(int k = 4 ; k < 64 ; k++)
		{
			
			if((k - 4) >= this->messageBoard[(i - 17)].length())
			{
				this->screen[(this->SCREEN_WIDTH * i) + k] = ' ' ;
			}
			else
			{
				this->screen[(this->SCREEN_WIDTH * i) + k] = this->messageBoard[(i - 17)][(k - 4)] ;
			}
		}
	}
}
