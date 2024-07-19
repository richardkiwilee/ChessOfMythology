#pragma once
#include <iostream>
#include <string>
#include <set>
#include <vector>
#define WHITE_KING 9812
#define WHITE_QUEEN 9813
#define WHITE_ROOK 9814
#define WHITE_BISHOP 9815
#define WHITE_KNIGHT 9816
#define WHITE_PAWN 9817
#define BLACK_KING 9818
#define BLACK_QUEEN 9819
#define BLACK_ROOK 9820
#define BLACK_BISHOP 9821
#define BLACK_KNIGHT 9822
#define BLACK_PAWN 9823

#define MOVETYPE_PWAN 1   // 兵的基础移动方式
#define MOVETYPE_KNIGHT 2 // 马的基础移动方式
#define MOVETYPE_BISHOP 3 // 象的基础移动方式
#define MOVETYPE_ROOK 4   // 车的基础移动方式
#define MOVETYPE_QUEEN 5  // 后的基础移动方式
#define MOVETYPE_KING 6   // 王的基础移动方式


struct Coordinate {
    int x;
    int y;
};

Coordinate parseCoordinate(const std::string& coordinate) {
    if (coordinate.length() < 2 || coordinate.length() > 3) {
        throw std::invalid_argument("Invalid coordinate format");
    }
    // Parse the letter part (A-Z)
    char letter = coordinate[0];
    if (letter < 'A' || letter > 'Z') {
        throw std::invalid_argument("Invalid coordinate format");
    }
    int x = letter - 'A';
    // Parse the number part (1-99)
    std::string numberStr = coordinate.substr(1);
    int number = std::stoi(numberStr);
    if (number < 1 || number > 99) {
        throw std::invalid_argument("Invalid coordinate format");
    }
    int y = number - 1;
    return { x, y };
}

std::string formatCoordinate(const Coordinate& coordinate) {
    char letter = 'A' + coordinate.x;
    int number = coordinate.y + 1;
    return std::string(1, letter) + std::to_string(number);
}

std::string formatCoordinate(int x, int y) {
    char letter = 'A' + x;
    int number = y + 1;
    return std::string(1, letter) + std::to_string(number);
}

class Chess
{
public:
    Chess();
    Coordinate coordinate;
    int armor = 0;
    int attack = 1;
    int max_health = 1;
    int curr_health = 1;
    int max_free_movement = 0;
    int curr_free_movement = 0;
    void AddMovementType(int movement_type) { this->movement_types.insert(movement_type); };
    void RemoveMovementType(int movement_type) { this->movement_types.erase(movement_type); };
    void OnTurnStart() { curr_free_movement = max_free_movement; };
    void OnTurnEnd() {};
    std::set<std::string> GetAvailableMoves()
    {
        std::set<std::string> moves;
        for (int movement_type : movement_types)
        {
            switch (movement_type)
            {
            case MOVETYPE_PWAN:
                moves.insert(formatCoordinate(coordinate.x, coordinate.y + 1));
                break;
            case MOVETYPE_KNIGHT:
                moves.insert(formatCoordinate(coordinate.x + 1, coordinate.y + 2));
                moves.insert(formatCoordinate(coordinate.x + 1, coordinate.y - 2));
                moves.insert(formatCoordinate(coordinate.x - 1, coordinate.y + 2));
                moves.insert(formatCoordinate(coordinate.x - 1, coordinate.y - 2));
                moves.insert(formatCoordinate(coordinate.x + 2, coordinate.y + 1));
                moves.insert(formatCoordinate(coordinate.x + 2, coordinate.y - 1));
                moves.insert(formatCoordinate(coordinate.x - 2, coordinate.y + 1));
                moves.insert(formatCoordinate(coordinate.x - 2, coordinate.y - 1));
                break;
            case MOVETYPE_BISHOP:
                for (int i = 1; i < 8; i++)
                {
                    moves.insert(formatCoordinate(coordinate.x + i, coordinate.y + i));
                    moves.insert(formatCoordinate(coordinate.x + i, coordinate.y - i));
                    moves.insert(formatCoordinate(coordinate.x - i, coordinate.y + i));
                    moves.insert(formatCoordinate(coordinate.x - i, coordinate.y - i));
                }
                break;
            case MOVETYPE_ROOK:
                for (int i = 1; i < 8; i++)
                {
                    moves.insert(formatCoordinate(coordinate.x + i, coordinate.y));
                    moves.insert(formatCoordinate(coordinate.x - i, coordinate.y));
                    moves.insert(formatCoordinate(coordinate.x, coordinate.y + i));
                    moves.insert(formatCoordinate(coordinate.x, coordinate.y - i));
                }
                break;
            case MOVETYPE_QUEEN:
                break;
            case MOVETYPE_KING:
                break;
            }
        }
        return moves;
    };
    Coordinate GetCoordinate() { return coordinate; };
private:
    std::set<int> movement_types;
};

class SquareEffect
{
public:
    void OnTurnStart() {};
    void OnTurnEnd() {};
};

class Building
{
public:
    int id;
    bool defence;
    bool attack;
    void OnTurnStart();
    void OnTurnEnd();
};

struct ChessBoardSquare
{
    Coordinate coordinate;
    int terrain;
    SquareEffect* effect;
    Building* building;
    Chess* chess;
};


class ChessBoard
{
public:
    ChessBoard(int x, int y);
    ~ChessBoard();
    void Print();
private:
    int ** m_board;
    int m_x;
    int m_y;
protected:

};

class Player
{
public:
    Player();
	~Player();
    int food;
    int gold;
    int wood;
    int stone;
    int faith;
    std::vector<Chess> m_chess;
    std::vector<Building> m_building;
private:

};