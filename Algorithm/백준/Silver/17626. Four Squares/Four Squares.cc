#include <iostream>

int* DP;

int main()
{
	int n;
	std::cin >> n;
	DP = new int[n + 1];
	std::fill(DP, DP + n + 1, 0);

	/*while (N != 0)
	{
		int temp = std::floor(std::sqrt(N));
		N -= std::pow(temp, 2);
		printf("%d - %d\n", N, temp);
		++cnt;
	}*/

	for (int i = 1; i <= n; i++) {
		DP[i] = DP[i - 1] + 1;
		for (int j = 1; j * j <= i; j++) {
			DP[i] = std::min(DP[i], DP[i - j * j] + 1);
		}
	}

	printf("%d", DP[n]);
	return 0;
}