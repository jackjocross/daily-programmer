#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> pullNumbers(string numbers);

bool isNumber(string number);

int main(int argc, char** argv) {

	string maybeNumeric;
	cout << "Enter a potential number: ";
	getline(cin, maybeNumeric);

	vector<string> numbers = pullNumbers(maybeNumeric);

	for (vector<string>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
		if (!isNumber(*it)) {
			cout << maybeNumeric << " (string)" << endl;
			return 0;
		}
	}

	cout << maybeNumeric << " (number)" << endl;

	return 0;
}

vector<string> pullNumbers(string numbers) {
	vector<string> numberVector;
	string current;

	for (string::iterator it = numbers.begin(); it != numbers.end(); ++it) {
		if (*it == ' ' && current.length() > 0) {
			numberVector.push_back(current);
			current.clear();
		} else {
			current.push_back(*it);
		}
	}

	if (current.length() > 0) {
		numberVector.push_back(current);
	}

	return numberVector;
}

bool isNumber(string number) {
	bool seenDecimal = false, seenE = false;
	for (string::iterator it = number.begin(); it != number.end(); ++it) {
		if (*it == 46) {
			if (seenE || seenDecimal) {
				return false;
			} else {
				seenDecimal = true;
			}
		} else if (*it == 101) {
			if (seenE) {
				return false;
			} else {
				seenE = true;
			}
		} else if (*it > 57 || *it < 48) {
			return false;
		}
	}

	return true;
}
