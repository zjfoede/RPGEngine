/*
Virtual class to hold information about interactable objects in the world, and what happens when they are interacted with.
*/

#pragma once

#include <SFML/Graphics.hpp>

#include <string>

#include "CollisionRect.h"

class Interactable
{
public:
	Interactable(){}

	virtual void onTouch(){};
	virtual void onInteract(){};

	virtual void setSolid(bool setting)
	{
		this->solid = setting;
	};

	virtual bool isSolid()
	{
		return this->solid;
	}

	virtual CollisionRect getCollision()
	{
		return collision;
	}

	virtual void setCollision(CollisionRect newCollision)
	{
		collision = newCollision;
	}

	virtual std::string getObjectName()
	{
		return this->objectName;
	}

	virtual void setObjectName(std::string name)
	{
		this->objectName = name;
	}

	~Interactable(void){};

private:
	CollisionRect collision;
	bool solid;
	std::string objectName;
};
