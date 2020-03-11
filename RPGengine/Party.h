#pragma once

#include <vector>
#include <map>

#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "Character.h"
#include "CollisionRect.h"

class Party
{
public:
	Party(void);
	Party(Char init);	//initialize with one character
	Party(std::vector<Char> init);    //initialize with many characters
	~Party(void);
	bool addMember(Char toAdd);
	void render(sf::RenderWindow& window);
	void updateInput();
	void update();
	sf::Vector2f pos();
	sf::Vector2f vel();
	void setVel(sf::Vector2f newVel);
	void setPos(sf::Vector2f newPos);
	void move(sf::Vector2f offset);
	CollisionRect collisionBounds();
	bool isInteracting();
private:
	std::vector<Char> members;
	sf::Vector2f currVel;
	std::map<std::string, sf::Keyboard::Key> controls;
	CollisionRect collision;
	bool interacting;
};

