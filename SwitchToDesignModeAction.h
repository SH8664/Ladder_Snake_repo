#pragma once
#include "Action.h"
#include"Grid.h"
#include"Player.h"
#include"CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"
class SwitchToDesignModeAction :
    public Action
{ 

public:
	SwitchToDesignModeAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters();

	virtual void Execute();
	virtual ~SwitchToDesignModeAction(); // A Virtual Destructor
};

