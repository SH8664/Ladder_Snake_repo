#include "SwitchToPlayModeAction.h"
SwitchToPlayModeAction::SwitchToPlayModeAction(ApplicationManager* pApp) :Action(pApp) {}

void SwitchToPlayModeAction::ReadActionParameters() {}

void SwitchToPlayModeAction::Execute() {
	
	Grid* pgrid = pManager->GetGrid();
	Output* pout = pgrid->GetOutput();
	pout->ClearStatusBar();
	pout->CreatePlayModeToolBar();
	
}
SwitchToPlayModeAction:: ~SwitchToPlayModeAction() {}