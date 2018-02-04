#include "Cell.h"


//When you store a wall of four cardinal points of a cell,
//the data overlap with the one next to it,
//so only the wall of the east and north will be stored in one cell.
Cell::Cell(int x, int y) : xCoord(x), yCoord(y) {
	wall_east = false;
	wall_north = false;
	isvisited = false;
	isstart = false;
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

void Cell::setStart() {
	isstart = true;
}

void Cell::buildNorthWall() {
	wall_north = true;
}

void Cell::buildEastWall() {
	wall_east = true;
}

bool Cell::isVisited() {
	return isvisited;
}

bool Cell::isStart() {
	return isstart;
}

int Cell::getX() {
	return xCoord;
}

int Cell::getY() {
	return yCoord;
}

int Cell::getDirection(){
	return direction;
}

int Cell::checkWall() {
	if (!wall_east && !wall_north) {
		return 0;
	}
	else if (wall_east && !wall_north) {
		return 1;
	}
	else if (!wall_east && wall_north) {
		return 2;
	}
	else if (wall_east && wall_north) {
		return 3;
	}
}