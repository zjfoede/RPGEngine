#include "subworldState.h"
#include "InertObject.h"

#include <iostream>

subworldState::subworldState(std::string path, std::string map)
{
	Char tmp;
	party.addMember(tmp);
	overworldLoader = new tmx::MapLoader(path);
	overworldLoader->Load(map);
	parseMap();
	view = sf::View(sf::Vector2f(party.pos().x, party.pos().y), sf::Vector2f(1920, 1080));
}


subworldState::~subworldState()
{
	delete overworldLoader;
}

void subworldState::onEnter()		//Called when the state is pushed onto the stack in the stateManager.
{
}

void subworldState::update()		//Update the state. Handle input, collision and triggers.
{
	party.updateInput();

	//Check interactables
	for (Interactable* obj : interactables)
	{
		CollisionRect temp = obj->getCollision();
		sf::Vector2f collOffsets = party.collisionBounds().checkCollision(temp);
		//If there is collision
		if (collOffsets.x || collOffsets.y)
		{
			//Stop the party from moving if the object is solid
			if (obj->isSolid())
			{
				if ((collOffsets.x < 0 && party.vel().x < 0) || (collOffsets.x > 0 && party.vel().x > 0))
				{
					party.setVel(sf::Vector2f(0, party.vel().y));
				}
				if ((collOffsets.y < 0 && party.vel().y < 0) || (collOffsets.y > 0 && party.vel().y > 0))
				{
					party.setVel(sf::Vector2f(party.vel().x, 0));
				}
			}
			//Either perform the onTouch event or the onInteract event if there was collision
			if (this->party.isInteracting()) obj->onInteract();
			else obj->onTouch();
		}
	}
	//Check loading zones
	for (int i = 0; i < getLoadZones().size(); i++)
	{
		LoadZone lz = getLoadZones().at(i);
		sf::Vector2f collOffsets = party.collisionBounds().checkCollision(lz.getCollision());
		if (collOffsets.x || collOffsets.y)
		{
			newMap(lz.getMapName());
		}
	}

	//Check map boundaries
	if ((party.collisionBounds().left() < 0 && party.vel().x < 0) || (party.collisionBounds().right() > overworldLoader->GetMapSize().x && party.vel().x > 0))
	{
		//std::cout << "found right/left" << std::endl;
		party.setVel(sf::Vector2f(0, party.vel().y));
	}
	if ((party.collisionBounds().top() < 0 && party.vel().y < 0) || (party.collisionBounds().bottom() > overworldLoader->GetMapSize().y && party.vel().y > 0))
	{
		//std::cout << "found top/bottom" << std::endl;
		party.setVel(sf::Vector2f(party.vel().x, 0));
	}
	party.update();
	//Move the view as the party approaches the border of the screen
	if((party.pos().y > view.getCenter().y + 180 && party.vel().y > 0) || (party.pos().y < view.getCenter().y - 180 && party.vel().y < 0))
	{
		view.move(sf::Vector2f(0, party.vel().y));
	}
	if((party.pos().x > view.getCenter().x + 640 && party.vel().x > 0) || (party.pos().x < view.getCenter().x - 640 && party.vel().x < 0))
	{
		view.move(sf::Vector2f(party.vel().x, 0));
	}
	//Don't move the view beyond the bounds of the map
	if (view.getCenter().x - 960 < 0)
	{
		view.setCenter(960, view.getCenter().y);
	}
	if (view.getCenter().y - 540 < 0)
	{
		view.setCenter(view.getCenter().x, 540);
	}
	if (view.getCenter().x + 960 > overworldLoader->GetMapSize().x)
	{
		view.setCenter(overworldLoader->GetMapSize().x - 960, view.getCenter().y);
	}
	if (view.getCenter().y + 540 > overworldLoader->GetMapSize().y)
	{
		view.setCenter(view.getCenter().x, overworldLoader->GetMapSize().y - 540);
	}

}

void subworldState::render(sf::RenderWindow& myWindow)		//Render the state to the window.
{
	myWindow.setView(view);
	for (int i = 0; i < layers.size(); i++)
	{
		if (layers.at(i).name == "sprt1")
		{
			party.render(myWindow);
			//std::cout << "rendered party" << std::endl;
		}
		overworldLoader->Draw(myWindow, i);
		std::cout << "rendered " << layers.at(i).name << std::endl;
	}
	//std::cin.get();
}

void subworldState::onExit()		//Called when the state is popped from the stack in the stateManager.
{
	//std::cout << "Left the Overwold state!\n";
}

bool subworldState::newMap(std::string path)		//Load a new map. Returns false on failure, true on success.
{
	if (overworldLoader->Load(path))
	{
		layers.clear();
		parseMap();
		return true;
	}
	else return false;
}

std::vector<LoadZone> subworldState::getLoadZones()
{
	return loadZones;
}

//Private functions

void subworldState::parseMap()
{
	layers = overworldLoader->GetLayers();
	loadZones.clear();
	interactables.clear();
	for (int i = 0; i < layers.size(); i++)
	{
		if (layers.at(i).name == "playerStart")
		{
			std::cout << "found playerStart layer" << std::endl;
			if (layers.at(i).objects.size())
			{
				std::cout << "found the playerStart object, coordinates (" << layers.at(i).objects.at(0).GetCentre().x << ", " << layers.at(i).objects.at(0).GetCentre().y << ")" << std::endl;
				party.setPos(layers.at(i).objects.at(0).GetPosition());
			}
		}
		if (layers.at(i).name == "col1") //TODO: generalize collision layer names, add multiple levels support
		{
			for (tmx::MapObject obj : layers.at(i).objects)
			{
				std::string interactType = obj.GetPropertyString("InteractType");
				if (interactType == "Inert")
				{
					interactables.push_back(new InertObject(CollisionRect(obj.GetAABB()), obj.GetName()));
				}
				std::cout << "Found " << interactables.size() << " interactables\n";
			}
		}
		if (layers.at(i).name == "loadZones")
		{
			for (tmx::MapObject obj : layers.at(i).objects)
			{
				this->loadZones.push_back(LoadZone(obj));
			}
		}
	}
}
