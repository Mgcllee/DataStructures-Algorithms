#include <iostream>
#include <cmath>

int main() {
	// N: 세로길이, M: 가로길이, B: 인벤내부 수
	int N, M, B;
	std::cin >> N >> M >> B;
	int** arr = new int* [N];
	for (int i = 0; i < N; ++i) arr[i] = new int[M];

	long long sum = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			std::cin >> arr[i][j];
			sum += arr[i][j];
		}
	}
	int avg = std::round(sum / (N * M));

	// 평탄화의 최소시간과 평균위치값
	/*
	평탄화할 때 위치값의 범위는
	블록의 최저높이부터 최고 높이 사이의 값에서만 존재한다.

	(1 <= 최저높이 <= 최고높이 <= 64)

	그러나 시간경과는 최저, 최고 높이에 맞춰 비례하지 않음

	*/

	while (avg >= 0) {
		long long usedBlock = 0;
		long long saveBlock = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				int dis = arr[i][j] - avg;
				if (dis > 0)
					saveBlock += dis;	// 제거 2초
				else if (dis < 0)
					usedBlock -= dis;	// 설치 1초
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