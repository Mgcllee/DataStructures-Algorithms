#include <iostream>
using namespace std;

int main() {
	int* arr = new int[1'001];
	int* DP = new int[1'001];
	
	int N, sum = 0;
	cin >> N;
	
	for(int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	
	for(int i = 0; i < N; ++i) {
		DP[i] = 1;
		for(int j = 0; j < i; ++j) {
			if(arr[i] > arr[j]) {
				DP[i] = DP[i] > DP[j] + 1 ? DP[i] : DP[j] + 1;
			}
		}
		sum = DP[i] > sum ? DP[i] : sum;
	}
	
	printf("%d", sum);
	return 0;
}