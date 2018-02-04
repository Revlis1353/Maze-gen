#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Grid.h"


Grid::Grid(int sizeX, int sizeY) : maxX(sizeX), maxY(sizeY) {
	int i, j;
	for (i = 0; i < sizeY; i++) {
		for (j = 0; j < sizeX; j++) {
			Cell * tempCell = new Cell(j, i);
			unvisitedCell.push_back(tempCell);
			cells.push_back(tempCell);
		}
	}
	srand((int)time(0));
}


Grid::~Grid() {
	//remove cells in vector
	int i;
	for (i = 0; i < cells.size(); i++) {
		delete cells[i];
	}
}

void Grid::printGrid() {
	int i, j;
	for (j = 0; j < maxY; j++) {
		std::cout << "l";
		for (i = 0; i < maxX; i++) {
			switch (cells[j*maxX + i]->checkWall()) {
			case 0:
				if (cells[j*maxX + i]->isVisited()) {
					std::cout << "##";
					break;
				}
				std::cout << "  ";
				break;
			case 1:
				std::cout << " l";
				break;
			case 2:
				std::cout << "£þ";
				break;
			case 3:
				std::cout << "¤¡";
				break;
			case 5:
				std::cout << "!!";
				break;
			}
		}
		std::cout << "l" << std::endl;
	}
}

void Grid::genMaze() {
	//Set start point
	Cell * startCell = pickRandomUnvisitedCell();
	startCell->changeToVisited();
	unvisitedCell.erase(unvisitedCell.begin() + findIndexwithCell(startCell));

	//###loop
	while (unvisitedCell.size() > 0) {

		//Pick random cell
		startCell = pickRandomUnvisitedCell();
		startCell->setStart();
		Cell * endCell = startCell;

		//Make way to exist maze passage
		while (!endCell->isVisited()) {
			int direction = rand() % 4;
			switch (direction) {

			case 0:
				if (endCell->getY() + 1 == maxY)
					break;
				endCell->setDirection(direction);
				endCell = cells[maxX * (endCell->getY() + 1) + endCell->getX()];
				break;
			case 1:
				if (endCell->getX() + 1 == maxX)
					break;
				endCell->setDirection(direction);
				endCell = cells[maxX * endCell->getY() + endCell->getX() + 1];
				break;
			case 2:
				if (endCell->getY() == 0)
					break;
				endCell->setDirection(direction);
				endCell = cells[maxX * (endCell->getY() - 1) + endCell->getX()];
				break;
			case 3:
				if (endCell->getX() == 0)
					break;
				endCell->setDirection(direction);
				endCell = cells[maxX * endCell->getY() + endCell->getX() - 1];
				break;
			}
		}
		//Now endCell is located in maze
		//I'll Track the way from startCell to endCell

		int lastdir = 0;

		while (!startCell->isVisited()) {
			int dir = startCell->getDirection();
			
			startCell->changeToVisited();
			unvisitedCell.erase(unvisitedCell.begin() + findIndexwithCell(startCell));
			buildWall(dir, lastdir, startCell);

			printGrid();
			std::cout << "#########" << startCell->isStart() << "############" << std::endl;

			switch (dir) {
			case 0:
				startCell = cells[maxX * (startCell->getY() + 1) + startCell->getX()];
				break;
			case 1:
				startCell = cells[maxX * startCell->getY() + startCell->getX() + 1];
				break;
			case 2:
				startCell = cells[maxX * (startCell->getY() - 1) + startCell->getX()];
				break;
			case 3:
				startCell = cells[maxX * startCell->getY() + startCell->getX() - 1];
				break;
			}
			lastdir = dir;
		}
	}
}

void Grid::buildWall(int dir, int lastdir, Cell * currentCell) {
	int currentIndex = currentCell->getX() + currentCell->getY() * maxX;

	if (currentCell->isStart()) {
		if (dir != 0 && currentCell->getY() != (maxY - 1) && cells[currentIndex + maxX]->isVisited()) { //north side
			currentCell->buildNorthWall();
		}
		if (dir != 1 && currentCell->getX() + 1 != maxX && cells[currentIndex + 1]->isVisited()) { //east side
			currentCell->buildEastWall();
		}
		if (dir != 2 && currentCell->getY() != 0 && cells[currentIndex - maxX]->isVisited()) { //south side
			cells[currentIndex - maxX]->buildNorthWall();
		}
		if (dir != 3 && currentCell->getX() != 0 && cells[currentIndex - 1]->isVisited()) { //west side
			cells[currentIndex - 1]->buildEastWall();
		}
		return;
	}
	//Bug!!!!
	if (dir != 0 && lastdir != 2 && currentCell->getY() + 1 != maxY && cells[currentIndex + maxX]->isVisited()) { //north side
		currentCell->buildNorthWall();
		//cells[currentIndex - maxX]->buildNorthWall();
	}
	if (dir != 1 && lastdir != 3 && currentCell->getX() + 1 != maxX && cells[currentIndex + 1]->isVisited()) { //east side
		currentCell->buildEastWall();
	}
	if (dir != 2 && lastdir != 0 && currentCell->getY() != 0 && cells[currentIndex - maxX]->isVisited()) { //south side
		cells[currentIndex - maxX]->buildNorthWall();
		//currentCell->buildNorthWall();
	}
	if (dir != 3 && lastdir != 1 && currentCell->getX() != 0 && cells[currentIndex-1]->isVisited()) { //west side
		cells[currentIndex - 1]->buildEastWall();
	}
}

Cell * Grid::pickRandomUnvisitedCell() {
	int tempIndex = rand() % unvisitedCell.size();
	Cell * tempCell = unvisitedCell[tempIndex];
	return tempCell;
}

int Grid::findIndexwithCell(Cell * data) {
	int index = (unvisitedCell.size() - 1) / 2;
	int borderStart = 0;
	int borderEnd = unvisitedCell.size() - 1;
	Cell * tempData = unvisitedCell[index];

	if (data == unvisitedCell[borderEnd])
		return borderEnd;

	while (tempData != data) {
		if (tempData->getY() * maxX + tempData->getX() > data->getY() * maxX + data->getX()) 
			borderEnd = index;
		else 
			borderStart = index;
		index = (borderStart + borderEnd) / 2;
		tempData = unvisitedCell[index];
	}

	return index;
}