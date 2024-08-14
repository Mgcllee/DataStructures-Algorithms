#include <iostream>
#include <vector>
#include <algorithm>

int N, M, K, ans;
std::vector<int> route;

void func(std::vector<std::vector<int>>& key, int curr_index, int cnt) {

	if (cnt == N) {
		int c = 0;
		
		for (auto& i : key) 
		{
			bool flag = true;
			for (auto& j : i) 
			{
				if (!std::binary_search(route.begin(), route.end(), j)) 
				{
					flag = false;
					break;
				}
			}

			if (flag)
				c++;
		}

		ans = std::max(ans, c);
		return;
	}

	for (int i = curr_index; i <= 2 * N; i++) 
	{
		route.push_back(i);
		func(key, i + 1, cnt + 1);
		route.pop_back();
	}
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> N >> M >> K;
	std::vector<std::vector<int>> key(M, std::vector<int>(K));

	for (int quest_index = 0; quest_index < M; ++quest_index)
	{
		for (int skill_index = 0; skill_index < K; skill_index++)
		{
		std::cin >> key[quest_index][skill_index];
		}
	}

	func(key, 1, 0);
	
	printf("%d", ans);
	return 0;
}
