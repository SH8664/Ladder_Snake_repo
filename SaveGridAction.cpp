
#include "SaveGridAction.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include <string>
#include <fstream>
#include<iostream>
using namespace std;
SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

void SaveGridAction:: ReadActionParameters()
{
	//Get pointer to the input class
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	//Get The FileName and its validation
	pOut->PrintMessage("Enter the name of the file.......");
	filename = pIn->GetSrting(pOut);

	//ClearStatusBar
	pOut->ClearStatusBar();
	
}
void SaveGridAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	ReadActionParameters();
	//open file_ 
	ofstream file(filename+".txt");
	//A- We get a pointer to the Grid from the ApplicationManager

	//saving data
		pGrid->SaveAll(file, ladder);
		pGrid->SaveAll(file, snake);
		pGrid->SaveAll(file, card);
	//close file_
	file.close();
	
}
SaveGridAction::~SaveGridAction()
{

}
