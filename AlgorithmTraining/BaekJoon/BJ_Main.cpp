#include <iostream>
#include <vector>

int main() {
	int seq;
	std::cin >> seq;
	int* arr = new int[seq];
	for (int i = 0; i < seq; ++i) {
		std::cin >> arr[seq - 1 - i];
	}

	std::vector<char> vec;
	for (int i = 1; i <= seq; ++i) {
		if (i == arr[i - 1]) vec.push_back('+');
		else if (i < arr[i - 1]) {
			for (int j = i; j <= seq; ++j) {
				if (j < arr[i - 1]) vec.push_back('+');
				else {
					vec.push_back('-');
					break;
				}
			}
		}
		else vec.push_back('-');
	}

	printf("=================\n");
	for (char c : vec)
		printf("%c\n", c);
}