#include"AI.h"

void AI::Interaction()
{
	if (IsKeyPressed(KEY_R))
	{
		Restart();
	}
	if (IsKeyPressed(KEY_S))
		RandomSearch(startPoint, endPoint);
}