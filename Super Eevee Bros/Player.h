#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "vector2D.h"
#include "physics.h"

namespace sf
{
	class RenderWindow;
	class Time;
};

class Player
{
private:
	static constexpr float speed = 5.f;
	//vector2D location = vector2D(0, 0);
	Physics physics;

	sf::Texture texture;
	sf::Sprite sprite;

	bool upEnd = true;

	void jump();

public:
	

	Player();
	~Player();

	void draw(sf::RenderWindow& window);
	void inputs(std::vector<sf::RectangleShape>& platforme);
	void ticks(const sf::Time& deltaTime);

};

#endif