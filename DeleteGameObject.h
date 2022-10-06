#pragma once
#include "Action.h"
class DeleteGameObject :
    public Action
{
	CellPosition positionOfObject;
public:
	DeleteGameObject(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters();

	virtual void Execute();
	virtual ~DeleteGameObject(); // A Virtual Destructor
};

