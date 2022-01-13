#include "Map.h"
#include <iostream>
void Map::initMap()
{
	

	this->mapScale = .5;
	//this->playerSpeed = 5.f;

    this->grass.loadFromFile("Images/Grass 001.png");
    this->grassTile.setTexture(grass);
    this->grassTile.setPosition(sf::Vector2f(0.f, 0.f));
	this->grassTile.setScale(sf::Vector2f(this->mapScale , this->mapScale));

	this->grassTree.loadFromFile("Images/Grass 001.png");
	this->grassTreeTile.setTexture(grassTree);
	this->grassTreeTile.setPosition(sf::Vector2f(0.f, 0.f));
	this->grassTreeTile.setScale(sf::Vector2f(this->mapScale, this->mapScale));

	this->wallTile.setFillColor(sf::Color::White);
	this->wallTile.setSize(sf::Vector2f(160.f, 80.f));
	this->wallTile.setPosition(sf::Vector2f(0.f, 0.f));
	this->wallTile.setOutlineColor(sf::Color::Black);
	this->wallTile.setOutlineThickness(3);

	this->file.open("Map/map.txt");
	for (int row = 0; row < 10; row++) {
		for (int column = 0; column < 10; column++) {
			file >> this->mapArray[row][column];
		}
	}
	file.close();
}

void Map::mapUpdate(sf::RenderWindow* window, Map &map)
{
	for (auto& e : map.tileVector)
	{
		//e.setRotation(45.f);
		//e.setScale(sf::Vector2f(1.f, 1.f));
		if ((260 > e.getGlobalBounds().top) & (160 < e.getGlobalBounds().top) & (420 > e.getGlobalBounds().left) & (220 < e.getGlobalBounds().left))
		{

			//std::cout << e.getGlobalBounds();
			e.setColor(sf::Color::Red);
			window->draw(e);
		}
	}
}

void Map::mapLoad()
{
	for (int row = 0; row < 10; row++) {

		this->grassTile.setPosition(sf::Vector2f(0.f, row * 128.f));
		this->grassTreeTile.setPosition(sf::Vector2f(0.f, row * 128.f));


		for (int column = 0; column < 10; column++) {
			if (mapArray[row][column] == '1')
			{
				this->tileVector.push_back(this->grassTile);
				this->grassTreeTile.move(sf::Vector2f(128.f, 0.f));

				this->grassTile.move(sf::Vector2f(128.f, 0.f));
			}
			if (mapArray[row][column] == '0')
			{
				//this->tileVector.push_back(this->grassTile);
				this->grassTreeTile.move(sf::Vector2f(128.f, 0.f));

				this->grassTile.move(sf::Vector2f(128.f, 0.f));
			}
			if (mapArray[row][column] == '2')
			{
				this->tileCollisionVector.push_back(this->grassTreeTile);

				this->grassTreeTile.move(sf::Vector2f(128.f, 0.f));
				
				this->grassTile.move(sf::Vector2f(128.f, 0.f));
			}
		}
	}
}

