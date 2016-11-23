#pragma once

#include <iostream>

using std::string ;

class Enemy
{
	private :
		
		int healthPoints ; //How much damage the enemy can take before he dies
		int dodgeChance ; //The chance that the enemy will avoid an incoming hit
		int chanceToHit ; //The chance that the enemy will hit its oponant
		int speed ; //Determines who attacks first great speed can allow the enemy to attack twice consecutively
		int stamina ; //The distance the enemy can run for and total effectiveness in combat
		int mana ; //The amount of mana avalile for casting spells
		int hp ; //Enemy current health points
		int mp ; //Enemy current mana points	
		int st ; //Enemy current stamina points
		int classType ; //The class type of the player
		int enemyXLocation ; //The enemy X location
		int enemyYLocation ; //The enemy Y location
	
	public :
	
		Enemy(void) ; //Constructor
		~Enemy(void) ; //Destructor
		int init(char type) ; //Initilization method
		
		void printStuff(void) ; //For testing
} ;
