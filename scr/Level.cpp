#include "Level.h"

#include <fstream>
#include <sstream>
#include <string>

#include "Player.h"

using std::ifstream ;
using std::ostringstream ;
using std::cout ;
using std::endl ;

Level::Level(void)
{
	this->currentLevel = 0 ;
}

Level::~Level(void)
{
	
}

void Level::loadLevel(int modifier , Player* player)
{
	this->currentLevel += modifier ;
	
	if(this->currentLevel < 0)
	{
		this->currentLevel = 0 ;
	}
	
	this->loadMap() ;
	
	for(int i = 0 ; i < this->mapHeight ; i++)
	{
		int length = 0 ;
		length = this->levelMap[i].length() ;
		
		for(int k = 0 ; k < length ; k++)
		{
			if(this->levelMap[i][k] == 'P')
			{
				player->setXLocation(k) ;
				player->setYLocation(i) ;
				
				cout << "x = " << k << endl ;
				cout << "y = " << i << endl ;
				
				if(this->currentLevel != 0)
				{
					this->levelMap[i][k] = '^' ;
				}
				else
				{
					this->levelMap[i][k] = ' ' ;
				}
			}
		}
	}
}

int Level::loadMap(void)
{
	ifstream file ;	
	
	if(this->currentLevel == 0)
	{
		file.open("assets/levels/dungeonEntrance.txt" , std::fstream::in) ;
	}
	else
	{
		ostringstream convert ;
		
		convert << this->currentLevel ;
		
		string levelFileName ;
		levelFileName = "assets/levels/level" ;
		levelFileName += convert.str() ;
		levelFileName += ".txt" ;
		
		file.open(levelFileName.c_str() , std::fstream::in) ;
	}
		
	if(file.is_open())
	{
		this->mapHeight = 0 ;
		string line ;
		while(getline(file , line))
		{
			this->levelMap[this->mapHeight] = line ;
			this->mapHeight++ ;
		}
		
		file.close() ;
	}
	else
	{
		cout << "error opening file" << endl ;
		return -1 ;
	}

	return 0 ; //Map succesfully loaded
}

int Level::getMapHeight(void)
{
	return this->mapHeight ;
}

string* Level::getMap(void)
{
	return this->levelMap ;
}

char Level::getMapTile(int xLoc , int yLoc)
{
	return this->levelMap[yLoc][xLoc] ;
}

void Level::toggleDoor(int x , int y)
{
	if(this->levelMap[y][x] == 'D')
	{
		this->levelMap[y][x] = '_' ;
	}
	else
	{
		this->levelMap[y][x] = 'D' ;
	}
}
