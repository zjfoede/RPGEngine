#include "LoadZone.h"


LoadZone::LoadZone(tmx::MapObject obj)
{
	active = true;
	collision = CollisionRect(obj.GetAABB());
	map = obj.GetPropertyString("MapToLoad");
	entryPoint = obj.GetPropertyString("LocationToLoad");
}

std::string LoadZone::getMapName()
{
	return map;
}

std::string LoadZone::getLoadZoneID()
{
	return entryPoint;
}

bool LoadZone::isActive()
{
	return active;
}

void LoadZone::setActive(bool active)
{
	this->active = active;
}

CollisionRect LoadZone::getCollision()
{
	return collision;
}


LoadZone::~LoadZone(void)
{
}
