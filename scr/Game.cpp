#include "Game.h"
#include "Player.h"
#include "Draw.h"
#include "Level.h"

#define NULL 0

using std::cin ;
using std::cout ;
using std::endl ;

Game::Game()
{
	this->player = NULL ;
	this->draw = NULL ;
	this->level = NULL ;
}

Game::~Game()
{
	if(this->player != NULL)
	{
		delete this->player ;
		this->player = NULL ;
	}
	
	if(this->draw != NULL)
	{
		delete this->draw ;
		this->draw = NULL ;
	}
	
	if(this->level != NULL)
	{
		delete this->level ;
		this->level = NULL ;
	}
}

int Game::init()
{
	this->player = new Player() ;
	this->player->init(this->requestPlayerClass()) ;
	
	this->draw = new Draw() ;
	
	int temp = 3 ;
	
	temp = this->draw->init() ;
	
	//if(this->draw->init() != 0)
	//{
		//cout << "return -1" << endl ;
		//return -1 ;
	//}
	
	this->level = new Level() ;
	this->level->loadLevel(0 , this->player) ;
	
	this->draw->addMessage("Welcome to Rogue Letters!") ;
	
	return 0 ;
}

void Game::run()
{
	if(this->init() != 0)
	{
        cout << "Should not be here" ;
		return ;
	}
	
	this->draw->updatePlayerStats(this->player) ;
	this->draw->updateMap(this->level->getMap() , this->level->getMapHeight() , this->player->getXLocation() , this->player->getYLocation()) ;
	
	for(int i = 0 ; i < 30 ; i++)
	{
		this->draw->drawScreen() ;
		
		string temp ;
		cin >> temp ;
		
		this->handleKeyboardInput(temp) ;
		
		this->draw->updatePlayerStats(this->player) ;
		this->draw->updateMap(this->level->getMap() , this->level->getMapHeight() , this->player->getXLocation() , this->player->getYLocation()) ;
	}
}

int Game::requestPlayerClass()
{
	do
	{
		string choice ;
		cout << "Player class types:" << endl ;
		cout << "W - Warrior" << endl ;
		cout << "R - Rogue" << endl ;
		cout << "M - Mage" << endl ;
		cout << "Enter your choice: " ;
		cin >> choice ;
	
		if(choice == "W" || choice == "w" || choice == "Warrior" || choice == "warrior")
		{
			cout << "" << endl ;
			cout << "Your sellection: Warrior" << endl ;
			
			return Player::WARRIOR ;
		}
		else if(choice == "R" || choice == "r" || choice == "Rogue" || choice == "rogue")
		{
			cout << "" << endl ;
			cout << "Your sellection: Rogue" << endl ;
			
			return Player::ROGUE ;
		}
		else if(choice == "M" || choice == "m" || choice == "Mage" || choice == "mage")
		{
			cout << "" << endl ;
			cout << "Your sellection: Mage" << endl ;
		
			return Player::MAGE ;
		}
	}
	while(1) ;
}

