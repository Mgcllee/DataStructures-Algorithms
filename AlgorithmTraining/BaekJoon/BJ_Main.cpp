#include <iostream>

int size; 
long long cnt;
long long DP[91];

long long Com(int currSize)
{
	if (2 >= currSize) {
		return 1;
	}

	if (DP[currSize] != 0) {
		return DP[currSize];
	}

	return DP[currSize] = Com(currSize - 2) + Com(currSize - 1);
}

int main()
{
	std::cin >> size;
	std::cout << Com(size);
	return 0;
}