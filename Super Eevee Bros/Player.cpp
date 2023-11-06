#include <SFML/Graphics.hpp>

#include "Player.h"

#include <iostream>



Player::Player()
{
	if (!texture.loadFromFile("Image/Eevee/Eevee_Stop.png"))
		return;
	sprite = sf::Sprite(texture);
}

Player::~Player()
{
}

void Player::draw(sf::RenderWindow& window, sf::RectangleShape &platforme)
{
	sprite.setScale(1.5f, 1.5f);
	
	if (sprite.getGlobalBounds().intersects(platforme.getGlobalBounds()))
	{
		sprite.setPosition(physics.location.x, physics.location.y);
	}

	window.draw(sprite);

	std::cout << physics.location.x << " / " << physics.location.y << std::endl;

	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);
	//window.draw(shape);
	
}

void Player::inputs()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		physics.location.x += speed;
		sprite.getTexture();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		physics.location.x -= speed;
	}

	if (570 <= physics.location.y && upEnd)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			jump();
		}
	}
	else if (609 > physics.location.y)
	{
		upEnd = false;
	}
	else
	{
		upEnd = true;
	}


}

void Player::jump()
{
	physics.speed.y = -1000;
}


void Player::ticks(const sf::Time& deltaTime)
{
	physics.ticks(deltaTime);

	constexpr float imageSizeY = 291;
	constexpr float imageSizeXd = 270;
	constexpr float imageSizeXg = 1830;
	const float bordery = WINDOW_SIZE_Y - imageSizeY;
	const float borderxd = WINDOW_SIZE_X - imageSizeXd;
	const float borderxg = WINDOW_SIZE_X - imageSizeXg;

	if (physics.location.y > bordery)
	{
		physics.location.y = bordery;
		physics.speed.y = 0;
	}

	if (physics.location.x > borderxd)
	{
		physics.location.x = borderxd;
		physics.speed.x = 0;
	}

	if (physics.location.x < borderxg)
	{
		physics.location.x = borderxg;
		physics.speed.x = 0;
	}
}