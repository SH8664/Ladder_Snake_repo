#pragma once
#include "Card.h"
#include"CellPosition.h"
// [ CardSix ] Summary:
// Its Apply() Function:Instructs the player to go to a specific cell
// Its Parameters: cell to move to
class CardSix :
    public Card
{
    CellPosition celltomoveto;
public:
	CardSix(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member
	virtual void SaveCardParameter(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual ~ CardSix(); // A Virtual Destructor
};

