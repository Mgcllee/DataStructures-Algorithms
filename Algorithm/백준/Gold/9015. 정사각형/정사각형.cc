#include <iostream>
#include <set>

int main()
{
	std::cin.tie(0)->sync_with_stdio(false);
	
	int T, N;
	std::cin >> T;
	for (int tc = 0; tc < T; ++tc)
	{
		std::cin >> N;
		auto arr = new std::pair<int, int>[N];
		std::set<std::pair<int, int>> set;

		for (int i = 0, x, y; i < N; ++i)
		{
			std::cin >> x >> y;
			arr[i] = { x, y };
			set.emplace(x, y);
		}

		int result = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				int dx = arr[i].first - arr[j].first;
				int dy = arr[i].second - arr[j].second;

				std::pair<int, int> p1 = { arr[i].first - dy, arr[i].second + dx };
				std::pair<int, int> p2 = { arr[j].first - dy, arr[j].second + dx };

				if (set.count(p1) && set.count(p2))
				{
					int temp = dx * dx + dy * dy;
					result = temp > result ? temp : result;
				}
			}
		}

		printf("%d\n", result);
	}
	return 0;
}