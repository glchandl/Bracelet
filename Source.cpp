#include <math.h>

int main(int argc, char* argv[]) {

	//width of design
	const int wid = 4;
	
	//length of design
	const int len = 6;

	//number of colors
	const int col = 3;
	
	//array: goal pattern
	int goal[len][wid];

	//array: minimum strings in each color
	int min[col];

	//loop: initialize minimums
	for (int i = 0; i < col; i++) {
		min[i] = 0;
	}

	//loop: count minimums
	
	//number of strings
	int strings = wid * 2;
	
	//array: possible starting configs
	int start[100][8];

	//array: [x] [y] [left, right, knot]
		//note: for knot, 0 = RR, 1 = RL, 2 = LL, 3 = LR
	int pattern[len][wid][3];
	
	//array: start config color minimums (number of each color in the first row)
	int startc[col];

	//loop: initialize start config mins
	for (int i = 0; i < col; i++) {
		startc[i] = 0;
	}

	//loop: start colors numbers (number of each color in the first row)
	for (int h = 0; h < wid; h++) {
		for (int g = 0; g < col; g++) {
			if (goal[0][h] == g) {
				startc[g]++;
			}
		}
	}
	//loop: check possible color starting positions
		//note: the correct color will be on the left of every first row pair
	int colCheck[col]; //number of each color to check against minimums
	int startCount = 0; //what number starting config we're on

	for(int i = 0; i < col; i++){
		for (int j = 0; j < col; j++) {
			for (int k = 0; k < col; k++) {
				for (int l = 0; l < col; l++) {
					//start the color checks at the first row color numbers
					colCheck[0] = startc[0];
					colCheck[1] = startc[1];
					colCheck[2] = startc[2];
					//loop: counting colors, m is color it's checking for
					for (int m = 0; m < col; m++) {
						if (i == m) { colCheck[m]++; }
						if (j == m) { colCheck[m]++; }
						if (k == m) { colCheck[m]++; }
						if (l == m) { colCheck[m]++; }
					}
					//if: check if minimums were reached, insert new possible starting config if true
					if ((colCheck[0] >= min[0]) && (colCheck[1] >= min[1]) && (colCheck[2] >= min[2])) {
						start[startCount][0] = goal[0][0];
						start[startCount][1] = i;
						start[startCount][2] = goal[0][1];
						start[startCount][3] = j;
						start[startCount][4] = goal[0][2];
						start[startCount][5] = k;
						start[startCount][6] = goal[0][3];
						start[startCount][7] = l;
						startCount++;
					}
				}
			}
		}
	}

	//function: check if any knot will give correct color





}