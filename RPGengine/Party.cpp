#include "Party.h"

#include <iostream>
#include <cmath>


Party::Party(void)
{
	controls["up"] = sf::Keyboard::W;
	controls["down"] = sf::Keyboard::S;
	controls["left"] = sf::Keyboard::A;
	controls["right"] = sf::Keyboard::D;
	controls["run"] = sf::Keyboard::LShift;
	controls["interact"] = sf::Keyboard::Space;
	currVel = sf::Vector2f(0, 0);
}

Party::Party(Char init)	//initialize with one character
{
	controls["up"] = sf::Keyboard::W;
	controls["down"] = sf::Keyboard::S;
	controls["left"] = sf::Keyboard::A;
	controls["right"] = sf::Keyboard::D;
	controls["run"] = sf::Keyboard::LShift;
	controls["interact"] = sf::Keyboard::Space;
	currVel = sf::Vector2f(0, 0);
	members.push_back(init);
	members.at(members.size() - 1).init();
}

Party::Party(std::vector<Char> init)    //initialize with many characters
{
	controls["up"] = sf::Keyboard::W;
	controls["down"] = sf::Keyboard::S;
	controls["left"] = sf::Keyboard::A;
	controls["right"] = sf::Keyboard::D;
	controls["run"] = sf::Keyboard::LShift;
	controls["interact"] = sf::Keyboard::Space;
	currVel = sf::Vector2f(0, 0);
	members = init;
}

Party::~Party(void)
{
}

void Party::setPos(sf::Vector2f newPos)
{
	if (members.size())
	{
		members.at(0).setPos(newPos.x, newPos.y);
	}
}

CollisionRect Party::collisionBounds()
{
	if (members.size())
	{
		return members.at(0).collisionBounds();
	}
	else
	{
		CollisionRect blank;
		return blank;
	}
}

bool Party::addMember(Char toAdd)
{
	members.push_back(toAdd);
	members.at(members.size() - 1).init();
	//std::cout << "called init on party member " << members.size() - 1 << std::endl;
	return true;
}

void Party::render(sf::RenderWindow& window)
{
	/*for (int i = 0; i < members.size(); i++)
	{
		members.at(i).render(window);
	}*/
	if (members.size()) members.at(0).render(window);
}

sf::Vector2f Party::pos()
{
	if (members.size())
	{
		return sf::Vector2f(members[0].pos().x, members[0].pos().y);
	}
	else
	{
		return sf::Vector2f(-1, -1);
	}
}

sf::Vector2f Party::vel()
{
	if (members.size())
	{
		return members.at(0).getVel();
	}
	else
	{
		return sf::Vector2f(0, 0);
	}
}

void Party::updateInput()
{
	if (!members.size()) return;
	//Check for input
	currVel = sf::Vector2f(0, 0);
	int modifier = 1;
	if (sf::Keyboard::isKeyPressed(controls["run"]))
	{
		modifier = 2.5;
	}
	if (sf::Keyboard::isKeyPressed(controls["up"]))
	{
		//std::cout << "pressed up" << std::endl;
		setVel(sf::Vector2f(members.at(0).getVel().x, -3 * modifier));
	}
	else if (sf::Keyboard::isKeyPressed(controls["down"]))
	{
		setVel(sf::Vector2f(members.at(0).getVel().x, 3 * modifier));
	}
	else
	{
		setVel(sf::Vector2f(members.at(0).getVel().x, 0));
	}
	if (sf::Keyboard::isKeyPressed(controls["left"]))
	{
		setVel(sf::Vector2f(-3 * modifier, members.at(0).getVel().y));
	}
	else if (sf::Keyboard::isKeyPressed(controls["right"]))
	{
		setVel(sf::Vector2f(3 * modifier, members.at(0).getVel().y));
	}
	else
	{
		setVel(sf::Vector2f(0, members.at(0).getVel().y));
	}
}

void Party::update()
{
	//sf::Vector2f tempVel1;
	//sf::Vector2f tempVel2;
	if (members.size())
	{
		//tempVel1 = members.at(0).getVel();
		members.at(0).update();
	}
	/*if (members.size() > 1)
	{
		for (int i = 1; i < members.size(); i++)
		{
			tempVel2 = members.at(i).getVel();
			members.at(i).setVel(tempVel1.x, tempVel1.y);
			tempVel1 = tempVel2;
			members.at(i).update();
		}
	}*/
}

void Party::setVel(sf::Vector2f newVel)
{
	if (members.size()) members.at(0).setVel(newVel.x, newVel.y);
}

void Party::move(sf::Vector2f offset)
{
	for (int i = 0; i < members.size(); i++)
	{
		members.at(i).move(offset.x, offset.y);
	}
}

bool Party::isInteracting()
{
	return sf::Keyboard::isKeyPressed(controls["interact"]);
}