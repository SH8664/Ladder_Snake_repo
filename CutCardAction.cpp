#include "CutCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"

CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

CutCardAction::~CutCardAction()
{
}

void CutCardAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the position parameter
	pOut->PrintMessage("click on the source cell");
	cardposition = pIn->GetCellClicked();



	

	/// Make the needed validations on the read parameters
	if (cardposition.GetCellNum() == -1)
	{
		pGrid->PrintErrorMessage("cancel operation:invalid cell position,click anywhere to continue");
		

	}



	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void CutCardAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a card object with the parameters read from the user


	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager


	if (cardposition.GetCellNum() == -1)
		return;
	if (pGrid->GetCard(cardposition))
	{
		pGrid->SetClipboard(pGrid->GetCard(cardposition));
		pGrid->RemoveObjectFromCell(cardposition);
	}
}