#include "pch.h"
#include "Chess.h"

ChessBoard::ChessBoard(int x, int y)
{
	m_board = new int* [m_x];  // ������ָ������

	for (int i = 0; i < m_x; i++) {
		m_board[i] = new int[m_y];  // Ϊÿһ�д���������
	}
}

ChessBoard::~ChessBoard()
{
	for (int i = 0; i < m_x; i++) {
		delete[] m_board[i];  // �ͷ�ÿһ�е�������
	}
	delete[] m_board;  // �ͷ���ָ������
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
