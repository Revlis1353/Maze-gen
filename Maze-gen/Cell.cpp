#include "Cell.h"



Cell::Cell(int x, int y) : xCoord(x), yCoord(y) {
	wall_east = false;
	wall_north = false;
	isvisited = false;
	direction = 0;
}


Cell::~Cell()
{
}

void Cell::changeToVisited() {
	isvisited = true;
}

void Cell::setDirection(int dir) {
	direction = dir;
}

bool Cell::isVisited() {
	return isvisited;
}

int Cell::getX() {
	return xCoord;
}

int Cell::getY() {
	return yCoord;
}
