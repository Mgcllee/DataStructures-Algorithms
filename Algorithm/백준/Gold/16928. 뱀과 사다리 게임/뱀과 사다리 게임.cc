#include <iostream>
#include <vector>
#include <queue>

int cnt_bridge, cnt_snake;
std::vector<int>* board = new std::vector<int>[101];
bool visited[101]{ false };

void BFS()
{
	std::queue<std::pair<int, int>> q;
	q.emplace(1, 0);
	std::fill(visited, visited + 101, false);
	visited[1] = true;

	while (false == q.empty())
	{
		int curr = q.front().first;
		int move_cnt = q.front().second;
		q.pop();

		if (curr >= 100)
		{
			printf("%d", move_cnt);
			return;
		}

		for (int next = 1; next <= 6; ++next)
		{
			if ((curr + next <= 100) && (false == visited[curr + next]))
			{
				visited[curr + next] = true;
				
				if (board[curr + next].size())
				{
					for (int bridge : board[curr + next])
					{
						q.emplace(bridge, move_cnt + 1);
					}
				}
				else
					q.emplace(curr + next, move_cnt + 1);
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> cnt_bridge >> cnt_snake;
	for (int bridge = 0; bridge < cnt_bridge; ++bridge)
	{
		int start, end;
		std::cin >> start >> end;
		board[start].push_back(end);
	}

	for (int snake = 0; snake < cnt_snake; ++snake)
	{
		int start, end;
		std::cin >> start >> end;
		board[start].push_back(end);
	}

	BFS();

	return 0;
}