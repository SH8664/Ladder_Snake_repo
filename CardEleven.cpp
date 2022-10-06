#include "CardEleven.h"
Player* CardEleven::CardOwner = NULL;
int CardEleven::price = 0;
int CardEleven::fees = 0;
CardEleven::CardEleven(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 11; // set the inherited cardNumber data member with the card number (1 here)
}

CardEleven::~CardEleven(void)
{
}

void CardEleven::ReadCardParameters(Grid* pGrid)
{

	{


		///TODO: Implement this function as mentiNined in the guideline steps (numbered below) below


		// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


		// 1- Get a Pointer to the Input / Output Interfaces from the Grid
		Output* pOut = pGrid->GetOutput();
		Input* pIn = pGrid->GetInput();
		// 2- Get  parameter of CardNine 
		// 1-1 price    1-2 fees
		if (price == 0 && fees == 0) {
			pOut->PrintMessage("Enter price of the cell");
			price = pIn->GetInteger(pOut);
			while (price <= 0)
			{
				pOut->PrintMessage("invalid::renter the price");
				price = pIn->GetInteger(pOut);
			}
			pOut->PrintMessage("Enter Fees payed to owner of the cell");
			fees = pIn->GetInteger(pOut);
			while (fees <= 0)
			{
				pOut->PrintMessage("invalid::renter the price");
				fees = pIn->GetInteger(pOut);
			}
			this->setPrice(price);
			// 3- Clear the status bar
			pOut->ClearStatusBar();
		}


	}
}
///////////////////////////////////////////////Fatma
//////////////////////////////////////////////////////
void CardEleven::SetCardPrice()
{
	Card::setPrice(price);
}
////////////////////////////////////////////////////
/////////////////////////////////////////////////////
void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentiNined in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==
	Input* inp = pGrid->GetInput();
	Output* out = pGrid->GetOutput();
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	if (CardOwner == NULL)
	{
		out->PrintMessage("do you want to buy this cell?y/n");
		string x;
		x = inp->GetSrting(out);
		if (x == "y"||x=="Y")
		{
			int w = (pPlayer->GetWallet() - price);

			if (w < 0)
			{
				out->PrintMessage("you dont have enough money,click anywhere to continue");
				inp->GetCellClicked();
			}
			else {
				pPlayer->SetWallet(w);
				CardOwner = pPlayer;
				pPlayer->SetAsOwner(this);
			}
		}

	}
	else {
		if (pPlayer == CardOwner) {
			out->PrintMessage("the owner of the card,click anywhereto continue");
			inp->GetCellClicked();
		}
		else {
			pPlayer->SetWallet(pPlayer->GetWallet() - fees);
			if (fees <= pPlayer->GetWallet())
				CardOwner->SetWallet(fees + CardOwner->GetWallet());
			else
				CardOwner->SetWallet(pPlayer->GetWallet() + CardOwner->GetWallet());
		}
	}

	out->ClearStatusBar();
}
void CardEleven::SaveCardParameter(ofstream& OutFile)
{
	OutFile << ' ' << fees << ' ' << price << endl;
}
void CardEleven::Load(ifstream& Infile)
{
	string f, p;
	getline(Infile, f, ' ');
	getline(Infile, p, '\n');
	fees = stoi(f);
	price = stoi(p);
}