#include "SwitchToDesignModeAction.h"
#include "Input.h"
#include "Output.h"

SwitchToDesignModeAction::SwitchToDesignModeAction(ApplicationManager* pApp):Action(pApp){}

 void SwitchToDesignModeAction:: ReadActionParameters(){}

 void SwitchToDesignModeAction::Execute() {
	 CardNine:: CardOwner =NULL;
	 CardTen::CardOwner = NULL;
	 CardEleven::CardOwner = NULL;

	 Grid* pgrid = pManager->GetGrid();
	 Output* pout = pgrid->GetOutput();
	 pout->ClearStatusBar();
	 pout->CreateDesignModeToolBar();
	 CellPosition start(1);
	 for (int i = 0;i < 4;i++)
	 {
		 Player* p = pgrid->GetCurrentPlayer();
		 pgrid->UpdatePlayerCell(p, start);
		 p->SetWallet(100);
		 p->SetTurncount(0);
		 pgrid->AdvanceCurrentPlayer();


	 }
 }
 SwitchToDesignModeAction:: ~SwitchToDesignModeAction(){}