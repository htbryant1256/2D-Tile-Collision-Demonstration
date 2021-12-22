#include "Map.h"
#include <iostream>
void Map::initMap()
{
	this->wallTile.setFillColor(sf::Color::Black);
	this->wallTile.setSize(sf::Vector2f(100.f, 100.f));
	this->wallTile.setPosition(sf::Vector2f(0.f, 0.f));

	this->mapScale = 4.f;
	this->playerSpeed = 5.f;

    this->map.loadFromFile("Images/background.jpg");
    this->mapSprite.setTexture(map);
    this->mapSprite.setPosition(sf::Vector2f(0.f, 0.f));
	this->mapSprite.setScale(sf::Vector2f(this->mapScale , this->mapScale));
	this->file.open("Map/map.txt");
	for (int row = 0; row < 50; row++) {
		for (int column = 0; column < 50; column++) {
			file >> this->mapArray[row][column];
		}
	}
	file.close();
}

void Map::mapUpdate(Map &map)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		for (auto& e : map.tileVector)
		{
			e.move(sf::Vector2f(0.f, this->playerSpeed));
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		for (auto& e : map.tileVector)
		{
			e.move(sf::Vector2f(this->playerSpeed, 0.f));
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		for (auto& e : map.tileVector)
		{
			e.move(sf::Vector2f(0.f, -this->playerSpeed));
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		for (auto& e : map.tileVector)
		{
			e.move(sf::Vector2f(-this->playerSpeed, 0.f));
		}
	}
}

void Map::mapLoad()
{
	for (int row = 0; row < 50; row++) {
		this->wallTile.setPosition(sf::Vector2f(0.f, row * this->wallTile.getSize().y));
		for (int column = 0; column < 50; column++) {
			//std::cout << map.mapArray[row][column] << "";
			if (mapArray[row][column] == '1')
			{
				this->tileVector.push_back(this->wallTile);
				this->wallTile.move(sf::Vector2f(this->wallTile.getSize().x, 0.f));
				//this->window->draw(this->map.wallTile);

			}
			if (mapArray[row][column] == '0')
			{
				//this->tileVector.push_back(this->map.wallTile);
				this->wallTile.move(sf::Vector2f(this->wallTile.getSize().x, 0.f));
				//this->window->draw(this->map.wallTile);

			}
		}
		//  std::cout << std::endl;
	}
}

void Map::mapRender(sf::RenderWindow *window, Map &map)
{
	for (auto& e : map.tileVector)
	{
		window->draw(e);
	}

}
