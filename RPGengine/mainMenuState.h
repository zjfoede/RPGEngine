#pragma once

#ifndef MAINMENUSTATE_H_
#define MAINMENUSTATE_H_

#include "stateinterface.h"
#include <string>

class mainMenuState : public stateInterface
{
public:
	mainMenuState(std::string path);
	~mainMenuState();
	void onEnter();		//Called when the state is pushed onto the stack in the stateManager.
	void update();		//Update the state. Handle events such as IO and triggers.
	void render(sf::RenderWindow& myWindow);		//Render the state to the window.
	void onExit();		//Called when the state is popped from the stack in the stateManager.

private:
	sf::Sprite mySprite;
	sf::Texture myText;
	int counter;
};

#endif
