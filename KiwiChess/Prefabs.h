#pragma once
#include "Chess.h"

class Pawn : public Chess	// ��
{
public:
	Pawn() {
		this->AddMovementType(MOVETYPE_PWAN);
	};
};


class Rook : public Chess	// ��
{	
public:
	Rook() { this->AddMovementType(MOVETYPE_ROOK); };
};

class Knight : public Chess	// ��
{	
public:
	Knight() { this->AddMovementType(MOVETYPE_KNIGHT); };
};	

class Bishop : public Chess	// ��
{	
public:
	Bishop() { this->AddMovementType(MOVETYPE_BISHOP); };
};	

class Queen : public Chess	// ��
{	
public:
	Queen() { this->AddMovementType(MOVETYPE_QUEEN); };
};	

class King : public Chess	// ��
{	
public:
	King() { this->AddMovementType(MOVETYPE_KING); };
};	
