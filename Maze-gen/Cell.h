#pragma once
class Cell
{
private:
	int xCoord;
	int yCoord;
	bool wall_north;
	bool wall_east;
	bool isvisited;
	int direction; //0 = north, 1 = east, 2 = south, 3 = west
public:
	Cell(int x, int y);
	~Cell();
	void changeToVisited();
	void setDirection(int dir);
	bool isVisited();
	int getX();
	int getY();
};

