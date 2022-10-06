#pragma once
#include "GameObject.h"
#include <fstream>
using namespace std;

class Snake :  public GameObject
{
	CellPosition endCellPos; 
public:
	
	Snake(const CellPosition& startCellPos, const CellPosition& endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const ; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer) ; // Applys the effect of the ladder by moving player to ladder's end cell

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	bool validsnake() const;
	bool isvertical() const;
	bool isoverlapping(GameObject* newobj) const;
	virtual void Save(ofstream &OutFile,Type type);
	void Load(ifstream &Infile,Grid*pGrid);
	virtual~Snake();
};

