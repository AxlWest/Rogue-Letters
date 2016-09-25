#include "Player.h"
#include "InventorySlot.h"

#define NULL 0

Player::Player(void)
{
	this->classType = 0 ;
	this->healthPoints = 0 ;
    this->hp = 0 ;
	this->dodgeChance = 0 ;
	this->chanceToHit = 0 ;
	this->speed = 0 ;
	this->mana = 0 ;
    this->mp = 0 ;
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
	switch(classType)
	{
		case Player::WARRIOR :
		
			this->healthPoints = 10 ;
			this->dodgeChance = 3 ;
			this->chanceToHit = 50 ;
			this->speed = 4 ;
			this->stamina = 6 ;
			this->mana = 2 ;
			this->hp = 10 ;
			this->mp = 2 ;
	
			break ;
		
		case Player::ROGUE :
		
			this->healthPoints = 5 ;
			this->dodgeChance = 10 ;
			this->chanceToHit = 80 ;
			this->speed = 10 ;
			this->stamina = 10 ;
			this->mana = 4 ;
			this->hp = 5 ;
			this->mp = 4 ;
		
			break ;
		
		case Player::MAGE :
	
			this->healthPoints = 2 ;
			this->dodgeChance = 5 ;
			this->chanceToHit = 50 ;
			this->speed = 6 ;
			this->stamina = 10 ;
			this->mana = 10 ;
			this->hp = 2 ;
			this->mp = 10 ;
	
			break ;
		
		default :
		
			//cout << "Unexpected class creation error Player::init" << endl ;
			return -1 ;
		
			break ;	
	}

	return 0 ;
}

int Player::changeHP(int modifier)
{
	if(modifier == 0)
	{
		return this->hp ;
	}
	
	this->hp += modifier ;
	
	return this->hp ;
}

void Player::changeHealthPoints(int modifier)
{
	this->healthPoints += modifier ;
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

int Player::changeSpeed(int modifier)
{
    if(modifier == 0)
    {
        return this->speed ;
    }

    this->speed += modifier ;

    return this->speed ;
}

int Player::changeST(int modifier)
{
	if(modifier == 0)
	{
		return this->stamina ;
	}
	
	this->stamina += modifier ;
	
	return this->stamina ;
}

void Player::changeStamina(int modifier)
{
    this->stamina += modifier ;
}

int Player::changeMP(int modifier)
{
	if(modifier == 0)
	{
		return this->mp ;
	}
	
	this->mp += modifier ;
	
	return this->mp ;
}

void Player::changeMana(int modifier)
{
	this->mana += modifier ;
}

int Player::getHealthPoints(void)
{
	return this->healthPoints ;
}

int Player::getMana(void)
{
	return this->mana ;
}

int Player::getStamina(void)
{
    return this->stamina ;
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
