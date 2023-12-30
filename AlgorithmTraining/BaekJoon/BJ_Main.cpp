#include <iostream>

int main() {
	int N, K, cnt = 0;
	std::cin >> N >> K;
	
	
	int* arr = new int[N];
	for (int i = 0; i < N; ++i) {
		std::cin >> arr[i];
	}
	
	// 일단 입력은 다 받아야 함.
	if (N == 1) {
		cnt = 0;
	}
	else {
		int prev = arr[0];

		for (int i = 1; i < N; ++i) {
			if (prev < arr[i]) {
				prev = arr[i];
			}
			else if (prev < arr[i] + K) {
				cnt += 1;
				prev = arr[i] + K;
			}
			else {
				cnt = -1;
				break;
			}
		}
	}

	printf("%d", cnt);
	return 0;
}