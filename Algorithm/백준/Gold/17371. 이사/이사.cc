#include <iostream>
#include <cmath>

int N;
std::pair<int, int>* convs;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> N;
	convs = new std::pair<int, int>[N];
	
	for (int i = 0; i < N; ++i)
	{
		std::cin >> convs[i].first >> convs[i].second;
	}

	int result = 2e9;
	int pos_index;
	for (int start = 0; start < N; ++start)
	{
		double curr_max = 0;
		for (int end = 0; end < N; ++end)
		{
			curr_max = std::max(std::sqrt(std::pow(convs[start].first - convs[end].first, 2) + std::pow(convs[start].second - convs[end].second, 2)), curr_max);
		}

		if (result > curr_max)
		{
			result = curr_max;
			pos_index = start;
		}
	}
	printf("%d %d", convs[pos_index].first, convs[pos_index].second);
	return 0;
}