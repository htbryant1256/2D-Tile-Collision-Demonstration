#include "Game.h"
#include <iostream>

//Private Functions---------------------------------------------------------------------------------
void Game::initVariables()
{
	this->window = nullptr;
    this->windowWidth = 800;
    this->windowHeight = 600;
}

void Game::initWindow()
{
    this->videoMode.width = windowWidth;
	this->videoMode.height = windowHeight;

	this->window = new sf::RenderWindow(this->videoMode, "C++ RPG", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

//Event polling
void Game::pollEvents()
{    
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
            {
                this->window->close();
                break;
            }
        }
    }
}

//Public Functions---------------------------------------------------------------------------------
//updates game logic
void Game::update()
{
    this->pollEvents();
    //this->player.playerInputUpdate();
    
    //Includes Player Movement
    this->map.mapUpdate(this->map);
}

//essentially display
void Game::render()
{
    //clear window
    this->window->clear(sf::Color::Blue);
    //Draw Map
    this->map.mapRender(this->window, this->map);
    //this->window->draw(this->map.mapSprite);
    
    //Draw Enemies
    //this->window->draw(this->enemy.enemyRect);
   
    //Draw Player
    this->window->draw(this->player.playerRect);

    //display to window
    this->window->display();
}
//Constructors / Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
    this->enemy.initEnemies();
    this->player.initPlayer(this->windowWidth, this->windowHeight);
    this->map.initMap();
    this->map.mapLoad();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}
