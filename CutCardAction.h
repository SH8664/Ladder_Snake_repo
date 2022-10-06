#pragma once
#include "Action.h"
class CutCardAction :
    public Action
{
	CellPosition cardposition;
public:
	CutCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads AddcardAction action parameters (cardposition)

	virtual void Execute(); 


	virtual ~CutCardAction(); // Virtual Destructor
};


