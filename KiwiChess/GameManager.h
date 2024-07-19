#pragma once
#include "Chess.h"
class GameManager
{
public:
	GameManager();
	~GameManager();
	void CreateBoard(int x, int y);
	void Flush();
	void Clear();
	void AddChess(int x, int y, Player player);
	void RemoveChess(int x, int y);
	void AddBuilding(int x, int y, Player player);
	void RemoveBuilding(int x, int y);
	void OnTurnStart(Player player);
};