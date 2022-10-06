#include "Player.h"
#include"Card.h"
#include"CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"
#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	count = 0;
	for (int i = 0; i < 3; i++)
	{
		stations[i] = 0;
	}
	this->pCell = pCell;
	this->turnCount = 0;
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	if (wallet >= 0)
		this->wallet = wallet;
	else this->wallet = 0;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	
	color playerColor = UI.PlayerColors[playerNum];
	

	///TODO: use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======
bool Player::deductwallet(Player* p, int x) {

	while (TimesToDeduct)
	{
		if (x >= 0)
		{
			p->SetWallet(p->GetWallet() - x);
			TimesToDeduct--;
			return true;
		}
	}
	return false;


}
int Player::poison(int x)
{
	while (TimesToPoison)
	{

		x = x - 1;
		TimesToPoison--;
		return x;

	}
	return x;

}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{
	deductwallet(this, 20);

	if (prevent())
	{
		turnCount++;
		return;
	}
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once

	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)



	turnCount++;


	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	if (GetTurnCount() % 3==0 && attempt == 2)
	{
		int recharge = GetWallet() + diceNumber * 10;
		SetWallet(recharge);
		return;
	}
	else if (GetTurnCount() % 3 == 0)
	{
		Input* pIn = pGrid->GetInput();
		Output* pOut = pGrid->GetOutput();
		pOut->PrintMessage("Do you wish to launch a special attack instead of recharging? y/n");
		string ans = pIn->GetSrting(pOut);
		pOut->ClearStatusBar();
		if (ans == "y" || ans == "Y")
		{

			pOut->PrintMessage("Choose your launch 1)Ice  2)Fire  3)Poison  4)Lighting   (Enter the number of your choice)");
			int Ans = pIn->GetInteger(pOut);
			pOut->ClearStatusBar();
			if (Ans == 1 && !flag1)
			{
				pOut->PrintMessage("please Write the num of the player to prevent from rolling the next time");
				Ans = pIn->GetInteger(pOut);
				pOut->ClearStatusBar();
				if (Ans >= 0 && Ans < 4)
				{
					Player* p = pGrid->GetCurrentPlayer();
					if (p->getplayerNum() == Ans) {
						pGrid->PrintErrorMessage("you cannot choose yourself ,click anywhere to continue");
					}
					for (int i = 0; i < MaxPlayerCount - 1; i++)
					{

						pGrid->AdvanceCurrentPlayer();
						Player* p = pGrid->GetCurrentPlayer();
						if (p->getplayerNum() == Ans)
						{
							p->SetTimesToPrevent(1);

						}
					}
					pGrid->AdvanceCurrentPlayer();
				}


				flag1 = true;
				attempt++;
				return;
			}
			else if (Ans == 2 && !flag2)
			{

				pOut->PrintMessage("please Write the num of the playerto burn ");
				Ans = pIn->GetInteger(pOut);
				pOut->ClearStatusBar();
				if (Ans >= 0 && Ans < 4)
				{
					Player* p = pGrid->GetCurrentPlayer();
					if (p->getplayerNum() == Ans) {
						pGrid->PrintErrorMessage("you cannot choose yourself ,click anywhere to continue");
					}
					for (int i = 0; i < MaxPlayerCount - 1; i++)
					{

						pGrid->AdvanceCurrentPlayer();
						Player* p = pGrid->GetCurrentPlayer();

						{
							if (p->getplayerNum() == Ans)
							{
								p->TimesToDeduct = 3;


							}
						}

					}
					pGrid->AdvanceCurrentPlayer();
				}
				flag2 = true;
				attempt++;
				return;
			}
			else if (Ans == 3 && !flag3)
			{
				pOut->PrintMessage("please Write the num of the playerto poison");
				Ans = pIn->GetInteger(pOut);
				pOut->ClearStatusBar();
				if (Ans >= 0 && Ans < 4)
				{
					Player* p = pGrid->GetCurrentPlayer();
					if (p->getplayerNum() == Ans)
					{
						pGrid->PrintErrorMessage("you cannot choose yourself ,click anywhere to continue");
					}
					for (int i = 0; i < MaxPlayerCount - 1; i++)
					{

						pGrid->AdvanceCurrentPlayer();
						Player* p = pGrid->GetCurrentPlayer();

						{
							if (p->getplayerNum() == Ans)
							{
								p->TimesToPoison = 5;


							}
						}

					}
					pGrid->AdvanceCurrentPlayer();


				}
				flag3 = true;
				attempt++;
				return;
			}
			else if (Ans == 4 && !flag4)
			{
				for (int i = 0; i < MaxPlayerCount - 1; i++)
				{
					pGrid->AdvanceCurrentPlayer();

					Player* p = pGrid->GetCurrentPlayer();
					p->TimesToDeduct = 1;
					p->deductwallet(p, 20);

				}
				pGrid->AdvanceCurrentPlayer();

				flag4 = true;
				attempt++;
				return;
			}
			pGrid->PrintErrorMessage("You chose this attempt before, try the next time,click anywhere to continue");
			int recharge = GetWallet() + diceNumber * 10;
			SetWallet(recharge);
			return;
		}
		else {

			int recharge = GetWallet() + diceNumber * 10;
			SetWallet(recharge);
			return;
		}
	}

	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	else
	{
		if (wallet < 1)
		{
			turnCount++;
			return;
		}

		
			else {

				//3 - Set the justRolledDiceNum with the passed diceNumber
				justRolledDiceNum = diceNumber;
				diceNumber = poison(justRolledDiceNum);
				CellPosition p = pCell->GetCellPosition();
				CellPosition newpos(p.GetCellNumFromPosition(p) + diceNumber);
				// 4- Get the player current cell position, say "pos", 
				// and add to it the diceNumber (update the position)
				// Using the appropriate function of CellPosition class to update "pos"

				pGrid->UpdatePlayerCell(this, newpos);

				// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) 
				// with the cell in the passed position, "pos" (the updated one)
				//  the importance of this function is that it Updates the pCell pointer 
				//of the player and Draws it in the new position
				pGrid->ApplyGameObject(this);  // 6- Apply() the game object of the reached cell (if any)
				if ((p.GetCellNumFromPosition(p)+diceNumber)==100)
					pGrid->SetEndGame(true);
				return;
				// 7- Check if the player reached the end cell of the whole game, 
				//and if yes, Set end game with true: pGrid->SetEndGame(true)
			}
		}
		
	}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}
