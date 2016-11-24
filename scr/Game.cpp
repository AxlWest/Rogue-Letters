#include "Game.h"
#include "Player.h"
#include "Draw.h"
#include "Level.h"
#include "Enemy.h"

#include <curses.h>
#include <ncurses.h>

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
	initscr() ;
	cbreak();
	echo() ; //Allows the user to see his input
	
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
	
	noecho() ; //Does not display the users input
	curs_set(0) ; //Make the curser invisible
	clear() ; //Clears the screen
	
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
	
	for(int i = 0 ; i < 100 ; i++)
	{
		this->draw->drawScreen() ;
		
		string temp ;
		temp = getUserInput() ;
		
		this->handleKeyboardInput(temp) ;
		
		this->draw->updatePlayerStats(this->player) ;
		this->draw->updateMap(this->level->getMap() , this->level->getMapHeight() , this->player->getXLocation() , this->player->getYLocation()) ;
	}
	
	endwin() ;
}

char Game::getUserInput()
{
	char input ;
	
	do
	{
		if((input = getch()) == ERR)
		{
		  //No input
		}
		else
		{
		  return input ;
		}	
	}
	while(1) ;
}

int Game::requestPlayerClass()
{
	do
	{
		string choice ;
		/*cout << "Player class types:" << endl ;
		cout << "W - Warrior" << endl ;
		cout << "R - Rogue" << endl ;
		cout << "M - Mage" << endl ;
		cout << "Enter your choice: " ;*/
		
		printw("W - Warrior\n") ;
		printw("R - Rogue\n") ;
		printw("M - Mage\n") ;
		printw("Enter your choice: ") ;
		refresh() ;
		
		//cin >> choice ;
		choice = getUserInput() ;
	
		if(choice == "W" || choice == "w" || choice == "Warrior" || choice == "warrior")
		{
			printw("\n") ;
			printw("Your sellection: Warrior\n") ;
			
			return Player::WARRIOR ;
		}
		else if(choice == "R" || choice == "r" || choice == "Rogue" || choice == "rogue")
		{
			printw("\n") ;
			printw("Your sellection: Rogue\n") ;
			
			return Player::ROGUE ;
		}
		else if(choice == "M" || choice == "m" || choice == "Mage" || choice == "mage")
		{
			printw("\n") ;
			printw("Your sellection: Mage\n") ;
		
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
					int bitKey = 0 ;
					int* countKey = NULL ;
					
					int k = 0 ;
					countKey = new int[8] ;
					
					for(int i = 0 ; i < 8 ; i++)
					{
						if(count[(i + 1)] == 1)
						{
							bitKey ^= 1 << i ;
							countKey[k] = (i + 1) ;
							k++ ;
						}
					}
					
					this->level->toggleSurroundingTiles(bitKey , this->player->getXLocation() , this->player->getYLocation()) ;
					
					int tileChoice = 0 ;
					
					tileChoice = this->surroundingTileInput(bitKey , count[0]) ;
					
					this->activateTile(countKey[tileChoice - 1]) ;
					
					if(count != NULL)
					{
						delete count ;
						count = NULL ;
					}
					
					if(countKey != NULL)
					{
						delete countKey ;
						countKey = NULL ;
					}
				}
				else
				{
					for(int i = 1 ; i < 9 ; i++)
					{
						if(count[i] == 1)
						{
							//cout << i << endl ;
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

	int* count = NULL ;
	
	count = new int[9] ;
	
	count[0] = 0 ;
	
	char tile = this->level->getMapTile((x - 1) , (y + 1)) ;
	if(tile != '+' && tile != ' ')
	{
		count[0]++ ;
		count[1] = 1 ;
		//this->draw->addMessage("TOP LEFT") ;
	}
	
	tile = this->level->getMapTile(x , (y - 1)) ;
	
	if(tile != '+' && tile != ' ')
	{
		count[0]++ ;
		count[2] = 1 ;
		//this->draw->addMessage("TOP") ;
	}
	
	tile = this->level->getMapTile((x + 1) , (y - 1)) ;
	
	if(tile != '+' && tile != ' ')
	{
		count[0]++ ;
		count[3] = 1 ;
		//this->draw->addMessage("TOP RIGHT") ;
	}
	
	tile = this->level->getMapTile((x + 1) , y) ;
	
	if(tile != '+' && tile != ' ')
	{
		count[0]++ ;
		count[4] = 1 ;
		//this->draw->addMessage("RIGHT") ;
	}
	
	tile = this->level->getMapTile((x + 1) , (y + 1)) ;
	
	if(tile != '+' && tile != ' ')
	{
		count[0]++ ;
		count[5] = 1 ;
		//this->draw->addMessage("BOTTOM RIGHT") ;
	}
	
	tile = this->level->getMapTile(x , (y + 1)) ;
	
	if(tile != '+' && tile != ' ')
	{
		count[0]++ ;
		count[6] = 1 ;
		//this->draw->addMessage("DOWN") ;
	}
	
	tile = this->level->getMapTile((x - 1) , (y + 1)) ;
	
	if(tile != '+' && tile != ' ')
	{
		count[0]++ ;
		count[7] = 1 ;
		//this->draw->addMessage("BOTTOM LLEFT") ;
	}
	
	tile = this->level->getMapTile((x - 1) , y) ;
	
	if(tile != '+' && tile != ' ')
	{
		count[0]++ ;
		count[8] = 1 ;
		//this->draw->addMessage("LEFT") ;
	}
	
	//cout << count[0] << endl ;
	
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
	
	switch(position)
	{
		case 1 :
			
			x = (this->player->getXLocation() - 1) ;
			y = (this->player->getYLocation() - 1) ;
			
			tile = this->level->getMapTile(x , y) ;
			
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
		
			tile = this->level->getMapTile(x , y) ;
		
			break ;
			
		case 8 :
			
			x = (this->player->getXLocation() - 1) ;
			y = (this->player->getYLocation()) ;
			
			tile = this->level->getMapTile(x , y) ;
		
			break ;
			
		default :
				
			this->draw->addMessage("TOO LARGE") ;
				
			break ;
	}
	
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

int Game::surroundingTileInput(int bitKey , int count)
{
	bool toggled = true ;
	
	string surroundingTileInput ;
					
	this->draw->addMessage("Select tile to activate (Press ""t"" to toggle).") ;
	
	this->draw->updateMap(this->level->getMap() , this->level->getMapHeight() , this->player->getXLocation() , this->player->getYLocation()) ;
	
	do
	{
		this->draw->drawScreen() ;
		//cin >> surroundingTileInput ;
		surroundingTileInput = getUserInput() ;
	
		//cout << count << endl ;
		
		switch(surroundingTileInput[0])
		{
			case '1' :
				
				if(1 <= count)
				{
					if(toggled == true)
					{
						this->level->toggleSurroundingTiles(bitKey , this->player->getXLocation() , this->player->getYLocation()) ;
					}
				
					return 1 ;
				}
			
				break ;
				
			case '2' :
			
				if(2 <= count)
				{
					if(toggled == true)
					{
						this->level->toggleSurroundingTiles(bitKey , this->player->getXLocation() , this->player->getYLocation()) ;
					}
				
					return 2 ;
				}
			
				break ;
				
			case '3' :
			
				if(3 <= count)
				{
					if(toggled == true)
					{
						this->level->toggleSurroundingTiles(bitKey , this->player->getXLocation() , this->player->getYLocation()) ;
					}
				
					return 3 ;
				}
				
				break ;
				
			case '4' :
			
				if(4 <= count)
				{
					if(toggled == true)
					{
						this->level->toggleSurroundingTiles(bitKey , this->player->getXLocation() , this->player->getYLocation()) ;
					}
				
					return 4 ;
				}
				
				break ;
				
			case '5' :
			
				if(5 <= count)
				{
					if(toggled == true)
					{
						this->level->toggleSurroundingTiles(bitKey , this->player->getXLocation() , this->player->getYLocation()) ;
					}
				
					return 5 ;
				}
				
				break ;
				
			case '6' :
			
				if(6 <= count)
				{
					if(toggled == true)
					{
						this->level->toggleSurroundingTiles(bitKey , this->player->getXLocation() , this->player->getYLocation()) ;
					}
				
					return 6 ;
				}
				
				break ;
				
			case '7' :
			
				if(7 <= count)
				{
					if(toggled == true)
					{
						this->level->toggleSurroundingTiles(bitKey , this->player->getXLocation() , this->player->getYLocation()) ;
					}
				
					return 7 ;
				}
				
				break ;
				
			case '8' :
			
				if(8 <= count)
				{
					if(toggled == true)
					{
						this->level->toggleSurroundingTiles(bitKey , this->player->getXLocation() , this->player->getYLocation()) ;
					}
				
					return 8 ;
				}
			
				break ;
				
			case 't' :
			case 'T' :
			
				this->level->toggleSurroundingTiles(bitKey , this->player->getXLocation() , this->player->getYLocation()) ;
				
				if(toggled == true)
				{
					toggled = false ;
				}
				else
				{
					toggled = true ;
				}
				
				this->draw->updateMap(this->level->getMap() , this->level->getMapHeight() , this->player->getXLocation() , this->player->getYLocation()) ;
			
				break ;
				
			default :
			
				//cout << "ARGG!!" << endl ;
			
				break ;
		}
	}
	while(1) ;
}
