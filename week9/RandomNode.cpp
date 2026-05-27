#include"AI.h"

Node* AI::GetRandomNode()
{
	int randomRow = GetRandomValue(0, ROWS - 1);
	int randomCol = GetRandomValue(0, COLS - 1);

	while (grids[randomRow][randomCol].blocked == true)
	{
		randomRow = GetRandomValue(0, ROWS - 1);
		randomCol = GetRandomValue(0, COLS - 1);
	}
	return &(grids[randomRow][randomCol]);
}