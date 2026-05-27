#include"AI.h"


void AI::Restart()
{
	for (auto& row : grids)
	{
		for (auto& col:row)
		{
			col.Reset();
		}
	}

	for (int i = 0; i < ROWS * COLS * 0.1; i++)
	{
		GetRandomNode()->blocked = true;
	}

	startPoint = GetRandomNode();
	startPoint->fillColor = BLUE; startPoint->blocked = true; startPoint->dispTxt = "S";
	endPoint = GetRandomNode();
	endPoint->fillColor = GREEN; endPoint->blocked = true; endPoint->dispTxt = "E";
}