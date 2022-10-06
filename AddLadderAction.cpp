#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	Ladder ladder(startPos,endPos);

	///TODO: Make the needed validations on the read parameters
	if (endPos.GetCellNum() == -1 || startPos.GetCellNum() == -1)
	{
		pGrid->PrintErrorMessage("cancel operation:invalid cell position,click any where to continue");
		
		
	}
	else if (endPos.GetCellNum() == 99 || startPos.GetCellNum() == 1) {
		pGrid->PrintErrorMessage("cancel operation:end cell cannot be last cell and the start cell cannot be the first cell,click any where to continue");

	}
	else if (!ladder.validladder())
   {
		pGrid->PrintErrorMessage("cancel operation:end cell can not be smaller than start cell,click any where to continue");
		
	}
	else if (!ladder.isvertical())
	{
		pGrid->PrintErrorMessage("cancel operation:ladder must be vertiacl,click any where to continue");
		
	}
	else if (pGrid->isoverlapping(&ladder)) {
		pGrid->PrintErrorMessage("cancel operation : two overlapping gameobjects,click any where to continue");
		
	}
	

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Ladder object with the parameters read from the user
	Ladder* pLadder = new Ladder(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the card object to the GameObject of its Cell:
	if (!(startPos.IsValidCell() && endPos.IsValidCell() && pLadder->validladder() && pLadder->isvertical() && !pGrid->isoverlapping(pLadder)&& endPos.GetCellNum() != 99 && startPos.GetCellNum() != 1))
		return;
	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}