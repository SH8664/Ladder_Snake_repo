#pragma once

#include "Grid.h"
#include "Cell.h"

class Player
{
	Cell * pCell;		   // pointer to the current Cell of the player

	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1)
	                       // player number does NOT change after construction (const.)

	int stepCount;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells
	int wallet;		       // player's wallet (how many coins he has -- integer)
	int justRolledDiceNum; // the current dice number which is just rolled by the player
	int turnCount;         // a counter that starts with 0, is incremented with each dice roll
	                       // and reset again when reached 3
	                       // it is used to indicate when to move and when to add to your wallet
	int TimesToPrevent = 0;
	int attempt = 0; //number of attempts to Launch (Bonus)
	bool flag1 = false;
	bool flag2 = false;       //Flages For Attempts of Launch
	bool flag3 = false;
	bool flag4 = false;
	int TimesToPoison = 0;
	int TimesToDeduct = 0;
	////////////////////////////////////////////
	/////////////////////////////////////////////
	Card* stations[3];
	int count ;
	
	///////////////////////////////////////////////////
	//////////////////////////////////////////////////
public:
	void SetAttemps(int);
	Player(Cell * pCell, int playerNum); // Constructor making any needed initializations

	// ====== Setters and Getters ======

	void SetCell(Cell * cell);		// A setter for the pCell
	Cell* GetCell() const;			// A getter for the pCell

	void SetWallet(int wallet);		// A setter for the wallet
	int GetWallet() const;			// a getter for the wallet

	int GetTurnCount() const;		// A getter for the turnCount

	///TODO: You can add setters and getters for data members here (if needed)

	// ====== Drawing Functions ======

	void Draw(Output* pOut) const;			// Draws the Player's Circle on its current cell

	void ClearDrawing(Output* pOut) const;	// Clears the Player's Circle from its current cell

	// ====== Game Functions ======

	void Move(Grid * pGrid, int diceNumber);	// Moves the Player with the passed diceNumber 
	                                            // and Applies the Game Object's effect (if any) of the end reached cell 
	                                            // for example, if the end cell contains a ladder, take it
	
	void AppendPlayerInfo(string & playersInfo) const; // Appends player's info to the input string, 
	int getjustRolledDiceNum();                                                // for example: P0(wallet, turnCount)
	int getplayerNum();
	void SetTurncount(int);
	bool prevent();
	bool deductwallet(Player*, int);
	int poison(int);
	void SetTimesToPrevent(int T);
	void SetIntialFlags();
	/////////////////////////////////////////////////////fatma
		////////////////////////////////////////////////////////
	void SetAsOwner(Card* p);
	Card* GetMaxStation();
	void NotOwner(Card* p);
	Player* GetMinPlayer(Player* p);
	/////////////////////////////////////////////////

};
