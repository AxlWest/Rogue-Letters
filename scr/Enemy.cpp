#include "Enemy.h"

#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>

#include <curses.h>
#include <ncurses.h>

using std::ifstream ;
using std::ostringstream ;

Enemy::Enemy(void)
{
	this->healthPoints = 0 ;
	this->dodgeChance = 0 ;
	this->chanceToHit = 0 ;
	this->speed = 0 ;
	this->stamina = 0 ;
	this->mana = 0 ;
	this->damage = 0 ;
	this->hp = 0 ;
	this->mp = 0 ;
	this->st = 0 ;
	this->enemyXLocation = 0 ;
	this->enemyYLocation = 0 ;
	this->lastEnemyXLocation = 0 ;
	this->lastEnemyYLocation = 0 ;
}

Enemy::~Enemy(void)
{

}

int Enemy::init(char type , int spawnXLoc , int spawnYLoc)
{
	ifstream file ;
	
	string enemyFileName ;
	enemyFileName = "assets/enemy/" ;
	enemyFileName += type ;
	enemyFileName += ".txt" ;
	
	file.open(enemyFileName.c_str() , std::fstream::in) ;
	
	if(file.is_open())
	{	
		file >> this->healthPoints ;
		file >> this->dodgeChance ;
		file >> this->chanceToHit ;
		file >> this->speed ;
		file >> this->stamina ;
		file >> this->mana ;
		file >> this->damage ;
		
		file.close() ;
	}
	else
	{
		//cout << "error opening file" << endl ;
		return -1 ;
	}
	
	this->hp = this->healthPoints ;
	this->mp = this->dodgeChance ;
	this->st = this->stamina ;
	this->enemyXLocation = spawnXLoc ;
	this->enemyYLocation = spawnYLoc ;
	this->lastEnemyXLocation = spawnXLoc ;
	this->lastEnemyYLocation = spawnYLoc ;
	
	this->classType = type ;

	return 0 ; //Map succesfully loaded
}

int Enemy::updateEnemy(string* rawMap , int playerXLoc , int playerYLoc)
{
	int move = 0 ;
	
	move = this->lookForPlayer(rawMap , playerXLoc , playerYLoc) ;
	
	if(move == 1)
	{
		for(int i = 0 ; i < ((this->speed / 10) + 1) ; i++)
		{
			if(this->moveTowardsPlayer(rawMap , playerXLoc , playerYLoc) != 0)
			{
				return this->attack() ;
			}
		}
	}
	else
	{
		for(int i = 0 ; i < ((this->speed / 10) + 1) ; i++)
		{
			this->moveRandomly(rawMap) ;
		}
	}

	return 0 ;
}

int Enemy::lookForPlayer(string* rawMap , int playerXLoc , int playerYLoc)
{	
	int x = 0 ;
	int y = 0 ;
	
	char tile ;
	
	bool above = false ;
	bool right = false ;

	if(playerXLoc > enemyXLocation) //Is the player to the right of the enemy?	
	{	
		right = true ;
	}		

	if(playerYLoc == enemyYLocation) //Is the player on the same line as the enemy?			
	{			
		do		
		{		
			if(right == true)	
			{	
				x++ ;
			}	
			else	
			{	
				x-- ;
			}	
				
			if((this->enemyXLocation + x) == playerXLoc)	
			{	
				return 1 ; //Player found (within line of sight)
			}	
				
			tile = rawMap[this->enemyYLocation][(this->enemyXLocation + x)] ;	
		}		
		while(tile != '+' && tile != 'D') ;		
			
		return -1 ; //Player is not in line of sight (not found)		
	}

	if(playerYLoc < enemyYLocation) //Is the player above the enemy?	
	{	
		above = true ;
	}

	if(right != true)
	{
		x = 1 ;
	}	

	do			
	{	
		if(above == true)		
		{		
			y-- ;	
		}		
		else		
		{		
			y++ ;	
		}
			
		do		
		{
			if(right == true)	
			{	
				x++ ;
			}	
			else	
			{	
				x-- ;
			}	
				
			if((this->enemyYLocation + y) == playerYLoc && (this->enemyXLocation + x) == playerXLoc)	
			{	
				return 1 ; //Player found (within line of sight)
			}	
				
			tile = rawMap[(this->enemyYLocation + y)][(this->enemyXLocation + x)] ;	
		}		
		while(tile != '+' && tile != 'D') ;

		if(right != true)
		{
			x = 1 ;
		}
		else
		{
			x = 0 ;
		}		
	
		tile = rawMap[(this->enemyYLocation + y)][this->enemyXLocation] ;	
	}			
	while(tile != '+' && tile != 'D') ;			
			
	return -1 ; //Player is not in line of sight (not found)			
}

