#include "SwitchToDesignModeAction.h"
#include "Input.h"
#include "Output.h"

SwitchToDesignModeAction::SwitchToDesignModeAction(ApplicationManager* pApp) :Action(pApp){}

void SwitchToDesignModeAction::ReadActionParameters(){}

void SwitchToDesignModeAction::Execute() {
	CardNine::CardOwner = NULL;

	CardTen::CardOwner = NULL;
	CardEleven::CardOwner = NULL;

	Grid* pgrid = pManager->GetGrid();
	Output* pout = pgrid->GetOutput();
	pout->ClearStatusBar();
	CellPosition start(1);
	
		
		pgrid->ToFirstCell( start);
		

	pout->CreateDesignModeToolBar();
	
}
SwitchToDesignModeAction:: ~SwitchToDesignModeAction(){}