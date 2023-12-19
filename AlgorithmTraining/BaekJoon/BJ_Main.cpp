#include <iostream>
#include <cmath>

int main() {
	int K = 0, N = 0, sum = 0;
	std::cin >> K >> N;
	int* arr = new int[K];

	for (int t = 0; t < K; ++t) {
		std::cin >> arr[t];
		sum += arr[t];
	}

	int maxVal = sum / N;
	int minVal = maxVal;
	int pos = 0;
	for (; minVal >= 10; ++pos) minVal /= 10;
	minVal = minVal * pow(10, pos);

	int maxCnt = 0;
	int maxLen = 0;
	for (int v = maxVal; v >= minVal; --v) {
		int currCnt = 0;

		for (int i = 0; i < K; ++i) {
			currCnt += (arr[i] / v);
		}
		if (currCnt > maxCnt){
			maxCnt = currCnt;
			maxLen = v;
		}
	}

	std::cout << maxLen;
	return 0;
}