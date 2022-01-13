#include "Player.h"
#include <iostream>
void Player::initPlayer(float width, float height)
{




	this->playerVelocity = sf::Vector2f(0.f, 0.f);

	this->playerSize = sf::Vector2f(25.f, 25.f);
	this->playerCollisionSize = sf::Vector2f(25.f, 20.f);
	this->playerCollisionRect.setPosition(sf::Vector2f(sf::Vector2f((width / 2) - (this->playerCollisionRect.getSize().x / 2), (height / 2) - (this->playerCollisionRect.getSize().y / 2))));


	this->playerSpeed = 5.f;

	//std::cout << "windowWidth: " << width << " windowHeight: " << height << "\n";

	this->playerRect.setSize(playerSize);
	this->playerRect.setFillColor(sf::Color::White);
	//this->playerRect.setOutlineColor(sf::Color::Black);
//	this->playerRect.setOutlineThickness(3);

	this->playerRect.setPosition(sf::Vector2f((width/2) - (this->playerRect.getSize().x / 2), (height/2) - (this->playerRect.getSize().y / 2)));
}

void Player::playerInputUpdate(sf::View& view1)
{

	this->playerVelocity.y = 0;
	this->playerVelocity.x = 0;

	// Player Size

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{

		this->playerSize.x += 1.f;
		this->playerRect.setSize(playerSize);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
	{
		this->playerSize.x -= 1.f;
		this->playerRect.setSize(playerSize);


	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{

		this->playerSize.y += 1.f;
		this->playerRect.setSize(playerSize);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		this->playerSize.y -= 1.f;
		this->playerRect.setSize(playerSize);


	}


	// Player movment
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		
		this->playerRect.move(sf::Vector2f(this->playerSpeed, 0.f));
		this->playerVelocity.x = 5;

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{


		this->playerRect.move(sf::Vector2f(-this->playerSpeed, 0.f));
		this->playerVelocity.x = -5;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		
		this->playerRect.move(sf::Vector2f(0.f, -this->playerSpeed));
		this->playerVelocity.y = -5;

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{

		this->playerRect.move(sf::Vector2f(0.f, this->playerSpeed));
		this->playerVelocity.y = 5;

	}

}
