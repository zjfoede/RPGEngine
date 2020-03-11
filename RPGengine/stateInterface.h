#pragma once

#ifndef STATEINTERFACE_H_
#define STATEINTERFACE_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <MapLoader.h>

class stateInterface
{
public:
	stateInterface(){}
	virtual ~stateInterface(){}
	virtual void onEnter() = 0;		//Called when the state is pushed onto the stack in the stateManager.
	virtual void update() = 0;		//Update the state. Handle events such as IO and triggers.
	virtual void render(sf::RenderWindow&) = 0;		//Render the state to the window.
	virtual void onExit() = 0;		//Called when the state is popped from the stack in the stateManager.
};

#endif