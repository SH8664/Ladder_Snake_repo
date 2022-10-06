#pragma once
#include "Action.h"
class CopyCardAction :
    public Action
{
    CellPosition cardposition;
public:
	CopyCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads AddcardAction action parameters (cardposition)

	virtual void Execute(); 

	virtual ~CopyCardAction(); // Virtual Destructor
};

