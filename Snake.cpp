#include "Snake.h"
#include"Ladder.h"
#include"Card.h"
#include <fstream>
using namespace std;

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	if(endCellPos.GetCellNum()!=-1)
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}
bool Snake::validsnake()const {
	if (endCellPos.GetCellNum() >= position.GetCellNum()) return false;
	return true;
}
CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}
bool Snake::isvertical() const {
	if (endCellPos.HCell() == position.HCell()&& endCellPos.VCell() != position.VCell()) return true;
	return false;


}

bool Snake::isoverlapping(GameObject* newobj) const {
	if (dynamic_cast<Snake*>(newobj))
	{
		if (newobj->GetPosition().HCell() == endCellPos.HCell())         //the two objects are on the same vertical line
		{
			for (int i = endCellPos.VCell(); i >= position.VCell(); i--)
				for (int j =((Snake*) newobj)->GetEndPosition().VCell();j >= (newobj)->GetPosition().VCell(); j--)
					if (i == j)
						return true;
		}
		return false;
	}
	if ((dynamic_cast<Ladder*>(newobj))) {
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
void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a Snake. Click to continue ..." and wait mouse click
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("You have reached a Snake. Click to continue ...");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();
	// 2- Apply the Snake's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	pGrid->ApplyGameObject(pPlayer);
}

Snake::~Snake(){}
void Snake :: Save(ofstream &OutFile, Type type)
{
	if (type == snake)
	{
		OutFile << GetPosition().GetCellNum() <<' ' << GetEndPosition().GetCellNum() << endl;

	}
}
void Snake::Load(ifstream &Infile,Grid*pGrid)
{
	string n;
	getline(Infile, n, '\n');
	int numOfSnake = stoi(n);
	Snake ** S = new Snake*[numOfSnake];

	for (int i = 0; i < numOfSnake; i++)
	{
		string s, e;
		getline(Infile, s, ' ');
		getline(Infile, e, '\n');

		S[i] = new Snake(stoi(s), stoi(e));
		pGrid->AddObjectToCell(S[i]);
	}
	delete[]S;
}