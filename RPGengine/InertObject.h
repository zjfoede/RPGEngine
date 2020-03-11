#pragma once
#include "interactable.h"
class InertObject :
	public Interactable
{
public:
	InertObject(void);
	InertObject(CollisionRect collision, bool isSolid, std::string name);
	InertObject(CollisionRect collision, std::string);
	virtual void onInteract();
	virtual void onTouch();
	~InertObject(void);
};

