#pragma once

#ifndef STATEMANAGER_H_
#define STATEMANAGER_H_

// An object that uses a stack to control the current state.

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <string>
#include <stack>

#include "stateInterface.h"

class StateStack
{
public:
	StateStack();
	~StateStack(void);
	void update();
	void render(sf::RenderWindow& gameWindow);
	void push(stateInterface* newState);
	void pop();

private:
	std::stack<stateInterface*> states;
	stateInterface* active;
};

#endif