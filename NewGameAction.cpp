#include "NewGameAction.h"
#include"CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"
#include "Grid.h"
#include "Player.h"

#include <time.h> // used to in srand to generate random numbers with different seed

NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{
}

void NewGameAction::ReadActionParameters()
{
	// no parameters to read from user
}

void NewGameAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Do you want to start New Game? Y/N ");
	string ans = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
	if (ans == "Y" || ans == "y")
	{
		CellPosition firstcell(1);
		pGrid->ToFirstCell(firstcell);  //move all players to cell number 1
		pGrid->SetInitialWallet();      //set players wallet with 100 coins
		pGrid->RemoveStations();        //set players stations with null
		pGrid->SetPlayerTurn();
		pGrid->SetCurrentPlayerNum(0);
		pGrid->SetEndGame(0);
		pGrid->SetIntialAttemps();
		CardNine::CardOwner = NULL;
CardTen::CardOwner = NULL;
		CardEleven::CardOwner = NULL;

	}

	else return;

}


NewGameAction::~NewGameAction()
{
}
