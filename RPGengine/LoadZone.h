#pragma once
#include "interactable.h"

#include <MapLoader.h>

class LoadZone
{
public:
	LoadZone(tmx::MapObject obj);

	std::string getMapName();
	std::string getEntryPoint();
	std::string getLoadZoneID();
	bool isActive();
	void setActive(bool active);
	CollisionRect getCollision();

	~LoadZone(void);

private:
	bool active;
	CollisionRect collision;
	std::string map;
	std::string entryPoint;
};

