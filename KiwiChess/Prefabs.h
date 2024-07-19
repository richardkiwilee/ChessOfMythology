#pragma once
#include "Chess.h"

class Pawn : public Chess	// 兵
{
public:
	Pawn() {
		this->AddMovementType(MOVETYPE_PWAN);
	};
};


class Rook : public Chess	// 车
{	
public:
	Rook() { this->AddMovementType(MOVETYPE_ROOK); };
};

class Knight : public Chess	// 马
{	
public:
	Knight() { this->AddMovementType(MOVETYPE_KNIGHT); };
};	

class Bishop : public Chess	// 相
{	
public:
	Bishop() { this->AddMovementType(MOVETYPE_BISHOP); };
};	

class Queen : public Chess	// 后
{	
public:
	Queen() { this->AddMovementType(MOVETYPE_QUEEN); };
};	

class King : public Chess	// 王
{	
public:
	King() { this->AddMovementType(MOVETYPE_KING); };
};	
