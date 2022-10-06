
#include "CardTwelve.h"
#include "CardNine.h"
#include "CardTen.h"
#include "CardEleven.h"
CardTwelve::CardTwelve(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 12; // set the inherited cardNumber data member with the card number (1 here)
}

CardTwelve::~CardTwelve(void)
{
}

void CardTwelve::ReadCardParameters(Grid* pGrid)
{
}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	//1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	Player* pmin = pGrid->GetMinPlayerWallet(pPlayer);
	Card* pcard = pPlayer->GetMaxStation();
	CardNine* p9card = NULL;
	CardTen* p10card = NULL;
	CardEleven* p11card = NULL;
	if (dynamic_cast<CardNine*>(pcard))
	{
		pPlayer->NotOwner(p9card);
		p9card->CardOwner = NULL;
		pmin->SetAsOwner(p9card);
		p9card->CardOwner = pmin;
		return;
	}
	if (dynamic_cast<CardTen*>(pcard))
	{
		pPlayer->NotOwner(p10card);
		p10card->CardOwner = NULL;
		pmin->SetAsOwner(p10card);
		p10card->CardOwner = pmin;
		return;
	}
	if (dynamic_cast<CardEleven*>(pcard))
	{
		pPlayer->NotOwner(p11card);
		p11card->CardOwner = NULL;
		pmin->SetAsOwner(p11card);
		p11card->CardOwner = pmin;
		return;
	}
}
