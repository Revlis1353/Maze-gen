#pragma once
class Cell
{
private:
	int xCoord;
	int yCoord;
	bool wall_north;
	bool wall_east;
	bool isvisited;
	bool isstart;
	int direction; //0 = north, 1 = east, 2 = south, 3 = west
public:
	Cell(int x, int y);
	~Cell();
	void changeToVisited();
	void setDirection(int dir);
	void setStart();
	void buildNorthWall();
	void buildEastWall();
	bool isVisited();
	bool isStart();
	int getX();
	int getY();
	int getDirection();
	int checkWall();
};

