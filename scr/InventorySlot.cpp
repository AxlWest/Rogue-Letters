#include "InventorySlot.h"

InventorySlot::InventorySlot(void)
{
	this->item = 0 ;
}

InventorySlot::~InventorySlot(void)
{
	if(this->item != 0)
	{
		delete this->item ;
		this->item = 0 ;
	}
}
