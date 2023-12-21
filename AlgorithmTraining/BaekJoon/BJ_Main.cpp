#include <iostream>
#include <cmath>

int main() {
	// N: 세로길이, M: 가로길이, B: 인벤내부 수
	int N, M, B;
	std::cin >> N >> M >> B;
	int** arr = new int*[N];
	for (int i = 0; i < N; ++i) arr[i] = new int[M];

	long long sum = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			std::cin >> arr[i][j];
			sum += arr[i][j];
		}
	}
	int avg = std::round(sum / (N * M));

	while (avg >= 0) {
		long long usedBlock = 0;
		long long saveBlock = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				int dis = arr[i][j] - avg;
				if (dis > 0)
					saveBlock += dis;
				else if (dis < 0)
					usedBlock -= dis;
			}
		}

		if (saveBlock + B >= usedBlock) {
			long long time = saveBlock * 2 + usedBlock;
			printf("%lld %d", time, avg);
			break;
		}
		else avg -= 1;
	}
	return 0;
}