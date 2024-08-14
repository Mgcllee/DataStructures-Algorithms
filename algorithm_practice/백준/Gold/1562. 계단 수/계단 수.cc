#include <iostream>
#define MOD 1'000'000'000

int N, result;
int DP[101][10][1 << 10];

int DFS(int index, int curr_num, int bit)
{
	if (DP[index][curr_num][bit])
		return DP[index][curr_num][bit];
	if (index == N)
		return bit == ((1 << 10) - 1) ? 1 : 0;

	int buffer = 0;
	if (curr_num + 1 < 10)
		buffer += DFS(index + 1, curr_num + 1, (bit | 1 << (curr_num + 1)));
	if (curr_num - 1 >= 0)
		buffer += DFS(index + 1, curr_num - 1, (bit | 1 << (curr_num - 1)));

	return DP[index][curr_num][bit] = buffer %= MOD;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> N;

	for (int start = 1; start <= 9; ++start)
	{
		result += DFS(1, start, 1 << start);
		result %= MOD;
	}
	printf("%d", result);
	return 0;
}