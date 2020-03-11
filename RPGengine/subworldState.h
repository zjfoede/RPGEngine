#pragma once

#ifndef SUBWORLDSTATE_H_
#define SUBWOLRDSTATE_H_

#include "stateinterface.h"
#include "Party.h"
#include "Interactable.h"
#include "LoadZone.h"

#include <string>
#include <vector>
#include <cmath>

class subworldState : public stateInterface
{
public:
	subworldState(std::string path, std::string map);		//Takes the path to the directory containing overworld maps
	~subworldState();
	void onEnter();		//Called when the state is pushed onto the stack in the stateManager.
	void update();		//Update the state. Handle events such as IO and triggers.
	void render(sf::RenderWindow& myWindow);		//Render the state to the window.
	void onExit();		//Called when the state is popped from the stack in the stateManager.
	std::vector<LoadZone> getLoadZones();	//Get the map's load zones
	bool newMap(std::string path);

private:
	void parseMap();

	Party party;
	sf::View view;
	sf::Sprite mySprite;
	sf::Texture myTexture;
	tmx::MapLoader* overworldLoader;	//Loader for the map
	std::vector<tmx::MapLayer> layers;	//Parsed layers of the map
	std::vector<Interactable*> interactables;  //Contains all objects that the player can collide or interact with
	std::vector<LoadZone> loadZones;	//Contains the map's loading zones
};

#endif
