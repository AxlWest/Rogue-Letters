#pragma once

class Item ;

class InventorySlot
{
	public :
		
		InventorySlot(void) ; //Constructor
		~InventorySlot(void) ; //Destructor

		enum items{BASIC_DAGGER = 0  ,  BASIC_SHIELD = 1 , NOVICE_MAGE_ROBES = 2} ;

		Item* item ; //The item that is in this inventory slot
} ;
