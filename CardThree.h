#pragma once

#include "Card.h"

// [ CardThree ] Summary:
// Its Apply() Function: Decrements the value of the passing player’s wallet by a value
// Its Parameters: The Wallet Value to decrease --> put it as a "data member" and read it in ReadCardParameters()

class CardThree : public Card
{
	// CardThree Parameters:
	

public:
	CardThree(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardThree which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardThree on the passed Player
	// by decrementing the player's wallet by the walletAmount data member

	virtual ~CardThree(); // A Virtual Destructor
};

