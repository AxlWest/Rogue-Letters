#pragma once

class InventorySlot ;

class Player
{
	private :
	
	const int MAX_INVENTORY_SPACE = 12 ; //The maximum no of items the plater can carry
	
	int healthPoints ; //How much damage the player can take before he dies
	int dodgeChance ; //The chance that the player will avoid an incoming hit
	int chanceToHit ; //The chance that the player will hit its oponant
	int stamina ; //The distance the player can run for and total effectiveness in combat
	int mana ; //The amount of mana avalile for casting spells
	int classType ; //The class type of the player
	int x ; //The players X location
	int y ; //The players Y location
	
	InventorySlot imventory[MAX_INVENTORY_SPACE] ; //Storage for the players imventory
	
	public :
	
	Player() ; //Constructor
	~Player() ; //Destructor
	int init(int classType) ; //Initilization function
	
	enum classTypes{WARRIOR = 0 , ROGUE = 1 , MAGE = 2} ;
	
	int changeHP(int modifier) //Changes the players healthPoints and returns its new value
	//(Can pass in 0 to just get the players current HP)
	int changeDodgeChance(int modifier) ; //Changes the players dodgeChance and returns its new value
	//(Can pass in 0 to just get the players current dodgeChance)
	int changeChanceToHit(int modifier) ; //Changes the players chanceToHit and returns its new value
	//(Can pass in 0 to just get the players current chanceToHit)
	int changeStamina(int modifier) ; //Changes the players stamina and returns its new value
	//(Can pass in 0 to just get the players current stamina)
	int changeMana(int modifier) ; //Changes the players mana and returns its new value
	//(Can pass in 0 to just get the players current mana)
	
	int getXLocation(void) ; //Returns the players X location
	int getYLocation(void) ; //Returns the players Y location
	void setXLocation(int newLocation) ; //Sets the players new X location
	void setYLocation(int newLocation) ; //Sets the players new Y location
} ;
