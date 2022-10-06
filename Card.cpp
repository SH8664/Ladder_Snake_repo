#include "Card.h"
#include "fstream"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include "CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include "CardSeven.h"
#include "CardEight.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
#include "CardTwelve.h"

Card::Card(const CellPosition & pos) : GameObject(pos) // sets the cell position of the GameObject
{
}

void Card::SetCardNumber(int cnum)
{
	if (cnum >= 1 && cnum <= 12)
		cardNumber = cnum; // needs validation
	else
		cardNumber = 1;
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position, cardNumber);


}

void Card::ReadCardParameters(Grid * pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer) 
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

Card::~Card()
{
}
void Card::SetCellpostion(CellPosition pos) {
	position = pos;
}
void Card::SetCellNum(int Cnum)
{
	CellPosition C (Cnum);
	this->position = C;
}
void Card::Save(ofstream& OutFile, Type type)
{
	if (type == card)
	{
		OutFile << cardNumber << ' ' << GetPosition().GetCellNum();
		if (dynamic_cast<CardOne*>(this) ||
			dynamic_cast<CardSix*>(this) ||
			dynamic_cast<CardEight*>(this) ||
			dynamic_cast<CardNine*>(this) ||
			dynamic_cast<CardTen*>(this) ||
			dynamic_cast<CardEleven*>(this)
			)
			this->SaveCardParameter(OutFile);
		else
			OutFile << endl;
	}
}
void Card::Load(ifstream& Infile, Grid* pGrid)
{
	string n;
	getline(Infile, n, '\n');
	int numOfCard = stoi(n);
	Card** C = new Card * [numOfCard];

	for (int i = 0; i < numOfCard; i++)
	{
		string n, p;
		getline(Infile, n, ' ');
		int CNum = stoi(n);
		if (CNum == 1 || CNum == 6 || CNum == 11 || CNum == 9 || CNum == 8 || CNum == 10)
		{
			getline(Infile, p, ' ');
			CellPosition pos(stoi(p));
			switch (CNum)
			{
			case 1:
				C[i] = new CardOne(pos);
				C[i]->SetCellNum(stoi(p));
				C[i]->cardNumber = stoi(n);
				C[i]->Load(Infile);
				break;

			case 6:
				C[i] = new CardSix(pos);
				C[i]->SetCellNum(stoi(p));
				C[i]->cardNumber = stoi(n);
				C[i]->Load(Infile);
				break;

			case 8:
				C[i] = new CardEight(pos);
				C[i]->SetCellNum(stoi(p));
				C[i]->cardNumber = stoi(n);
				C[i]->Load(Infile);
				break;
			case 9:
				C[i] = new CardNine(pos);
				C[i]->SetCellNum(stoi(p));
				C[i]->cardNumber = stoi(n);
				C[i]->Load(Infile);
				break;
			case 10:
				C[i] = new CardTen(pos);
				C[i]->SetCellNum(stoi(p));
				C[i]->cardNumber = stoi(n);
				C[i]->Load(Infile);
				break;
			case 11:
				C[i] = new CardEleven(pos);
				C[i]->SetCellNum(stoi(p));
				C[i]->cardNumber = stoi(n);
				C[i]->Load(Infile);

				break;

			}

		}
		else
		{
			getline(Infile, p, '\n');
			CellPosition pos(stoi(p));
			switch (CNum)
			{
			case 2:
				C[i] = new CardTwo(pos);
				C[i]->SetCellNum(stoi(p));
				C[i]->cardNumber = stoi(n);
				C[i]->Load(Infile);
				break;
			case 3:
				C[i] = new CardThree(pos);
				C[i]->SetCellNum(stoi(p));
				C[i]->cardNumber = stoi(n);
				C[i]->Load(Infile);
				break;
			case 4:
				C[i] = new CardFour(pos);
				C[i]->SetCellNum(stoi(p));
				C[i]->cardNumber = stoi(n);
				C[i]->Load(Infile);
				break;
			case 5:
				C[i] = new CardFive(pos);
				C[i]->SetCellNum(stoi(p));
				C[i]->cardNumber = stoi(n);
				C[i]->Load(Infile);
			case 7:
				C[i] = new CardSeven(pos);
				C[i]->SetCellNum(stoi(p));
				C[i]->cardNumber = stoi(n);
				C[i]->Load(Infile);
				break;
			case 12:
				C[i] = new CardTwelve(pos);
				C[i]->SetCellNum(stoi(p));
				C[i]->cardNumber = stoi(n);
				C[i]->Load(Infile);
				break;
			}
		}

		pGrid->AddObjectToCell(C[i]);
	}
	delete[] C;
}

////////////////////////////////////////////fatma
//////////////////////////////////////////////
void Card::setPrice(int price)
{
	stationPrice = price;
}

int Card::GetPrice()
{
	return stationPrice;
}
//////////////////////////////////////
////////////////////////////////////////
void Card::SaveCardParameter(ofstream& OutFile)
{
	//No Implementation 
}
void Card::Load(ifstream& Infile)
{
	//No Implementation 
}