#include "InputDiceValueAction.h"
#include "Grid.h"
#include "Player.h"

InputDiceValueAction::InputDiceValueAction(ApplicationManager* pApp) : Action(pApp)
{
}

void InputDiceValueAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please enter a dice value between 1-6");
	do {

		diceValue = pIn->GetInteger(pOut);
		pOut->ClearStatusBar();
	}
	while (!(diceValue<7 && diceValue>0));
}

void InputDiceValueAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	 if (pGrid->GetEndGame()) 
	{
		pOut->PrintMessage("The Game has ended, for another game click NewGame");
	}
	 else 
	{
		Player* pplayer = pGrid->GetCurrentPlayer();
		pplayer->Move(pGrid, diceValue);
		pGrid->AdvanceCurrentPlayer();
	}
}
InputDiceValueAction::~InputDiceValueAction()
{
}
