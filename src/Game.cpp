#include"Game.h"

int main() {
	int aliveCount = 0, neighboursCount = 0, generations = 0;
	int grid[rows][cols] = { 0 };
	GridInfo unInit[150];

	readFromFile(grid, generations, unInit, aliveCount);

	displayGrid(grid);
	
	for (int i = 0; i < generations; i++) {
		NeighboursInfo* aux = new NeighboursInfo[150];
		neighboursCount = 0;
		for (int i = 0; i < aliveCount; i++) {
			storeNeighbours(grid, aux, unInit[i].getRow(), unInit[i].getCol(), neighboursCount);
		}
		run(grid, unInit, aux, neighboursCount, aliveCount);
		displayGrid(grid);
		delete[] aux;
	}
	return 0;
}