void Game::handleKeyboardInput(string input)
{
	switch(input[0])
	{
		case 'W' :
		case 'w' :
			
			if(this->level->getMapTile(this->player->getXLocation() , (this->player->getYLocation() - 1)) != ' ')
			{
				int blocked = this->blockedPath(this->level->getMapTile(this->player->getXLocation() , (this->player->getYLocation() - 1))) ;
				if(blocked != -1)
				{
					if(blocked == 1)
					{
						this->player->setYLocation((this->player->getYLocation() - 1)) ;
					}
					else
					{
						this->level->toggleDoor(this->player->getXLocation() , (this->player->getYLocation() - 1)) ;
					}
				}
			}
			else
			{
				this->player->setYLocation((this->player->getYLocation() - 1)) ;
			}
			
			break ;
		
		case 'S' :
		case 's' :
			
			if(this->level->getMapTile(this->player->getXLocation() , (this->player->getYLocation() + 1)) != ' ')
			{
				int blocked = this->blockedPath(this->level->getMapTile(this->player->getXLocation() , (this->player->getYLocation() + 1))) ;
				if(blocked != -1)
				{
					if(blocked == 1)
					{
						this->player->setYLocation((this->player->getYLocation() + 1)) ;
					}
					else
					{
						this->level->toggleDoor(this->player->getXLocation() , (this->player->getYLocation() + 1)) ;
					}
				}
			}
			else
			{
				this->player->setYLocation((this->player->getYLocation() + 1)) ;
			}
			
			break ;
			
		case 'D' :
		case 'd' :
			
			if(this->level->getMapTile((this->player->getXLocation() + 1) , this->player->getYLocation()) != ' ')
			{
				int blocked = this->blockedPath(this->level->getMapTile((this->player->getXLocation() + 1) , this->player->getYLocation())) ;
				if(blocked != -1)
				{
					if(blocked == 1)
					{
						this->player->setXLocation((this->player->getXLocation() + 1)) ;
					}
					else
					{
						this->level->toggleDoor((this->player->getXLocation() + 1) , this->player->getYLocation()) ;
					}
				}
			}
			else
			{
				this->player->setXLocation((this->player->getXLocation() + 1)) ;
			}
			
			break ;
			
		case 'A' :
		case 'a' :
			
			if(this->level->getMapTile((this->player->getXLocation() - 1) , this->player->getYLocation()) != ' ')
			{
				int blocked = this->blockedPath(this->level->getMapTile((this->player->getXLocation() - 1) , this->player->getYLocation())) ;
				if(blocked != -1)
				{
					if(blocked == 1)
					{
						this->player->setXLocation((this->player->getXLocation() - 1)) ;
					}
					else
					{
						this->level->toggleDoor((this->player->getXLocation() - 1) , this->player->getYLocation()) ;
					}
				}
			}
			else
			{
				this->player->setXLocation((this->player->getXLocation() - 1)) ;
			}
			
			break ;
			
		case 'E' :
		case 'e' :
		
			if(this->level->getMapTile(this->player->getXLocation() , this->player->getYLocation()) == 'E')
			{
				this->level->loadLevel(1 , this->player) ;
			}
			else if(this->level->getMapTile(this->player->getXLocation() , this->player->getYLocation()) == '^')
			{
				this->level->loadLevel(-1 , this->player) ;
			}
			else
			{
				int* count ;
				
				count = this->surroundingTileCount(this->player->getXLocation() , this->player->getYLocation()) ;

				if(count[0] > 1)
				{
					
				}
				else
				{
					for(int i = 1 ; i < 9 ; i++)
					{
						if(count[i] == 1)
						{
							cout << i << endl ;
							this->activateTile(i) ;
						}
					}
				}
			}
			
		default :
		
			break ;
	}
}

int Game::blockedPath(char blockage)
{
	int blocked = -1 ;
	switch(blockage)
	{
		case Game::WALL :
		
			this->draw->addMessage("A wall blocks your way.") ;
		
			break ;
			
		case Game::SIGN :
		
			this->draw->addMessage("There is a sign here. It reads:") ;
			//Add functuanality for sign reading here
			
			break ;
			
		case Game::CLOSED_DOOR :
		
			blocked = 0 ;
		
			break ;
			
		case Game::LEVEL_PROGRESS :
		case Game::LEVEL_REGRESS :
		case Game::OPEN_DOOR :
		case Game::ITEM :
		
			blocked = 1 ;
			
			break ;
			
		default :
		
			this->draw->addMessage("Your path is blocked.") ;
			
			break ;
	}
	
	return blocked ;
}
int* Game::surroundingTileCount(int x , int y)
{
	//[x - 1 , y + 1],[x , y + 1],[x + 1 , y + 1]
	//[x - 1 ,   y  ],[ 0  ,  0 ],[x + 1 ,   y 1]
	//[x - 1 , y - 1],[x , y - 1],[x + 1 , y - 1]

	int count[9] ;
	count[0] = 0 ;
	
	char tile = this->level->getMapTile((x - 1) , (y + 1)) ;
	if(tile != '+' && tile != ' ')
	{
		count[0]++ ;
		count[1] = 1 ;
		this->draw->addMessage("TOP LEFT") ;
	}
	
	tile = this->level->getMapTile(x , (y - 1)) ;
	
	if(tile != '+' && tile != ' ')
	{
		count[0]++ ;
		count[2] = 1 ;
		this->draw->addMessage("TOP") ;
	}
	
	tile = this->level->getMapTile((x + 1) , (y - 1)) ;
	
	if(tile != '+' && tile != ' ')
	{
		count[0]++ ;
		count[3] = 1 ;
		this->draw->addMessage("TOP RIGHT") ;
	}
	
	tile = this->level->getMapTile((x + 1) , y) ;
	
	if(tile != '+' && tile != ' ')
	{
		count[0]++ ;
		count[4] = 1 ;
		this->draw->addMessage("RIGHT") ;
	}
	
	tile = this->level->getMapTile((x + 1) , (y + 1)) ;
	
	if(tile != '+' && tile != ' ')
	{
		count[0]++ ;
		count[5] = 1 ;
		this->draw->addMessage("BOTTOM RIGHT") ;
	}
	
	tile = this->level->getMapTile(x , (y + 1)) ;
	
	if(tile != '+' && tile != ' ')
	{
		count[0]++ ;
		count[6] = 1 ;
		this->draw->addMessage("DOWN") ;
	}
	
	tile = this->level->getMapTile((x - 1) , (y + 1)) ;
	
	if(tile != '+' && tile != ' ')
	{
		count[0]++ ;
		count[7] = 1 ;
		this->draw->addMessage("BOTTOM LLEFT") ;
	}
	
	tile = this->level->getMapTile((x - 1) , y) ;
	
	if(tile != '+' && tile != ' ')
	{
		count[0]++ ;
		count[8] = 1 ;
		this->draw->addMessage("LEFT") ;
	}
	
	cout << count[0] << endl ;
	
	return count ;
}

