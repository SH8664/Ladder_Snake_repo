#include "CardSeven.h"
CardSeven::CardSeven(const CellPosition& pos) : Card(pos)
{
	cardNumber = 7;
}
void CardSeven::Apply(Grid* pGrid, Player* pPlayer) {
	Card::Apply(pGrid, pPlayer);
	CellPosition c(8, 0);        //first cell
	
	Player* p = pGrid->GetCurrentPlayer();
	pGrid->AdvanceCurrentPlayer();
	Player* p1 = pGrid->GetCurrentPlayer();
	pGrid->AdvanceCurrentPlayer();
	Player* p2 = pGrid->GetCurrentPlayer();
	pGrid->AdvanceCurrentPlayer();
	Player* p3 = pGrid->GetCurrentPlayer();
	pGrid->AdvanceCurrentPlayer();

	if (p1->GetCell()->GetCellPosition().GetCellNum() > p->GetCell()->GetCellPosition().GetCellNum() && (p1->GetCell()->GetCellPosition().GetCellNum() <= p2->GetCell()->GetCellPosition().GetCellNum() || p2->GetCell()->GetCellPosition().GetCellNum() <= p->GetCell()->GetCellPosition().GetCellNum()) && (p1->GetCell()->GetCellPosition().GetCellNum() <= p3->GetCell()->GetCellPosition().GetCellNum() || p3->GetCell()->GetCellPosition().GetCellNum() <= p->GetCell()->GetCellPosition().GetCellNum()))
	{
		pGrid->UpdatePlayerCell(p1, c);
		return;
	}
	if (p2->GetCell()->GetCellPosition().GetCellNum() > p->GetCell()->GetCellPosition().GetCellNum() && (p2->GetCell()->GetCellPosition().GetCellNum() <= p1->GetCell()->GetCellPosition().GetCellNum() || p1->GetCell()->GetCellPosition().GetCellNum() <= p->GetCell()->GetCellPosition().GetCellNum()) && (p1->GetCell()->GetCellPosition().GetCellNum() <= p3->GetCell()->GetCellPosition().GetCellNum() || p3->GetCell()->GetCellPosition().GetCellNum() <= p->GetCell()->GetCellPosition().GetCellNum()))
	{
		pGrid->UpdatePlayerCell(p2, c);
		return;
	}
	if (p3->GetCell()->GetCellPosition().GetCellNum() > p->GetCell()->GetCellPosition().GetCellNum() && (p3->GetCell()->GetCellPosition().GetCellNum() <= p2->GetCell()->GetCellPosition().GetCellNum() || p2->GetCell()->GetCellPosition().GetCellNum() <= p->GetCell()->GetCellPosition().GetCellNum()) && (p3->GetCell()->GetCellPosition().GetCellNum() <= p1->GetCell()->GetCellPosition().GetCellNum() || p1->GetCell()->GetCellPosition().GetCellNum() <= p->GetCell()->GetCellPosition().GetCellNum()))
	{
		pGrid->UpdatePlayerCell(p3, c);
		return;
	}
}



CardSeven:: ~CardSeven() {}