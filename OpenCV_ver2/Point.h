#pragma once
#include"Header.h"
#include "Character.h"

class point {
	friend class character;
protected:
	int x;
	int y;
public:
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}

};