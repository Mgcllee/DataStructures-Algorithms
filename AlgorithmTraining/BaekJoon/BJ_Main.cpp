#include <iostream>

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	int* DP = new int[12];
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;
	for (int j = 4; j < 11; ++j) {
		DP[j] = DP[j - 3] + DP[j - 2] + DP[j - 1];
	}

	for (int i = 0, temp; i < N; ++i) {
		std::cin >> temp;
		printf("%d\n", DP[temp]);
	}

	return 0;
}