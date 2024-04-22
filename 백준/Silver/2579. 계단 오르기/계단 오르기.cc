#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int N;
	std::cin >> N;
	
	int* step = new int[N];
	std::fill(step, step + N, 0);

	int* DP = new int[N];
	std::fill(DP, DP + N, 0);

	for (int i = 0; i < N; ++i)
	{
		std::cin >> step[i];
	}
	DP[0] = step[0];
	DP[1] = step[0] + step[1];

	for (int i = 2; i < N; ++i)
	{
		DP[i] = std::max(step[i - 1] + DP[i - 3] + step[i], DP[i - 2] + step[i]);
	}
	printf("%d", DP[N - 1]);

	return 0;
}