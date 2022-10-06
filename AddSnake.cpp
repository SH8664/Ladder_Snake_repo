#include "AddSnake.h"
#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnake::AddSnake(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnake::~AddSnake()
{
}

void AddSnake::ReadActionParameters()
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
		pGrid->PrintErrorMessage("cancel operation:invalid cell position,click any where to continue");

	}
	else if (startPos.GetCellNum() == 99 || endPos.GetCellNum() == 1) {
		pGrid->PrintErrorMessage("cancel operation:start cell cannot be last cell and the end cell cannot be the first cell,click any where to continue");

	}
	else if (!snake.validsnake())
	{
		pGrid->PrintErrorMessage("cancel operation:end cell can not be larger than start cell,click any where to continue");
		
	}
	else if (!snake.isvertical())
	{
		pGrid->PrintErrorMessage("cancel operation:snake must be vertiacl,click any where to continue");
		

	}
	else if (pGrid->isoverlapping(&snake)) {
		pGrid->PrintErrorMessage("cancel operation : two overlapping gameobjects,click any where to continue");
	}


	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddSnake::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a card object with the parameters read from the user
	Snake* psnake = new Snake(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the snake object to the GameObject of its Cell:
	if (!(startPos.IsValidCell() && endPos.IsValidCell() && psnake->validsnake() && psnake->isvertical() && !pGrid->isoverlapping(psnake)&& startPos.GetCellNum() != 99 && endPos.GetCellNum() != 1))
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