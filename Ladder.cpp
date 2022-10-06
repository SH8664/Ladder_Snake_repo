#include "Ladder.h"
#include"Snake.h"
#include"Card.h"
#include <fstream>
#include"ApplicationManager.h"
Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{ 
	if(endCellPos.GetCellNum()!=-1)
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	Output* pout=pGrid->GetOutput();
	pout->PrintMessage("You have reached a ladder. Click to continue ...");
	Input* pin = pGrid->GetInput();
	pin->GetCellClicked();
	pout->ClearStatusBar();
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	pGrid->ApplyGameObject(pPlayer);
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}
bool Ladder::validladder()const {
	if (endCellPos.GetCellNum() <= position.GetCellNum()) return false;
	return true;
}
bool Ladder::isvertical() const {
	if (endCellPos.HCell() == position.HCell()&& endCellPos.VCell()!= position.VCell()) return true;
	
	return false;


}

bool Ladder::isoverlapping(GameObject* newobj) const {
	if (dynamic_cast<Ladder*>(newobj))
	{
		if (newobj->GetPosition().HCell() == endCellPos.HCell())         //the two objects are on the same vertical line
		{
			for (int i = position.VCell(); i >= endCellPos.VCell(); i--)
				for (int j = newobj->GetPosition().VCell();j >= ((Ladder*)newobj)->GetEndPosition().VCell(); j--)
					if (i == j)
						return true;
		}
		return false;
	}
	if (dynamic_cast<Snake*>(newobj)) {
		if (endCellPos.HCell() == (newobj->GetPosition().HCell()) && (endCellPos.VCell() == (newobj->GetPosition().VCell())))
			return true;
		if (position.HCell() == (((Snake*)newobj)->GetEndPosition().HCell()) && position.VCell() == (((Snake*)newobj)->GetEndPosition().VCell()))
			return true;
		return false;
	}
	if (dynamic_cast<Card*>(newobj)) {
		return false;
	}
}
Ladder::~Ladder()
{
}
void Ladder::Save(ofstream &OutFile, Type type)
{
	if (type == ladder)
	{
		OutFile << GetPosition().GetCellNum() <<' ' << GetEndPosition().GetCellNum()<<endl;

	}
}
void Ladder::Load(ifstream &Infile,Grid*pGrid)
{
	
	string n;
	getline(Infile,n, '\n');
	int numOfladder = stoi(n);
	Ladder ** L = new Ladder*[numOfladder];

	for (int i = 0; i < numOfladder; i++)
	{
		string s, e;
		getline(Infile, s,' ');
		getline(Infile, e, '\n');

		L[i] = new Ladder(stoi(s), stoi(e));
	pGrid->AddObjectToCell(L[i]);
	}

	delete[]L;
}