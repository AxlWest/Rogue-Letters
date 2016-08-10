#include "Player.h"
#include "InventorySlot.h"

#define NULL 0

Player::Player(void)
{
	this->classType = 0 ;
	this->healthPoints = 0 ;
	this->dodgeChance = 0 ;
	this->chanceToHit = 0 ;
	this->speed = 0 ;
	this->mana = 0 ;
	this->playerXLocation = 0 ;
	this->playerYLocation = 0 ;
	
	for(int i = 0 ; i < this->MAX_INVENTORY_SPACE ; i++)
	{
		this->inventory[i] = NULL ;
	}
}

Player::~Player()
{
	for(int i = 0 ; i < this->MAX_INVENTORY_SPACE ; i++)
	{
		if(this->inventory[i] != NULL)
		{
			delete this->inventory[i] ;
			this->inventory[i] = NULL ;
		}
	}
}

int Player::init(int classType)
{
	
}

int Player::changeHP(int modifier)
{
	if(modifier == 0)
	{
		return this->healthPoints ;
	}
	
	this->healthPoints += modifier ;
	
	return this->healthPoints ;
}

int Player::changeDodgeChance(int modifier)
{
	if(modifier == 0)
	{
		return this->dodgeChance ;
	}
	
	this->dodgeChance += modifier ;
	
	return this->dodgeChance ;
}

int Player::changeChanceToHit(int modifier)
{
	if(modifier == 0)
	{
		return this->chanceToHit ;
	}
	
	this->chanceToHit += modifier ;
	
	return this->chanceToHit ;
}

int Player::changeStamina(int modifier)
{
	if(modifier == 0)
	{
		return this->stamina ;
	}
	
	this->stamina += modifier ;
	
	return this->stamina ;
}

int Player::changeMana(int modifier)
{
	if(modifier == 0)
	{
		return this->mana ;
	}
	
	this->mana += modifier ;
	
	return this->mana ;
}

int Player::getXLocation(void)
{
	return this->playerXLocation ;
}

int Player::getYLocation(void)
{
	return this->playerYLocation ;
}

void Player::setXLocation(int newLocation)
{
	this->playerXLocation = newLocation ;
}

void Player::setYLocation(int newLocation)
{
	this->playerYLocation = newLocation ;
}
