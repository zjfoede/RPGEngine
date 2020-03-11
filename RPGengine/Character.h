#pragma once

#ifndef CHAR_H_
#define CHAR_H_

#include <SFML/Graphics.hpp>

#include <string>

#include "CollisionRect.h"

class Char
{
public:
	Char();
	void levelUp();
	int getDamageDone();		//Returns damage done by standard attack in combat
	int getBlockedDamage();		//Returns the damage blocked in combat;
	void takeDamage();		//Deal damage to the character
	void setPos(float x, float y);
	void move(float x, float y);
	void render(sf::RenderWindow& target);
	void init();
	void setVel(double x, double y);
	sf::Vector2f getVel();
	sf::Vector2f pos();
	void update();
	CollisionRect collisionBounds();

private:
	std::string name;		//Character name
	CollisionRect coll;
	sf::Vector2f vel;
	  //--------------//
	 // Battle Stats //
	//--------------//
	int maxHP;
	int currentHP;
	int maxMP;
	int currentMP;
	int strength;
	int defense;
	int speed;
	int magic;
	int exp;
	int toNextLevel;
	  //----------//
	 // Graphics //
	//----------//
	sf::Texture subworldTxt;
	sf::Sprite overworld;		//Sprite that appears in the overworld
	sf::Sprite subworld;		//Sprite that appears in cities and dungeons
	sf::Sprite portrait;		//A portrait for menus;
	  //-------//
	 // Sound //
	//-------//
	//In development
};

#endif