int Enemy::moveRandomly(string* rawMap)
{
	int random = 0 ;
	
	random = rand() % 10 ;

	switch(random)
	{
		case 0 : 
		case 1 :
		
			if(rawMap[(this->enemyYLocation - 1)][this->enemyXLocation] != '+' && rawMap[(this->enemyYLocation - 1)][this->enemyXLocation] != 'S')
			{
				this->enemyYLocation-- ;
			}
		
			break ;
			
		case 2 :
		case 3 :
		
			if(rawMap[(this->enemyYLocation + 1)][this->enemyXLocation] != '+' && rawMap[(this->enemyYLocation + 1)][this->enemyXLocation] != 'S')
			{
				this->enemyYLocation++ ;
			}
		
			break ;
			
		case 4 :
		case 5 :
		
			if(rawMap[this->enemyYLocation][(this->enemyXLocation + 1)] != '+' && rawMap[this->enemyYLocation][(this->enemyXLocation + 1)] != 'S')
			{
				this->enemyXLocation++ ;
			}
		
			break ;
			
		case 6 :	
		case 7 :
		
			if(rawMap[this->enemyYLocation][(this->enemyXLocation - 1)] != '+' && rawMap[this->enemyYLocation][(this->enemyXLocation - 1)] != 'S')
			{
				this->enemyXLocation-- ;
			}
		
			break ;
			
		case 8 :
		case 9 :
		case 10 :
		
			//No movement (30% chance)
		
			break ;
		
		default :
		
			break ;
	}

	return 0 ;
}

int Enemy::moveTowardsPlayer(string* rawMap , int playerXLoc , int playerYLoc)
{	
	//printw("Player X %d Player Y %d" , playerXLoc , playerYLoc) ;
	//printw("\n") ;
	//printw("Enemy X %d Enemy Y %d" , this->enemyXLocation , this->enemyYLocation) ;

	if(playerYLoc == enemyYLocation) //Is the player on the same line as the enemy
	{
		if(playerXLoc > enemyXLocation) //Is the player to the right of the enemy?
		{
			this->moveRight(rawMap) ;
			
			//this->lastEnemyXLocation = this->enemyXLocation ;
			//this->enemyXLocation++ ; //Move right

			if(this->enemyXLocation == playerXLoc && this->enemyYLocation == playerXLoc)
			{
				this->enemyXLocation = this->lastEnemyXLocation ;
				
				return 1 ;
			}
			
			return 0 ;
		}
		else
		{
			this->moveLeft(rawMap) ;

			//this->lastEnemyXLocation = this->enemyXLocation ;
			//this->enemyXLocation-- ; //Move left

			if(this->enemyXLocation == playerXLoc && this->enemyYLocation == playerXLoc)
			{
				this->enemyXLocation = this->lastEnemyXLocation ;
				
				return 1 ;
			}
			
			return 0 ;
		}
	}
	
	if(playerXLoc == enemyXLocation) //Is the player on the same column as the enemy
	{
		if(playerYLoc > enemyYLocation) //Is the player to the below the enemy?
		{
			this->moveDown(rawMap) ;
			
			//this->lastEnemyYLocation = this->enemyYLocation ;
			//this->enemyYLocation++ ; //Move down

			if(this->enemyXLocation == playerXLoc && this->enemyYLocation == playerXLoc)
			{
				this->enemyYLocation = this->lastEnemyYLocation ;
				
				return 1 ;
			}
			
			return 0 ;
		}
		else
		{
			this->moveUp(rawMap) ;

			//this->lastEnemyYLocation = this->enemyYLocation ;
			//this->enemyYLocation-- ; //Move up

			if(this->enemyXLocation == playerXLoc && this->enemyYLocation == playerXLoc)
			{
				this->enemyYLocation = this->lastEnemyYLocation ;
				
				return 1 ;
			}
			
			return 0 ;
		}
	}
	
	if(abs((this->enemyXLocation - playerXLoc)) > abs((this->enemyYLocation - playerYLoc)))
	{
		if(playerXLoc > enemyXLocation) //Is the player to the right of the enemy?
		{
			this->moveRight(rawMap) ;

			//this->lastEnemyXLocation = this->enemyXLocation ;
			//this->enemyXLocation++ ; //Move right

			if(this->enemyXLocation == playerXLoc && this->enemyYLocation == playerXLoc)
			{
				this->enemyXLocation = this->lastEnemyXLocation ;
				
				return 1 ;
			}
			
			return 0 ;
		}
		else
		{
			this->moveLeft(rawMap) ;

			//this->lastEnemyXLocation = this->enemyXLocation ;
			//this->enemyXLocation-- ; //Move left

			if(this->enemyXLocation == playerXLoc && this->enemyYLocation == playerXLoc)
			{
				this->enemyXLocation = this->lastEnemyXLocation ;
				
				return 1 ;
			}
			
			return 0 ;
		}
	}
	else
	{
		if(playerYLoc > enemyYLocation) //Is the player to the below the enemy?
		{
			this->moveDown(rawMap) ;

			//this->lastEnemyYLocation = this->enemyYLocation ;
			//this->enemyYLocation++ ; //Move down

			if(this->enemyXLocation == playerXLoc && this->enemyYLocation == playerXLoc)
			{
				this->enemyYLocation = this->lastEnemyYLocation ;
				
				return 1 ;
			}
			
			return 0 ;
		}
		else
		{
			this->moveUp(rawMap) ;

			//this->lastEnemyYLocation = this->enemyYLocation ;
			//this->enemyYLocation-- ; //Move up

			if(this->enemyXLocation == playerXLoc && this->enemyYLocation == playerXLoc)
			{
				this->enemyYLocation = this->lastEnemyYLocation ;
				
				return 1 ;
			}
			
			return 0 ;
		}
	}

	return -1 ;
}

