#include "AI.h"


void AI::RandomSearch(Node* s, Node* e)
{
	Node* current = s;
	std::vector<Node*> path;
	bool passable = true;
	bool left = true;
	bool right = true;
	bool up = true;
	bool down = true;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			grids[i][j].isVisted = false;
		}
	}

	auto isWithinGrid = [&](int row, int col)->bool
		{
			return row >= 0 && col >= 0 && row < ROWS && col < COLS;
		};
	
	current->isVisted = true;
    while (current != e)
    {
        std::vector<Node*> neighbors;

        // left
        if (isWithinGrid(current->row, current->col - 1) &&
            !grids[current->row][current->col - 1].blocked &&
            !grids[current->row][current->col - 1].isVisted)
        {
            neighbors.push_back(&grids[current->row][current->col - 1]);
        }

        // right
        if (isWithinGrid(current->row, current->col + 1) &&
            !grids[current->row][current->col + 1].blocked &&
            !grids[current->row][current->col + 1].isVisted)
        {
            neighbors.push_back(&grids[current->row][current->col + 1]);
        }

        // up
        if (isWithinGrid(current->row - 1, current->col) &&
            !grids[current->row - 1][current->col].blocked &&
            !grids[current->row - 1][current->col].isVisted)
        {
            neighbors.push_back(&grids[current->row - 1][current->col]);
        }

        // down
        if (isWithinGrid(current->row + 1, current->col) &&
            !grids[current->row + 1][current->col].blocked &&
            !grids[current->row + 1][current->col].isVisted)
        {
            neighbors.push_back(&grids[current->row + 1][current->col]);
        }

        // 没路可走
        if (neighbors.empty())
        {
            passable = false;
            break;
        }

        int randomIndex = GetRandomValue(0, neighbors.size() - 1);

        current = neighbors[randomIndex];
        current->isVisted = true;

        path.push_back(current);
    }
	if (current == e)
	{
		for (int i = 0; i < path.size(); i++)
		{
			path[i]->fillColor = GREEN;
		}
	}
	else
	{
		for (int i = 0; i < path.size(); i++)
		{
			path[i]->fillColor = RED;
		}
		
	}
    paths.push_back(path);
}