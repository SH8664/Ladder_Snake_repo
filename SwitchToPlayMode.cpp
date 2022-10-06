#include "SwitchToPlayModeAction.h"
#include"Player.h"
SwitchToPlayModeAction::SwitchToPlayModeAction(ApplicationManager* pApp) :Action(pApp) {}

void SwitchToPlayModeAction::ReadActionParameters() {}

void SwitchToPlayModeAction::Execute() {

	Grid* pGrid = pManager->GetGrid();
	Output* pout = pGrid->GetOutput();
	pout->ClearStatusBar();
	pGrid->SetInitialWallet();      //set players wallet with 100 coins
	pGrid->SetPlayerTurn();
	pGrid->SetCurrentPlayerNum(0);
	pGrid->SetEndGame(0);
	pout->CreatePlayModeToolBar();
	pGrid->SetIntialAttemps();
}
SwitchToPlayModeAction:: ~SwitchToPlayModeAction() {}