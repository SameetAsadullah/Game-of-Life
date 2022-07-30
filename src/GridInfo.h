#pragma once
class GridInfo {
protected:
	int row, col;

public:
	GridInfo() :row(0), col(0) {
	}

	void setRow(int r) {
		if (r >= 0) {
			row = r;
		}
	}

	void setCol(int c) {
		if (c >= 0) {
			col = c;
		}
	}

	int getRow()const {
		return row;
	}

	int getCol()const {
		return col;
	}
};