#include "CardEight.h"

CardEight::CardEight(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 8; // set the inherited cardNumber data member with the card number (1 here)
}

CardEight::~CardEight(void)
{
}

void CardEight::ReadCardParameters(Grid* pGrid)
{
	Input* pin = pGrid->GetInput();
	Output* pout = pGrid->GetOutput();
	pout->PrintMessage("New CardEight :Please enter coins needed  to be decremented");
	bail = pin->GetInteger(pout);
	while (bail <= 0) {
		pout->PrintMessage("invalid value ,please enter a valid value");
		bail=pin->GetInteger(pout);

	}
	pout->ClearStatusBar();
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	Input* pin = pGrid->GetInput();
	Output* pout = pGrid->GetOutput();
	pout->PrintMessage("Do you want to skip prison ? Y/N");
	string ans = pin->GetSrting(pout);
	pout->ClearStatusBar();
	if (ans == "y" || ans == "Y")
	{
		int newWallet = pPlayer->GetWallet() - bail;
		pPlayer->SetWallet(newWallet);
	}
	else
	{
		pPlayer->SetTimesToPrevent(3);
	}
}
void CardEight::SaveCardParameter(ofstream& OutFile)
{
	OutFile << ' ' << bail << endl;
}
void CardEight::Load(ifstream& Infile)
{
	string b;
	getline(Infile, b, '\n');
	bail = stoi(b);

}
