#include "AddSnakeAction.h"
#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	Snake snake(startPos, endPos);

	///TODO: Make the needed validations on the read parameters
	if (endPos.GetCellNum() == -1 || startPos.GetCellNum() == -1)
	{
		pOut->PrintMessage("cancel operation:invalid cell position");
		return;
		
	}
	else if (!snake.validsnake())
	{
		pOut->PrintMessage("cancel operation:end cell can not be larger than start cell");
		return;
	}
	else if (!snake.isvertical())
	{
		pOut->PrintMessage("cancel operation:snake must be vertiacl");
		return;
		
	}
	else if (pGrid->isoverlapping(&snake)) {
		pOut->PrintMessage("cancel operation : two overlapping gameobjects");
		return;
	}


	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a card object with the parameters read from the user
	Snake* psnake = new Snake(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the snake object to the GameObject of its Cell:
	if (!(startPos.IsValidCell() && endPos.IsValidCell() && psnake->validsnake() && psnake->isvertical() && !pGrid->isoverlapping(psnake)))
		return;
	bool added = pGrid->AddObjectToCell(psnake);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the snake is created and added to the GameObject of its Cell, so we finished executing the addsnakeaction

}