#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition()
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;
}

CellPosition::CellPosition(int v, int h)
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1;
	hCell = -1;

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition(int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
	// from the passed (cellNum)
	// (*this) = ... --> this will copy the returned (vCell and hCell)
	//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (!(v >= 0 && v < NumVerticalCells))
		return false; // this line sould be changed with your implementation
	vCell = v;
	return true;
}

bool CellPosition::SetHCell(int h)
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)

	if (!(h >= 0 && h < NumHorizontalCells))
		return false; // this line sould be changed with your implementation
	hCell = h;
	return true;
}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const
{
	return hCell;
}

bool CellPosition::IsValidCell() const
{
	///TODO: Implement this function as described in the .h file
	if (vCell == -1 || hCell == -1)

		return false; // this line sould be changed with your implementation
	return true;
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
	// which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition& cellPosition)
{

	int arr[NumVerticalCells][NumHorizontalCells];
	int g = 1;
	for (int i = NumVerticalCells - 1; i >= 0; i--)
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			arr[i][j] = g++;
		}

	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file


	if (cellPosition.IsValidCell())
		return arr[cellPosition.VCell()][cellPosition.HCell()]; // this line should be changed with your implementation
	else
		return -1;
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	/// TODO: Implement this function as described in the .h file
	int arr[NumVerticalCells][NumHorizontalCells];
	int g = 1;
	for (int i = NumVerticalCells - 1; i >= 0; i--)
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			arr[i][j] = g++;
			if (cellNum == arr[i][j])
			{
				position.SetVCell(i);
				position.SetHCell(j);
				break;
			}
		}
	if (cellNum < 1) {
		position.SetVCell(8);
		position.SetHCell(0);
	}
	if (cellNum > 99)
	{
		
		position.SetVCell(0);
		position.SetHCell(10);
	}
	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	return position;
}


void CellPosition::AddCellNum(int addedNum)
{

	/// TODO: Implement this function as described in the .h file

	CellPosition x = GetCellPositionFromNum(GetCellNum() + addedNum);
	vCell = x.VCell();
	hCell = x.HCell();

	// Note: this function updates the data members (vCell and hCell) of the calling object

}