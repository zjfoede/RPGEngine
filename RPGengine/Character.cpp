#include "Character.h"

#include <iostream>

Char::Char()
{
	coll = CollisionRect(sf::Vector2f(0, 0), sf::Vector2f(0, 0));
	init();
}

void Char::init()
{
	if (!subworldTxt.loadFromFile("resources/images/filler/blankChar.png"))
	{
		std::cout << "no such file!" << std::endl;
	}
	subworld.setTexture(subworldTxt);
	subworld.setPosition(50, 50);
	coll = CollisionRect(sf::Vector2f(subworld.getGlobalBounds().width, subworld.getGlobalBounds().height / 3), 
		sf::Vector2f(subworld.getGlobalBounds().left, subworld.getGlobalBounds().top + subworld.getGlobalBounds().height * 0.67));
	coll.setVisible(0);
}

CollisionRect Char::collisionBounds()
{
	return coll;
}

void Char::setPos(float x, float y)
{
	coll.move(x - subworld.getGlobalBounds().left, y - subworld.getGlobalBounds().top);
	subworld.setPosition(x, y);
}

sf::Vector2f Char::pos()
{
	return sf::Vector2f(subworld.getGlobalBounds().left, subworld.getGlobalBounds().top);
}

void Char::move(float x, float y)
{
	coll.move(x, y);
	subworld.move(x, y);
}

void Char::setVel(double x, double y)
{
	vel.x = x;
	vel.y = y;
}

sf::Vector2f Char::getVel()
{
	return vel;
}

void Char::update()
{
	this->move(vel.x, vel.y);
}

void Char::render(sf::RenderWindow& target)
{
	coll.render(target);
	target.draw(subworld);
}

void Char::levelUp()
{
}

int Char::getDamageDone()		//Returns damage done by standard attack in combat
{
	return 0;
}

int Char::getBlockedDamage()		//Returns the damage blocked in combat;
{
	return 0;
}

void Char::takeDamage()		//Deal damage to the character
{
}