int Enemy::moveRight(string* rawMap)
{
	char tile ;
	
	tile = rawMap[enemyYLocation][(enemyXLocation + 1)] ;
	
	switch(tile)
	{
		case '#' :
		case '_' :
		case '^' :
		case ' ' :

			this->lastEnemyXLocation = this->enemyXLocation ;
			this->enemyXLocation++ ;

			break ;

		case 'D' :
		case '+' :
		case 'S' :
		default :
			
			return -1 ;
			//Can not move any more in this direction

			break ;	

	}

	return 1 ;
}

int Enemy::moveLeft(string* rawMap)
{
	char tile ;
	
	tile = rawMap[enemyYLocation][(enemyXLocation - 1)] ;
	
	switch(tile)
	{
		case '#' :
		case '_' :
		case '^' :
		case ' ' :

			this->lastEnemyXLocation = this->enemyXLocation ;
			this->enemyXLocation-- ;
		
			break ;

		case 'D' :
		case '+' :
		case 'S' :
		default :
		
			return -1 ;
			//Can not move any more in this direction

			break ;	

	}

	return 1 ;
}

int Enemy::moveUp(string* rawMap)
{
	char tile ;
	
	tile = rawMap[(enemyYLocation - 1)][enemyXLocation] ;
	
	switch(tile)
	{
		case '#' :
		case '_' :
		case '^' :
		case ' ' :

			this->lastEnemyYLocation = this->enemyYLocation ;
			this->enemyYLocation-- ;
		
			break ;

		case 'D' :
		case '+' :
		case 'S' :
		default :
		
			return -1 ;
			//Can not move any more in this direction

			break ;	

	}

	return 1 ;
}

int Enemy::moveDown(string* rawMap)
{
	char tile ;
	
	tile = rawMap[(enemyYLocation + 1)][enemyXLocation] ;
	
	switch(tile)
	{
		case '#' :
		case '_' :
		case '^' :
		case ' ' :

			this->lastEnemyYLocation = this->enemyYLocation ;
			this->enemyYLocation++ ;
		
			break ;


		case 'D' :
		case '+' :
		case 'S' :
		default :
		
			return -1 ;
			//Can not move any more in this direction

			break ;	

	}

	return 1 ;
}

int Enemy::getXLoc(void)
{
	return this->enemyXLocation ;
}

int Enemy::getYLoc(void)
{
	return this->enemyYLocation ;
}

int Enemy::attack(void)
{
	int randomNumber ;

	randomNumber = rand() % 100 ;

	if(randomNumber > this->chanceToHit)
	{
		return this->damage ;
	}
	else
	{
		return -1 ;
	}
}

char Enemy::getType(void)
{
	return this->classType ;
}

void Enemy::printStuff(void)
{
	printw("%d" , this->healthPoints) ;
	printw("%d" , this->dodgeChance) ;
	printw("%d" , this->chanceToHit) ;
	printw("%d" , this->speed) ;
	printw("%d" , this->stamina) ;
	printw("%d" , this->mana) ;
}

