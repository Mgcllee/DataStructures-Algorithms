#include <iostream>

int main() {
	int N, cnt = 0;
	std::cin >> N;

	while (true) {
		if (N % 5 == 0) {
			cnt += N / 5;
			printf("%d", cnt);
			break;
		}

		N -= 3;
		cnt += 1;

		if (N < 0) {
			printf("-1");
			break;
		}
	}
}