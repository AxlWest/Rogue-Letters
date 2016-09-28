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
	
	for(int i = 0 ; i < 10 ; i++)
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
			
			this->player->setYLocation((this->player->getYLocation() - 1)) ;
			
			break ;
		
		case 'S' :
		case 's' :
			
			this->player->setYLocation((this->player->getYLocation() + 1)) ;
			
			break ;
			
		case 'D' :
		case 'd' :
			
			this->player->setXLocation((this->player->getXLocation() + 1)) ;
			
			break ;
			
		case 'A' :
		case 'a' :
			
			this->player->setXLocation((this->player->getXLocation() - 1)) ;
			
			break ;
			
		default :
		
			break ;
	}
}
