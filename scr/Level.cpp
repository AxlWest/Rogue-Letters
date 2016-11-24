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
	
	this->surroundingTilesStore = NULL ;
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
	this->convertMap() ;
	
	for(int i = 0 ; i < this->mapHeight ; i++)
	{
		int length = 0 ;
		length = this->levelMap[i].length() ;
		
		for(int k = 0 ; k < length ; k++)
		{
			if(modifier >= 0)
			{
				if(this->levelMap[i][k] == 'P')
				{
					player->setXLocation(k) ;
					player->setYLocation(i) ;
				
					//cout << "x = " << k << endl ;
					//cout << "y = " << i << endl ;
				
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
			else
			{
				if(this->levelMap[i][k] == 'E')
				{
					player->setXLocation(k) ;
					player->setYLocation(i) ;
				
					
					this->levelMap[i][k] = 'E' ;
				}
				
				if(this->levelMap[i][k] == 'P')
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
			//this->levelMap[this->mapHeight] = line ;
			this->rawMap[this->mapHeight] = line ;
			this->mapHeight++ ;
		}
		
		file.close() ;
	}
	else
	{
		//cout << "error opening file" << endl ;
		return -1 ;
	}

	return 0 ; //Map succesfully loaded
}

void Level::convertMap(void)
{
	for(int i = 0 ; i < MAX_MAP_SIZE ; i++)
	{
		this->levelMap[i].assign(this->rawMap[i]) ;	
		
		for(int k = 0 ; k < levelMap[i].length() ; k++)
		{
			if(this->levelMap[i][k] == '#')
			{
				this->levelMap[i][k] = ' ' ;
			}
			else
			{
				this->levelMap[i][k] = this->rawMap[i][k] ;
			}
		}
	}
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

void Level::toggleSurroundingTiles(int bitKey , int x , int y)
{
	int count = 1 ;
	
	cout << "BitKey: " << bitKey << endl ;
	
	if(this->surroundingTilesStore == NULL)
	{
		this->surroundingTilesStore = new char[Level::SURROUNDING_TILE_MAX] ;	
	
		if(bitKey & 1)
		{
			this->surroundingTilesStore[0] = this->getMapTile((x - 1) , (y - 1)) ;
			this->levelMap[(y - 1)][(x - 1)] = convertNumberToString(count)[0] ;
		
			count++ ;
		}
	
		if(bitKey & 2)
		{
			this->surroundingTilesStore[1] = this->getMapTile(x , (y - 1)) ;
			this->levelMap[(y - 1)][x] = convertNumberToString(count)[0] ;
		
			count++ ;
		}
	
		if(bitKey & 4)
		{
			this->surroundingTilesStore[2] = this->getMapTile((x + 1) , (y - 1)) ;
			this->levelMap[(y - 1)][(x + 1)] = convertNumberToString(count)[0] ;
		
			count++ ;
		}
	
		if(bitKey & 8)
		{
			this->surroundingTilesStore[3] = this->getMapTile((x + 1) , y) ;
			this->levelMap[y][(x + 1)] = convertNumberToString(count)[0] ;
		
			count++ ;
		}
	
		if(bitKey & 16)
		{
			this->surroundingTilesStore[4] = this->getMapTile((x + 1) , (y + 1)) ;
			this->levelMap[(y + 1)][(x + 1)] = convertNumberToString(count)[0] ;
		
			count++ ;
		}
	
		if(bitKey & 32)
		{
			this->surroundingTilesStore[5] = this->getMapTile(x , (y + 1)) ;
			this->levelMap[(y + 1)][x] = convertNumberToString(count)[0] ;
		
			count++ ;
		}
	
		if(bitKey & 64)
		{
			this->surroundingTilesStore[6] = this->getMapTile((x - 1) , (y + 1)) ;
			this->levelMap[(y + 1)][(x - 1)] = convertNumberToString(count)[0] ;
		
			count++ ;
		}
	
		if(bitKey & 128)
		{
			this->surroundingTilesStore[7] = this->getMapTile((x - 1) , y) ;
			this->levelMap[y][(x - 1)] = convertNumberToString(count)[0] ;
		
			count++ ;
		}
	}
	else
	{	
		if(bitKey & 1)
		{
			this->levelMap[(y - 1)][(x - 1)] = this->surroundingTilesStore[0] ;
		}
	
		if(bitKey & 2)
		{
			this->levelMap[(y - 1)][x] = this->surroundingTilesStore[1] ;
		}
	
		if(bitKey & 4)
		{
			this->levelMap[(y - 1)][(x + 1)] = this->surroundingTilesStore[2] ;
		}
	
		if(bitKey & 8)
		{
			this->levelMap[y][(x + 1)] = this->surroundingTilesStore[3] ;
		}
	
		if(bitKey & 16)
		{
			this->levelMap[(y + 1)][(x + 1)] = this->surroundingTilesStore[4] ;
		}
	
		if(bitKey & 32)
		{
			this->levelMap[(y + 1)][x] = this->surroundingTilesStore[5] ;
		}
	
		if(bitKey & 64)
		{
			this->levelMap[(y + 1)][(x - 1)] = this->surroundingTilesStore[6] ;
		}
	
		if(bitKey & 128)
		{
			this->levelMap[y][(x - 1)] = this->surroundingTilesStore[7] ;
		}
		
		if(this->surroundingTilesStore != NULL)
		{
			delete this->surroundingTilesStore ;
			this->surroundingTilesStore = NULL ;
		}
	}
}

string Level::convertNumberToString(int number)
{
	string convertedNumber ;
	ostringstream convert ;
		
	convert << number ;
	
	convertedNumber = convert.str() ;
	
	return convertedNumber ;
}
