#pragma once

#include "Card.h"


class CardEight : public Card
{
	int bail;

public:
	CardEight(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void SaveCardParameter(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual ~CardEight(); // A Virtual Destructor
};

