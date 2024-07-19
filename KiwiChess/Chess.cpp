#include "pch.h"
#include "Chess.h"

ChessBoard::ChessBoard(int x, int y)
{
	m_board = new int* [m_x];  // 创建行指针数组

	for (int i = 0; i < m_x; i++) {
		m_board[i] = new int[m_y];  // 为每一行创建列数组
	}
}

ChessBoard::~ChessBoard()
{
	for (int i = 0; i < m_x; i++) {
		delete[] m_board[i];  // 释放每一行的列数组
	}
	delete[] m_board;  // 释放行指针数组
}

Chess::Chess()
{
	
}

void Building::OnTurnStart()
{
}

void Building::OnTurnEnd()
{
}

Player::Player()
{
}

Player::~Player()
{
}
