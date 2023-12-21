#include <iostream>

int main() {
	int* prime = new int[1001];

	prime[1] = 0;
	for (int i = 2; i <= 1'000; ++i) prime[i] = i;
	for (int i = 2; i <= 1'000; ++i) {
		if (prime[i] == 0) continue;
		for (int j = i + i; j <= 1'000; j += i) prime[j] = 0;
	}

	int N, cnt = 0;
	std::cin >> N;
	for (int i = 0, temp; i < N; ++i) {
		std::cin >> temp;
		if (prime[temp]) cnt += 1;
	}

	printf("%d", cnt);
	return 0;
}