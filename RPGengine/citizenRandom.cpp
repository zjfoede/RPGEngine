#include "citizenRandom.h"
#include <cstdlib>


citizenRandom::citizenRandom(std::string path, int interval, sf::Vector2i loc)
{
	this->interval = interval;
	if (!texture.loadFromFile(path))
	{
	}
	sprite.setTexture(texture);
	sprite.setPosition(loc.x, loc.y);
	sprite.setOrigin(sprite.getGlobalBounds().height, sprite.getGlobalBounds().width / 2);
	srand(time(NULL));
}


citizenRandom::~citizenRandom(void)
{
}

void citizenRandom::idle()
{
	int dir = rand() % 4;
	switch (dir)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	}
}

bool citizenRandom::moveX(int offset, int tileWidth)
{
	int pixelsToGo = offset * tileWidth;
	for (int i = 0; i < pixelsToGo; i++)
	{
	}
	return 1;
}

void citizenRandom::render(sf::RenderWindow& window)
{
}

void citizenRandom::onInteract()
{
}