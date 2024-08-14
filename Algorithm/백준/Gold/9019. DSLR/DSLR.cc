#include <iostream>
#include <cstring>
#include <queue>

int T, start, goal;
bool visited[10000]{};

void BFS()
{
	std::queue<std::pair<std::string, int>> q;
	q.push(std::make_pair("", start));
	visited[start] = true;

	while (false == q.empty())
	{
		std::string curr_cal = q.front().first;
		int curr_num = q.front().second;

		if (goal == curr_num) 
		{
			std::cout << curr_cal << '\n';
			return;
		}
		q.pop();

		int l_index = (curr_num * 10 + curr_num / 1000) % 10000;
		if (false == visited[l_index])
		{
			visited[l_index] = true;
			q.push(std::make_pair(curr_cal + "L", l_index));
		}

		int r_index = (curr_num / 10 + 1000 * (curr_num % 10));
		if (false == visited[r_index])
		{
			visited[r_index] = true;
			q.push(std::make_pair(curr_cal + "R", r_index));
		}

		int d_index = curr_num * 2 > 9999 ? (curr_num * 2 % 10000) : curr_num * 2;
		if (false == visited[d_index])
		{
			visited[d_index] = true;
			q.push(std::make_pair(curr_cal + "D", d_index));
		}

		int s_index = curr_num == 0 ? 9999 : curr_num - 1;
		if (false == visited[s_index])
		{
			visited[s_index] = true;
			q.push(std::make_pair(curr_cal + "S", s_index));
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> T;
	for (int tc = 0; tc < T; ++tc)
	{
		std::cin >> start >> goal;
		BFS();
		memset(visited, 0, sizeof(bool) * 10000);
	}
	return 0;
}