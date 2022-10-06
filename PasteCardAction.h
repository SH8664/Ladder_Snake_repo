#pragma once
#include"Action.h"
class PasteCardAction:

	public Action
{
	CellPosition cardposition;
public:
	PasteCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads AddcardAction action parameters (cardposition)

	virtual void Execute();


	virtual ~PasteCardAction(); // Virtual Destructor
};


