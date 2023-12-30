#include <iostream>

int main() {
	int T;
	std::cin >> T;

	for (int t = 0; t < T; ++t) {
		int N, M, K, cnt = 0;
		std::cin >> N >> M >> K;

		if (K == 1 && M == 1 && N != 1) {
			printf("-1\n");
			continue;
		}

		while (0 < N) {
			cnt += 1;
			
			if (N >= M * K) {
				N -= (M * K);
				if (N > 0) {
					cnt += 1;
					N += 1;
				}
			}
			else break;
		}

		printf("%d\n", cnt);
	}

	return 0;
}
