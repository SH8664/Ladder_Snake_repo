#pragma once

#include "Card.h"

// [ CardEleven ] Summary:
// Its Apply() Function: Decrements the value of the passing player’s wallet by a value
// Its Parameters: The Wallet Value to decrease --> put it as a "data member" and read it in ReadCardParameters()

class CardEleven : public Card
{
	// CardEleven Parameters:
	static int price;
	static int fees;
	

public:
	static Player* CardOwner;

	CardEleven(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardEleven which is: walletAmount
	virtual void SaveCardParameter(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardEleven on the passed Player
	// by decrementing the player's wallet by the walletAmount data member
	///////////////////////////////////////////////
	//////////////////////////////////////////////////
	void SetCardPrice();
	/////////////////////////////////////////////////
	////////////////////////////////////////////////////
	virtual ~CardEleven(); // A Virtual Destructor
};

