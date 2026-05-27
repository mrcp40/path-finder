#pragma once
#include<raylib.h>
#include<string>

inline void DrawRectLinesVec(Vector2 pos, Vector2 size, Color color)
{

	DrawRectangleLines(pos.x, pos.y, size.x, size.y, color);
}


struct Node
{
	Node(int r, int c, Vector2 pos, Vector2 size, bool b, Color fc = RAYWHITE, Color oc = BLACK)
	{
		this->row = r;
		this->col = c;
		this->position = pos;
		this->size = size;
		this->fillColor = fc;
		this->outlineColor = oc;
		this->blocked = b;
	}

	int row, col;
	Vector2 position;
	Vector2 size = { 25,25 };
	Color fillColor;
	Color outlineColor;
	bool blocked = false;
	std::string dispTxt;
	float weight;
	bool isVisted = false;

	void Draw()
	{
		if (blocked)
		{
			DrawRectangleV(position, size, fillColor);
		}
		DrawRectLinesVec(position, size, outlineColor);

		if (dispTxt.empty())
		{
			return;
		}

		int textHeight = 20;
		int textWidth = MeasureText(dispTxt.c_str(), textHeight);

		Vector2 txtPos = Vector2{position.x + size.x / 2 - textWidth / 2, position.y + size.y / 2 - textHeight / 2};
		DrawText(dispTxt.c_str(), txtPos.x, txtPos.y, textHeight, BLACK);
	}

	void DrawPath()
	{
		DrawRectangleV(position, size, fillColor);
	}

	void Reset()
	{
		this->blocked = false;
		this->dispTxt = "";
		this->fillColor = GRAY;
	}

};