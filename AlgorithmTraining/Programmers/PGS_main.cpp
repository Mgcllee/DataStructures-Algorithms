#pragma once

#include "main.h"
#include "SortFunctions.h"

#include <vector>

int main() {
	int n = 5;
	int m = 4;
	vector<int> section = { 1, 3 };

	int answer = 0;

	vector<int>::iterator startPos = section.begin();
	vector<int>::iterator endPos = section.begin();

	/*for ( ; ; startPos = endPos + 1, endPos = endPos + 2) {
		if (*startPos && (endPos == section.end() || endPos == section.end() - 1)) {
			*startPos = -1;
			answer += 1;
			break;
		}
		else if (*startPos && *endPos && (*endPos - *startPos + 1 <= m)) {
			answer += 1;
			*startPos = *endPos = -1;
		}
	}*/

	for (vector<int>::iterator it = section.begin(); it != section.end(); ++it) {
		if (it + 1 == section.end()) break;

		/*for (int i = *it; i < *(it + 1); ++i) {
			cout << i << endl;
		}
		cout << "==========\n";*/
		answer += 1;
	}
	
	cout << answer;
}