void Game::activateTile(int position)
{
	//[x - 1 , y + 1],[x , y + 1],[x + 1 , y + 1]
	//[x - 1 ,   y  ],[ 0  ,  0 ],[x + 1 ,   y 1]
	//[x - 1 , y - 1],[x , y - 1],[x + 1 , y - 1]

	char tile ;
	int x ;
	int y ;
	
	cout << "HERE" << endl ;
	cout << position  << endl ;
	
	switch(position)
	{
		case 1 :
			
			cout << "Inside" << endl ;
			
			x = (this->player->getXLocation() - 1) ;
			y = (this->player->getYLocation() - 1) ;
			
			cout << "Position set" << endl ;
			
			tile = this->level->getMapTile(x , y) ;
			
			cout << "Got tile: " << tile << endl ;
			
			break ;
		
		case 2 :
		
			x = (this->player->getXLocation()) ;
			y = (this->player->getYLocation() - 1) ;
		
			tile = this->level->getMapTile(x , y) ;
		
			break ;
		
		case 3 :
		
			x = (this->player->getXLocation() + 1) ;
			y = (this->player->getYLocation() - 1) ;
		
			tile = this->level->getMapTile(x , y) ;
		
			break ;
			
		case 4 :
		
			x = (this->player->getXLocation() + 1) ;
			y = (this->player->getYLocation()) ;
		
			tile = this->level->getMapTile(x , y) ;
		
			break ;
			
		case 5 :
		
			x = (this->player->getXLocation() + 1) ;
			y = (this->player->getYLocation() + 1) ;
		
			tile = this->level->getMapTile(x , y) ;
		
			break ;
			
		case 6 :
		
			x = (this->player->getXLocation()) ;
			y = (this->player->getYLocation() + 1) ;
		
			tile = this->level->getMapTile(x , y) ;
		
			break ;
			
		case 7 :
		
			x = (this->player->getXLocation() - 1) ;
			y = (this->player->getYLocation() + 1) ;
		
			tile = this->level->getMapTile((x - 1) , (y + 1)) ;
		
			break ;
			
		case 8 :
		
			tile = this->level->getMapTile((x - 1) , y) ;
		
			break ;
			
		default :
				
			this->draw->addMessage("TOO LARGE") ;
				
			break ;
	}
	
	cout << "HERE" ;
	
	switch(tile)
	{
		case Game::SIGN :
		
			this->draw->addMessage("There is a sign here. It reads:") ;
			//Add functuanality for sign reading here
			
			break ;
			
		case Game::ITEM :
		
			this->draw->addMessage("You have found an item:") ;
			
			break ;
			
		case Game::OPEN_DOOR :
		case Game::CLOSED_DOOR :

			this->level->toggleDoor(x , y) ;

			break ;
			
		default :
		
			break ;
	}
}
