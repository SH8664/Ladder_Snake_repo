#include "CardSix.h"
CardSix::CardSix(const CellPosition& pos):Card(pos) 
{
	cardNumber = 6; 
}
void CardSix::ReadCardParameters(Grid* pGrid) {
	Input *pin = pGrid->GetInput();
	Output* pout = pGrid->GetOutput();
	pout->PrintMessage("New CardSix :please click on cell to move to ");
	celltomoveto=pin->GetCellClicked();       //get cell tomoveto from  the user
	while (!celltomoveto.IsValidCell()|| celltomoveto.GetCellNum()== position.GetCellNum())   //in case user clicked invalid position
	{
		pout->PrintMessage("invlid position ,click on anther cell");
		celltomoveto = pin->GetCellClicked();
		pout->ClearStatusBar();
	}
	pout->ClearStatusBar();
}
void CardSix::Apply(Grid* pGrid, Player* pPlayer) {
	Card::Apply(pGrid, pPlayer);
	pGrid->UpdatePlayerCell(pPlayer, celltomoveto);
	GameObject* objectinnewcell = pPlayer->GetCell()->GetGameObject();  //game object in new position
	if (objectinnewcell != NULL) {
		objectinnewcell->Apply(pGrid, pPlayer);  //apply game object in new position

	}
} CardSix:: ~CardSix(){}
void CardSix::SaveCardParameter(ofstream& OutFile)
{
	OutFile << ' ' << celltomoveto.GetCellNum() << endl;
}

void CardSix::Load(ifstream& Infile)
{
	string p;
	getline(Infile, p, ' ');
	CellPosition pos(stoi(p));
	celltomoveto = pos;
}