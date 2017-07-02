#include "Item.h"

#include <fstream>
#include <sstream>
#include <string>

Item::Item(void)
{
	this->type = 0 ;
	this->attackModifier = 0 ;
	this->hpModidier = 0 ;
	this->dodgeModifier = 0 ;
	this->chanceToHitModifier = 0 ;
	this->speedModifier = 0 ;
	this->manaModifier = 0 ;
	this->level = 1 ;
}

Item::~Item(void)
{
}

int Item::loadItemInfo(int type)
{
	this->type = type ;

	ifstream file ;
	file.open("assets/items/itemsList.txt" , std::fstream::in) ;
	
	if(file.is_open())
	{
		string line ;
		for(int i = 0 ; i < this->type ; i++)
		{
			getline(file , line) ;
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
