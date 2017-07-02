#pragma once

#include <iostream>

using std::string ;

class Item
{
	public :
		
		Item(void) ; //Constructor
		~Item(void) ; //Destructor

		static const int INITIAL_MAX = 2 ;
		static const int FULL_MAME_MAX = 50 ;

		int type ; //The number value of the items type
		int attackModifier ; //How much the item modifies attack
		int hpModidier ; //How much the item modifies the players health points
		int dodgeModifier ; //How much the item modifies the players dodge chance
		int chanceToHitModifier ; //How much the item modifies the players chance to hit
		int speedModifier ; //How much the item modifies the players speed stat
		int manaModifier ; //How much the item modifiers the players mana points
		int level ; //The items level (starts at 1)
		char initial[INITIAL_MAX] ; //The display initial of the item
		string fullName[FULL_MAME_MAX] ; //The full name of the item

		int loadItemInfo(int type) ; 
} ;
