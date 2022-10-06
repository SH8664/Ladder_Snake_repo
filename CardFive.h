#pragma once
#include "Card.h"
// [ CardFive ] Summary:
// Its Apply() Function:Moves the player backward with the same number of steps that he just rolled.
// Its Parameters: _
class CardFive :
    public Card
{ public:
	CardFive(const CellPosition& pos); // A Constructor takes card position



	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardFive on the passed Player
													  // by Moveing the player backward with the same number of steps that he just rolled

	virtual ~CardFive(); // A Virtual Destructor
};




