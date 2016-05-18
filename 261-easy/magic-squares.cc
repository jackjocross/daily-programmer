#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {

	char str[256];
	cout << "Enter the name of the input file: ";
	cin.get(str, 256);

	ifstream is(str);

	vector<int> magicSquare;

	char c;
	while(is.get(c)) {
		if (c < 58 && c > 47) {
			magicSquare.push_back(c-48);
		}
	}

	is.close();

	int count = magicSquare.size();

	int sideLength = sqrt(count);

	int leftDiagTotal = 0;
	int rightDiagTotal = 0;

	vector<int> rowTotals(sideLength, 0);
	vector<int> columnTotals(sideLength, 0);

	int currentRow = 0;

	for (int i = 0; i < magicSquare.size();i++) {
		// Row count
		rowTotals[i / sideLength] += magicSquare[i];
		
		// Column count
		columnTotals[i % sideLength] += magicSquare[i];

		// Left diag count
		if ((i % sideLength) == (i / sideLength)) {
			leftDiagTotal += magicSquare[i];
		}

		// Right diag count
		int row = i / sideLength;
		if (i == row * sideLength + (sideLength - 1 - row)) {
			rightDiagTotal += magicSquare[i];
		}
	}

	if (leftDiagTotal != 15 || rightDiagTotal != 15) {
		cout << "false" << endl;
		return 0;
	}

	for (int i = 0;i < sideLength; i++) {
		if (rowTotals[i] != 15 || columnTotals[i] != 15) {
			cout << "false" << endl;
			return 0;
		}
	}

	cout << "true" << endl;
	return 0;
}