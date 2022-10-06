#pragma once
#include "Card.h"
#include"Ladder.h"
// [ CardTwo ] Summary:
// Its Apply() Function:nMoves the player forward to the start of the next ladder in the grid ( If no ladders ahead, do nothing)
// Its Parameters: _
class CardTwo :
    public Card
{ public:
	CardTwo(const CellPosition& pos); // A Constructor takes card position

	 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardTwo on the passed Player
													  // by moving current player to the next ladder

	virtual ~CardTwo(); // A Virtual Destructor
};

