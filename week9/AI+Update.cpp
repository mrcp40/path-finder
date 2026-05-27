#include"AI.h"


void AI::Draw()
{
	for (auto row : grids)
	{
		for (auto col : row)
		{
			col.Draw();
		}
	}

	for (auto row : paths)
	{
		for (auto col : row)
		{
			col->DrawPath();
		}
	}
}


void AI::Update()
{
	
	
}