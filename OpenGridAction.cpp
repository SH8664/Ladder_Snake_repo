#include "OpenGridAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include <string>
#include "Ladder.h"
#include "Snake.h"
#include "Card.h"
#include "fstream"
OpenGridAction::OpenGridAction(ApplicationManager *pApp) :Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void OpenGridAction::ReadActionParameters()
{
	Grid*pGrid = pManager->GetGrid();
	Input *pIn = pGrid->GetInput();
	Output *pOut = pGrid->GetOutput();
	pOut->PrintMessage("Enter the file name to open.... ");
	filename=pIn->GetSrting(pOut);
	//clear statusbar
	pOut->ClearStatusBar();
}

void OpenGridAction::Execute()
{
	ReadActionParameters();
	Grid*pGrid = pManager->GetGrid();
	Output * pOut=pGrid->GetOutput();
	pGrid->RemoveAllGameObject();
	ifstream file;
	file.open(filename+".txt");
	if (file.is_open())
	{
		Ladder L(-1,-1);
		L.Load(file,pGrid);
		Snake S(-1, -1);
		S.Load(file, pGrid);
		Card C((-1,-1));
		C.Load(file, pGrid);
		pGrid->UpdateInterface();
		file.close();
	}
	else
	{
		pOut->PrintMessage("the file cannot be opened.......");
	}
	
	
}
OpenGridAction::~OpenGridAction()
{

}
