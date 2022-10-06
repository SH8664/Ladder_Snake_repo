#include "DeleteGameObject.h"
#include"Grid.h"
DeleteGameObject::DeleteGameObject(ApplicationManager* pApp):Action(pApp) {}

void DeleteGameObject::ReadActionParameters() {
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Delete Object: Click on its  Cell ...");

	positionOfObject = pIn->GetCellClicked();
	pOut->ClearStatusBar();
	if (!positionOfObject.IsValidCell()) {
		pGrid->PrintErrorMessage("Opeartion Cancelled:invalid cell,click anywhere to continue");
		
	}
	pOut->ClearStatusBar();
 }

 void DeleteGameObject:: Execute(){
	 ReadActionParameters();
	 if (!positionOfObject.IsValidCell())
		 return;
	 Grid* pGrid = pManager->GetGrid();
	
	 pGrid->RemoveObjectFromCell(positionOfObject);

 }
 DeleteGameObject:: ~DeleteGameObject(){}