int Player::getjustRolledDiceNum() { return justRolledDiceNum; }
int Player::getplayerNum() { return playerNum; }
void Player::SetTurncount(int x) {
	if (x >= 0 && x < 4)
		turnCount = x;
}
void Player::SetTimesToPrevent(int T)
{
	TimesToPrevent = (T > 0) ? T : 0;
}
bool Player::prevent()
{
	while (TimesToPrevent)
	{

		TimesToPrevent--;
		return true;

	}
	return false;
}
void Player:: SetAttemps(int x)
{
	if (x >= 0 && x < 3)
		attempt = x;
}
void Player::SetIntialFlags()
{
	flag1 = false;
	flag2 = false;       
	flag3 = false;
	flag4 = false;
}
///////////////////////////////////////////fatma
//////////////////////////////////////////////
void Player::SetAsOwner(Card* p)
{
	if (p)
	{
		stations[count] = p;
		count++;
	}
	else
	{
		count = 0;
		stations[count] = NULL;
	}

}
Card* Player::GetMaxStation()
{
	Card* max;
	max = stations[0];
	for (int i = 1; i < count; i++)
	{
		if (stations[i]->GetPrice() > max->GetPrice())
			max = stations[i];
	}
	return max;
}
void Player::NotOwner(Card* p)
{
	for (int i = 1; i < count; i++)
	{
		if (stations[i] == p)
		{
			stations[i] = NULL;
			stations[i] = stations[count - 1];
			count--;
		}
	}
}
Player* Player::GetMinPlayer(Player* p)
{
	if (wallet < p->GetWallet())
		return this;
	else return p;
}
///////////////////////////////////////////////////////
////////////////////////////////////////////////////////