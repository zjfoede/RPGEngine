#pragma once

#include <SFML/Graphics.hpp>

class CollisionRect
{
public:
	CollisionRect(sf::Vector2f size, sf::Vector2f pos);
	CollisionRect();
	CollisionRect(sf::FloatRect bounds);
	void setVisible(bool visible);
	bool isVisible();
	void setPos(sf::Vector2f newPos);
	sf::Vector2f checkCollision(CollisionRect toCheck);		//hacked version of SAT, upgrade? returns offset vector for this rectangle
	void render(sf::RenderWindow& window);
	double top();
	double bottom();
	double left();
	double right();
	void move(float x, float y);

private:
	bool visible;
	sf::RectangleShape bounds;
};

