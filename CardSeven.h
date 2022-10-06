#pragma once
#include "Card.h"
class CardSeven :
    // [ CardSeven ] Summary:
// Its Apply() Function:Restarts the game for the first player whose cell is after the current player in the grid
// Its Parameters: _
    public Card
{
public:
	CardSeven(const CellPosition& pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual ~CardSeven(); // A Virtual Destructor
};




