#include "ApplicationManager.h"
#include "CardFour.h"
CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number (1 here)
}

CardFour::~CardFour(void)
{
}

void CardFour::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentiFourd in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 3- Clear the status bar
	pOut->ClearStatusBar();

}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	
	

		///TODO: Implement this function as mentiFourd in the guideline steps (numbered below) below


		// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

		// 1- Call Apply() of the base class Card to print the message that you reached this card number
		Card::Apply(pGrid, pPlayer);
		pPlayer->SetTimesToPrevent(1);

	
}
