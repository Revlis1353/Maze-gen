#pragma once
class Grid
{
private:
	bool *wall_north;
	bool *wall_east;
	bool *isWall;
	int *direction; //0 = north, 1 = east, 2 = south, 3 = west
public:
	Grid(int sizeX, int sizeY);
	void genMaze();
	~Grid();
};

