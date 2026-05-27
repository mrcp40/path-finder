#pragma once
#include<raylib.h>
#include<vector>
#include"Node.h"

class AI
{
public:
#define ROWS 10
#define COLS 20
#define NODE_SIZE  25//每一格的长宽

	static const int screenW = 500;
	static const int screenH = 250;

	std::vector<std::vector<Node>> grids;
	std::vector<std::vector<Node*>> paths;
	Node* startPoint;
	Node* endPoint;
	bool disableRandomSearch;


	void Main();
	void Start();
	void Update();
	void Draw();
	void Interaction();
	void Restart();
	std::vector<Node*> GetNeighbors(Node* node);
	Node* GetRandomNode();

	void BFS(Node* s, Node* e);
	void DFS(Node* s, Node* e);
	void Djikstra(Node* s, Node* e);
	void Astar(Node* s, Node* e);

	void RandomSearch(Node* s, Node* e);
};