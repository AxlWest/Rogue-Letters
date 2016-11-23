#include "Enemy.h"

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
	this->hp = 0 ;
	this->mp = 0 ;
	this->st = 0 ;
	this->classType = 0 ;
	this->enemyXLocation = 0 ;
	this->enemyYLocation = 0 ;
}

Enemy::~Enemy(void)
{

}

int Enemy::init(char type)
{
	ifstream file ;
	
	string enemyFileName ;
	enemyFileName = "assets/enemy/" ;
	enemyFileName += type ;
	enemyFileName += ".txt" ;
	
	file.open(enemyFileName.c_str() , std::fstream::in) ;
	
	if(file.is_open())
	{
		/*this->mapHeight = 0 ;
		string line ;
		while(getline(file , line))
		{
			this->levelMap[this->mapHeight] = line ;
			this->mapHeight++ ;
		}
		*/
		
		//getline(file , this->healthPoints) ;
		//getline(file , this->dodgeChance) ;
		//getline(file , this->chanceToHit) ;
		//getline(file , this->speed) ;
		//getline(file , this->stamina) ;
		//getline(file , this->mana) ;
		
		file >> this->healthPoints ;
		file >> this->dodgeChance ;
		file >> this->chanceToHit ;
		file >> this->speed ;
		file >> this->stamina ;
		file >> this->mana ;
		
		file.close() ;
	}
	else
	{
		//cout << "error opening file" << endl ;
		return -1 ;
	}

	return 0 ; //Map succesfully loaded
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
