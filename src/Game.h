#pragma once
#include<iostream>
#include"GridInfo.h"
#include"NeighboursInfo.h"
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;

struct CellsToDelete {
public:
	int row, col, index;
};

const int rows = 12, cols = 12;

void displayGrid(int grid[rows][cols]) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << grid[i][j] << "   ";
		}
		cout << endl;
	}
	system("PAUSE");
}

void storeAlive(GridInfo* unInit, int r, int c, int& count) {
	unInit[count].setRow(r);
	unInit[count].setCol(c);
	count++;
}

int countSumOfNeighbours(int grid[rows][cols], int r, int c) {
	int sum = 0;

	sum += grid[r - 1][c - 1];
	sum += grid[r - 1][c];
	sum += grid[r - 1][c + 1];
	sum += grid[r ][c - 1];
	sum += grid[r ][c + 1];
	sum += grid[r + 1][c - 1];
	sum += grid[r + 1][c];
	sum += grid[r + 1][c + 1];

	return sum;
}

void storeNeighbours(int grid[rows][cols], NeighboursInfo* aux, int r, int c, int& count) {
	int sum = 0, sum1 = 0;
	int r1, c1;

	if ((r != 0) && (r != rows - 1) && (c != 0) && (c != cols - 1)) {
		sum = countSumOfNeighbours(grid, r, c);
		if (grid[r - 1][c - 1] == 0) {
			sum1 = 0;
			if ((r - 1 != 0) && (r - 1 != rows - 1) && (c - 1 != 0) && (c - 1 != cols - 1)) {
				sum1 = countSumOfNeighbours(grid, r - 1, c - 1);
			}

			if (sum1 == 3) {
				aux[count].setRow(r - 1);
				aux[count].setCol(c - 1);
				aux[count].setSum(sum1);
				count++;
			}
		}

		if (grid[r - 1][c] == 0) {
			sum1 = 0;
			if ((r - 1 != 0) && (r - 1 != rows - 1) && (c != 0) && (c != cols - 1)) {
				sum1 = countSumOfNeighbours(grid, r - 1, c);
			}

			if (sum1 == 3) {
				aux[count].setRow(r - 1);
				aux[count].setCol(c);
				aux[count].setSum(sum1);
				count++;
			}
		}

		if (grid[r - 1][c + 1] == 0) {
			sum1 = 0;
			if ((r - 1 != 0) && (r - 1 != rows - 1) && (c + 1 != 0) && (c + 1 != cols - 1)) {
				sum1 = countSumOfNeighbours(grid, r - 1, c + 1);
			}

			if (sum1 == 3) {
				aux[count].setRow(r - 1);
				aux[count].setCol(c + 1);
				aux[count].setSum(sum1);
				count++;
			}
		}

		if (grid[r][c - 1] == 0) {
			sum1 = 0;
			if ((r != 0) && (r != rows - 1) && (c - 1 != 0) && (c - 1 != cols - 1)) {
				sum1 = countSumOfNeighbours(grid, r, c - 1);
			}

			if (sum1 == 3) {
				aux[count].setRow(r);
				aux[count].setCol(c - 1);
				aux[count].setSum(sum1);
				count++;
			}
		}

		if (grid[r][c + 1] == 0) {
			sum1 = 0;
			if ((r != 0) && (r != rows - 1) && (c + 1 != 0) && (c + 1 != cols - 1)) {
				sum1 = countSumOfNeighbours(grid, r, c + 1);
			}

			if (sum1 == 3) {
				aux[count].setRow(r);
				aux[count].setCol(c + 1);
				aux[count].setSum(sum1);
				count++;
			}
		}

		if (grid[r + 1][c - 1] == 0) {
			sum1 = 0;
			if ((r + 1 != 0) && (r + 1 != rows - 1) && (c - 1 != 0) && (c - 1 != cols - 1)) {
				sum1 = countSumOfNeighbours(grid, r + 1, c - 1);
			}

			if (sum1 == 3) {
				aux[count].setRow(r + 1);
				aux[count].setCol(c - 1);
				aux[count].setSum(sum1);
				count++;
			}
		}

		if (grid[r + 1][c] == 0) {
			sum1 = 0;
			if ((r + 1 != 0) && (r + 1 != rows - 1) && (c != 0) && (c != cols - 1)) {
				sum1 = countSumOfNeighbours(grid, r + 1, c);
			}

			if (sum1 == 3) {
				aux[count].setRow(r + 1);
				aux[count].setCol(c);
				aux[count].setSum(sum1);
				count++;
			}
		}

		if (grid[r + 1][c + 1] == 0) {
			sum1 = 0;
			if ((r + 1 != 0) && (r + 1 != rows - 1) && (c + 1 != 0) && (c + 1 != cols - 1)) {
				sum1 = countSumOfNeighbours(grid, r + 1, c + 1);
			}

			if (sum1 == 3) {
				aux[count].setRow(r + 1);
				aux[count].setCol(c + 1);
				aux[count].setSum(sum1);
				count++;
			}
		}
	}

	if ((r != rows - 1) && (c != cols - 1)) {
		aux[count].setRow(r);
		aux[count].setCol(c);
		aux[count].setSum(sum);
		count++;
	}
}

void run(int grid[rows][cols], GridInfo* unInit, NeighboursInfo* aux, int& neighboursCount, int& aliveCount) {
	int count = neighboursCount;
	int count1 = aliveCount;
	CellsToDelete d1[150];
	int k = 0, l = 0;

	for (int i = 0; i < count; i++) {
		if (grid[aux[i].getRow()][aux[i].getCol()] == 1) {
			if (aux[i].getSum() < 2 || aux[i].getSum() > 3) {
				grid[aux[i].getRow()][aux[i].getCol()] = 0;
				d1[k].row = aux[i].getRow();
				d1[k].col = aux[i].getCol();
				d1[k].index = i;
				k++;
			}

			else if (aux[i].getSum() == 3 || aux[i].getSum() == 2) {
				grid[aux[i].getRow()][aux[i].getCol()] = 1;
			}
		}

		else {
			if (aux[i].getSum() == 3) {
				grid[aux[i].getRow()][aux[i].getCol()] = 1;
				unInit[aliveCount].setRow(aux[i].getRow());
				unInit[aliveCount].setCol(aux[i].getCol());
				aliveCount++;
			}
		}
	}
	
	for (int i = 0; i < aliveCount && l <= k; i++) {
		if (d1[l].row == unInit[i].getRow() && d1[l].col == unInit[i].getCol()) {
			unInit[i] = unInit[aliveCount - 1];
			aliveCount--;
			aux[d1[l].index] = aux[neighboursCount - 1];
			neighboursCount--;
			i--;
		}

		if (i == aliveCount - 1) {
			i = -1;
			l++;
		}
	}
}

void readFromFile(int grid[rows][cols], int& generations, GridInfo* unInit, int& aliveCount) {
	fstream f("data.txt", ios::in);

	if (f) {
		string a;
		int x, y;

		f >> a;
		generations = stoi(a);
		f >> a;

		while (!f.eof()) {
			getline(f, a, ' ');
			x = stoi(a);
			f >> a;
			y = stoi(a);

			grid[x][y] = 1;
			storeAlive(unInit, x, y, aliveCount);
		}
	}
}