void Map::mapRender(sf::RenderWindow *window, Map &map, Player &player)
{
	bool colliding = false;
	bool leftCollide = false;
	for (auto& e : map.tileCollisionVector)
	{
		if (e.getGlobalBounds().width >= player.playerRect.getGlobalBounds().left > e.getGlobalBounds().left)
		{
			leftCollide = true;
			std::cout << "LeftCollide True\n";
		}
		if (e.getGlobalBounds().intersects(player.playerRect.getGlobalBounds()))
		{
			colliding = true;
			/*
			std::cout << "INTERSECTING\n";
			std::cout << "e.globalBounds.top: " << e.getGlobalBounds().top << "\n";
			std::cout << "e.globalBounds.top + 125: " << e.getGlobalBounds().top + 125 << "\n";

			std::cout << "e.globalBounds.left: " << e.getGlobalBounds().left << "\n";
			std::cout << "player.globalBounds.top: " << player.playerRect.getGlobalBounds().top << "\n";
			std::cout << "player.globalBounds.left: " << player.playerRect.getGlobalBounds().left << "\n";
			
			if (e.getGlobalBounds().top >= player.getGlobalBounds().top)
			{
				std::cout << "BOTTOM COLLIDING\n";

				player.move(sf::Vector2f(0.f, -5));
				
			}
			
			 if (e.getGlobalBounds().left <= player.getGlobalBounds().left)
			{
				std::cout << "LEFT COLLIDING\n";

				player.move(sf::Vector2f(5.f, 0));

			}
			if (e.getGlobalBounds().top + 125 >= player.getGlobalBounds().top)
			{
				std::cout << "TOP COLLIDING\n";

				player.move(sf::Vector2f(0.f, 5));

			}
			 if (e.getGlobalBounds().left + 125 >= player.getGlobalBounds().left)
			{
				std::cout << "RIGHT COLLIDING\n";

				player.move(sf::Vector2f(-5.f, 0));

			}
			*/



			//std::cout << e.getGlobalBounds();
			e.setColor(sf::Color::Blue);
			window->draw(e);


		}
		else
		{
			//std::cout << "test\n";

			e.setColor(sf::Color::Black);
			window->draw(e);
		}


		//std::cout << "test\n";


	}
	if (colliding)
	{
		player.playerRect.move(sf::Vector2f(-player.playerVelocity.x, -player.playerVelocity.y));
	}

	
	else if (!colliding)
	{

	}


	/*
	if (colliding && (player.playerVelocity.y < 0) && (player.playerVelocity.y > 0))
	{
		player.playerRect.move(sf::Vector2f(0, -player.playerVelocity.y));
	}
	if (colliding && (player.playerVelocity.y > 0))
	{
		player.playerRect.move(sf::Vector2f(0, -player.playerVelocity.y));
	}

	if (colliding && (player.playerVelocity.x < 0))
	{
		player.playerRect.move(sf::Vector2f(-player.playerVelocity.x, 0));
	}
	if (colliding && (player.playerVelocity.x > 0))
	{
		player.playerRect.move(sf::Vector2f(-player.playerVelocity.x, 0));
	}
	*/



	/*
	if (colliding && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		
		player.playerRect.move(sf::Vector2f(10.f, 0.f));
	}
	if (colliding && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{

		player.playerRect.move(sf::Vector2f(-10.f, 0.f));
	}
	if (colliding && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{

		player.playerRect.move(sf::Vector2f(0.f, 10.f));
	}
	if (colliding && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{

		player.playerRect.move(sf::Vector2f(0.f, -10.f));
	}
	*/
	for (auto& e : map.tileVector)
	{
		//e.setRotation(45.f);
		//e.setScale(sf::Vector2f(1.f, 1.f));
		if (e.getGlobalBounds().intersects(player.playerRect.getGlobalBounds()))
		{

			//std::cout << e.getGlobalBounds();
			e.setColor(sf::Color::Red);
			window->draw(e);
			
		}
		else
		{
			e.setColor(sf::Color::Green);
			window->draw(e);
		}


		

	
		//sf::RectangleShape origin;
		//origin.setPosition(sf::Vector2f(400.f, 300.f));
	//	origin.setSize(sf::Vector2f(100.f, 100.f));
		//origin.setFillColor(sf::Color::Red);
//		if (e.getGlobalBounds().contains(sf::Vector2f(400.f, 300.f)))
	//	{
//			e.setColor(sf::Color::Blue);
	//		window->draw(e);
	//	}
		//window->draw(origin);

	//	if ((240 > e.getGlobalBounds().top) &! (400 > e.getGlobalBounds().left))
	//	{
	//		e.setColor(sf::Color::Green);
	//		window->draw(e);
	//	}
		

		
		//std::cout << this->playerData.playerRect.getGlobalBounds().top << "\n";
	}

}
