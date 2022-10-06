
#include "CardThree.h"
#include "ApplicationManager.h"
#include "RollDiceAction.h"
CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number (1 here)
}

CardThree::~CardThree(void)
{
}

void CardThree::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentiThreed in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

//Card3 gives the player an extra dice roll
void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentiThreed in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	pGrid->AdvanceCurrentPlayer();
	pGrid->AdvanceCurrentPlayer();
	pGrid->AdvanceCurrentPlayer();
}