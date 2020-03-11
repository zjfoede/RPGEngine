#include "CollisionRect.h"

#include <iostream>
#include <cmath>


CollisionRect::CollisionRect(sf::Vector2f size, sf::Vector2f pos)
{
	bounds.setSize(size);
	bounds.setPosition(pos.x, pos.y);
	bounds.setFillColor(sf::Color(0, 0, 0, 0));		//Fill is blank
	bounds.setOutlineColor(sf::Color::Red);
	bounds.setOutlineThickness(5);
	visible = false;
}

CollisionRect::CollisionRect()
{
	bounds.setSize(sf::Vector2f(0, 0));
	bounds.setPosition(sf::Vector2f(0, 0));
	visible = false;
}

CollisionRect::CollisionRect(sf::FloatRect bounds)
{
	this->bounds.setSize(sf::Vector2f(bounds.width, bounds.height));
	this->bounds.setPosition(sf::Vector2f(bounds.left, bounds.top));
	this->bounds.setFillColor(sf::Color(0, 0, 0, 0));		//Fill is blank
	this->bounds.setOutlineColor(sf::Color::Red);
	this->bounds.setOutlineThickness(5);
	visible = false;
}

void CollisionRect::setVisible(bool visible)
{
	this->visible = visible;
}

bool CollisionRect::isVisible()
{
	return visible;
}

void CollisionRect::setPos(sf::Vector2f newPos)
{
	bounds.setPosition(newPos.x, newPos.y);
}

sf::Vector2f CollisionRect::checkCollision(CollisionRect toCheck)
{
	int xOff, yOff;
	sf::Vector2f offset;
	//x axis
	if (std::min(toCheck.right(), this->right()) - std::max(toCheck.left(), this->left()) > 0)
	{
		if (abs(this->right() - toCheck.left()) > abs(this->left() - toCheck.right()))
		{
			xOff = this->left() - toCheck.right();
		}
		else
		{
			xOff = this->right() - toCheck.left();
		}
		//std::cout << "found x overlap" << std::endl;
	}
	else return offset;
	//y axis
	if (std::min(toCheck.bottom(), this->bottom()) - std::max(toCheck.top(), this->top()) > 0)
	{
		if (abs(this->bottom() - toCheck.top()) > abs(this->top() - toCheck.bottom()))
		{
			yOff = this->top() - toCheck.bottom();
		}
		else
		{
			yOff = this->bottom() - toCheck.top();
		}
		//std::cout << "found y overlap" << std::endl;
	}
	else return offset;
	if (abs(xOff) < abs(yOff))
	{
		//std::cout << "collision on x axis" << std::endl;
		offset.x = xOff;
	}
	else
	{
		//std::cout << "collision on y axis" << std::endl;
		offset.y = yOff;
	}
	return offset;
	//overlap formula: std::min(max1, max2) - std::max(min1, min2) > 0
}

void CollisionRect::render(sf::RenderWindow& window)
{
	if (visible)
	{
		window.draw(bounds);
	}
}

void CollisionRect::move(float x, float y)
{
	bounds.move(x, y);
}

double CollisionRect::top()
{
	return bounds.getGlobalBounds().top;
}

double CollisionRect::bottom()
{
	return bounds.getGlobalBounds().top + bounds.getGlobalBounds().height;
}

double CollisionRect::left()
{
	return bounds.getGlobalBounds().left;
}

double CollisionRect::right()
{
	return bounds.getGlobalBounds().left + bounds.getGlobalBounds().width;
}