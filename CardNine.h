#pragma once

#include "Card.h"

// [ CardNine ] Summary:
// Its Apply() Function: Decrements the value of the passing player’s wallet by a value
// Its Parameters: The Wallet Value to decrease --> put it as a "data member" and read it in ReadCardParameters()

class CardNine : public Card
{
	// CardNine Parameters:
	static int price;
	static int fees;
	

public:
	static Player* CardOwner;
	CardNine(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardNine which is: walletAmount
	virtual void SaveCardParameter(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardNine on the passed Player
	// by decrementing the player's wallet by the walletAmount data member
	virtual ~CardNine(); // A Virtual Destructor
};

