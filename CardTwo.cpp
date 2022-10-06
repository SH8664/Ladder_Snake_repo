#include "CardTwo.h"
CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (1 here)
}
void CardTwo::Apply(Grid* pGrid, Player* pPlayer) {
	Card::Apply(pGrid,pPlayer);
	Ladder * pladder = pGrid->GetNextLadder(position);
	
	if (pladder != NULL)
	{
		CellPosition newposition= pladder->GetPosition();
		pGrid->UpdatePlayerCell(pPlayer, newposition);
		pladder-> Apply(pGrid,pPlayer);       
	}

}
CardTwo:: ~CardTwo(){}