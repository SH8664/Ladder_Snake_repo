#include "CardFive.h"
CardFive::CardFive(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number (1 here)
}
void CardFive::Apply(Grid* pGrid, Player* pPlayer) {
	Card::Apply(pGrid, pPlayer);
	int justrolleddiceno=pPlayer->getjustRolledDiceNum();
	int oldposition = position.GetCellNumFromPosition(position);
	int newposition = oldposition - pPlayer->getjustRolledDiceNum();
	CellPosition newcellposition = position.GetCellPositionFromNum(newposition);
	pGrid->UpdatePlayerCell(pPlayer, newcellposition);
	
	pGrid->ApplyGameObject(pPlayer);
	

}
CardFive:: ~CardFive() {}