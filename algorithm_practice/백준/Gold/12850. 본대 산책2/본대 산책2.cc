#include <iostream>
#include <vector>

#define BUILDING_COUNT 8

#define MOD 1'000'000'007

int D;
std::vector<std::vector<long long>> grid
{ 
	{0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 1, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 0, 1, 1, 0},
	{0, 0, 0, 1, 1, 0, 0, 1},
	{0, 0, 0, 0, 1, 0, 0, 1},
	{0, 0, 0, 0, 0, 1, 1, 0}
};
std::vector<std::vector<long long>> result
	(BUILDING_COUNT, std::vector<long long>(BUILDING_COUNT));

template<class T>
T Multiple(const T& grid01, const T& grid02)
{
	T ret_grid(BUILDING_COUNT, std::vector<long long>(BUILDING_COUNT));
	for (int row = 0; row < BUILDING_COUNT; ++row)
	{
		for (int col = 0; col < BUILDING_COUNT; ++col)
		{
			long long sum = 0;
			for (int curr = 0; curr < BUILDING_COUNT; ++curr)
			{
				sum += (grid01[row][curr] * grid02[curr][col]);
				sum %= MOD;
			}
			ret_grid[row][col] = sum % MOD;
		}
	}
	return ret_grid;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	for (int index = 0; index < BUILDING_COUNT; ++index)
		result[index][index] = 1;

	std::cin >> D;
	auto factor = grid;
	while (D)
	{
		if (D & 1)
		{
			result = Multiple(result, factor);
			D -= 1;
		}
		factor = Multiple(factor, factor);
		D /= 2;
	}

	std::cout << result[0][0];
	return 0;
}