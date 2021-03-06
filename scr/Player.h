#pragma once

class InventorySlot ;

class Player
{
	private :
	
	static const int MAX_INVENTORY_SPACE = 8 ; //The maximum no of items the plater can carry
	
	int healthPoints ; //How much damage the player can take before he dies
	int dodgeChance ; //The chance that the player will avoid an incoming hit
	int chanceToHit ; //The chance that the player will hit its oponant
	int speed ; //Determines who attacks first great speed can allow the player to attack twice consecutively
	int stamina ; //The distance the player can run for and total effectiveness in combat
	int mana ; //The amount of mana avalile for casting spells
	int hp ; //Players current health points
	int mp ; //Players current mana points	
	int st ; //Players current stamina points
	int classType ; //The class type of the player
	int playerXLocation ; //The players X location
	int playerYLocation ; //The players Y location
	
	InventorySlot* inventory[MAX_INVENTORY_SPACE] ; //Storage for the players imventory
	
	public :
	
	Player() ; //Constructor
	~Player() ; //Destructor
	int init(int classType) ; //Initilization function
	
	enum classTypes{WARRIOR = 0 , ROGUE = 1 , MAGE = 2} ;
	
	int changeHP(int modifier) ; //Changes the players healthPoints and returns its new value
	//(Can pass in 0 to just get the players current HP)
	void changeHealthPoints(int modifier) ; //Modifies the players health total by the ammount passed in
	int changeDodgeChance(int modifier) ; //Changes the players dodgeChance and returns its new value
	//(Can pass in 0 to just get the players current dodgeChance)
	int changeChanceToHit(int modifier) ; //Changes the players chanceToHit and returns its new value
	//(Can pass in 0 to just get the players current chanceToHit)
	int changeSpeed(int modifier) ; //Changes the players speed and returns its new value
	//(Can pass in 0 to just get the players current speed)
	void changeStamina(int modifier) ; //Modifies the players stamina total by the ammount passed in
	int changeST(int modifier) ; //Changes the players stamina and returns its new value
	//(Can pass in 0 to just get the players current stamina)
	int changeMP(int modifier) ; //Changes the players mana and returns its new value
	//(Can pass in 0 to just get the players current mana)
	void changeMana(int modifier) ; //Modifies the players mana total by the ammount passed in
	
	int getHealthPoints(void) ; //Returns the players health points
	int getMana(void) ; //Returns the players mana points
	int getStamina(void) ; //Returns the players stamina points
	int getXLocation(void) ; //Returns the players X location
	int getYLocation(void) ; //Returns the players Y location
	int meleeAttack(void) ; //Attacks and reutrns if its attack is on target
	void setXLocation(int newLocation) ; //Sets the players new X location
	void setYLocation(int newLocation) ; //Sets the players new Y location
} ;
