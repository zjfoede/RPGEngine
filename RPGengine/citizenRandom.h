#pragma once
#include "actorinterface.h"
class citizenRandom : public actorInterface
{
public:
	citizenRandom(std::string path, int interval, sf::Vector2i loc);
	~citizenRandom();
	void idle();
	void onInteract();
	void render(sf::RenderWindow& window);
	bool moveX(int offset, int tileWidth);
	bool moveY(int offset, int tileWidth);

private:
	std::string dialog;
	int interval;
};

