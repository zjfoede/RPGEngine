#include "StateStack.h"

StateStack::StateStack()
{
}

StateStack::~StateStack()
{
}

void StateStack::update()
{
	states.top()->update();
}

void StateStack::render(sf::RenderWindow& gameWindow)
{
	states.top()->render(gameWindow);
}

void StateStack::push(stateInterface* newState)
{
	if (states.size() > 0)
	{
		states.top()->onExit();
	}
	states.push(newState);
	states.top()->onEnter();
}

void StateStack::pop()
{
	states.top()->onExit();
	stateInterface* toDelete = states.top();
	delete toDelete;
	states.pop();
	if (states.size() > 0)
	{
		states.top()->onEnter();
	}
}