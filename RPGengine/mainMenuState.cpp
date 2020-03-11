#include "mainMenuState.h"
#include <iostream>

mainMenuState::mainMenuState(std::string path)
{
	counter = 0;
	if (!myText.loadFromFile(path));
	{
		std::cout << "Ya done messed up!!!\n";
	}
	mySprite.setTexture(myText);
	mySprite.setPosition(0, 0);
}


mainMenuState::~mainMenuState()
{
}

void mainMenuState::onEnter()		//Called when the state is pushed onto the stack in the stateManager.
{
	std::cout << "Entered the Main Menu state!\n";
}

void mainMenuState::update()		//Update the state. Handle events such as IO and triggers.
{

}

void mainMenuState::render(sf::RenderWindow& myWindow)		//Render the state to the window.
{
	myWindow.draw(mySprite);
}

void mainMenuState::onExit()		//Called when the state is popped from the stack in the stateManager.
{
	std::cout << "Left the Main Menu state!\n";
}
