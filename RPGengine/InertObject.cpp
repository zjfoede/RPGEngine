#include "InertObject.h"
#include <iostream>

InertObject::InertObject(void)
{
}

InertObject::InertObject(CollisionRect collision, std::string name)
{
	this->setObjectName(name);
	this->setCollision(collision);
	this->setSolid(true);
}

InertObject::InertObject(CollisionRect collision, bool isSolid, std::string name)
{
	this->setObjectName(name);
	this->setSolid(isSolid);
	this->setCollision(collision);
}

void InertObject::onInteract()
{
	std::cout << "Interacted with inert object '" + this->getObjectName() + "'" << std::endl;
}

void InertObject::onTouch()
{
	std::cout << "Touched inert object '" + this->getObjectName() + "'" << std::endl;
}


InertObject::~InertObject(void)
{
}
