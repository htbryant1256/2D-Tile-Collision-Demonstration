#include "Player.h"
#include <iostream>
void Player::initPlayer(float width, float height)
{
	this->playerSize = sf::Vector2f(25.f, 50.f);
	this->playerCollisionSize = sf::Vector2f(25.f, 20.f);


	this->playerCollisionRect.setSize(playerCollisionSize);
	//this->playerSpeed = 5.f;

	//std::cout << "windowWidth: " << width << " windowHeight: " << height << "\n";

	this->playerRect.setSize(playerSize);
	this->playerRect.setFillColor(sf::Color::White);
	//this->playerRect.setOutlineColor(sf::Color::Black);
//	this->playerRect.setOutlineThickness(3);

	this->playerRect.setPosition(sf::Vector2f((width/2) - (this->playerRect.getSize().x / 2), (height/2) - (this->playerRect.getSize().y / 2)));
}

void Player::playerInputUpdate()
{

}