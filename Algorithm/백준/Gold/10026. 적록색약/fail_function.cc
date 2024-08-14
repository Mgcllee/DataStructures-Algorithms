#include <iostream>
#include <vector>

int N;
int dx[4]{ 0, -1, 0, 1 };
int dy[4]{ -1, 0, 1, 0 };
char** board;
int** map;

#define R 0
#define G 1
#define B 2
int counter[3]{ R, G, B };

std::vector<std::pair<int, int>> find_same(int y, int x)
{
	std::vector<std::pair<int, int>> ret;
	for (int dir = 0; dir < 4; ++dir)
	{
		int new_x = dx[dir] + x;
		int new_y = dy[dir] + y;

		if (new_x < 0 || new_y < 0 || new_x >= N || new_y >= N)
			continue;

		if (board[y][x] == board[new_y][new_x])
		{
			ret.push_back({new_y, new_x});
		}
	}

	if (ret.size() != 0)
	{
		return ret;
	}
	else
	{
		ret.clear();
		return ret;
	}
}
std::vector<std::pair<int, int>> red_green_find_same(int y, int x)
{
	std::vector<std::pair<int, int>> ret;
	for (int dir = 0; dir < 4; ++dir)
	{
		int new_x = dx[dir] + x;
		int new_y = dy[dir] + y;

		if (new_x < 0 || new_y < 0 || new_x >= N || new_y >= N)
			continue;

		if ((board[y][x] == 'R' && board[new_y][new_x] == 'G')
			|| (board[y][x] == 'G' && board[new_y][new_x] == 'R')
			|| (board[y][x] == board[new_y][new_x]))
		{
			ret.push_back({ new_y, new_x });
		}
	}

	if (ret.size() != 0)
	{
		return ret;
	}
	else
	{
		ret.clear();
		return ret;
	}
}

int normal()
{
	map[0][0] = 0;
	int curr_max_number = 0;
	for (int row = 0; row < N; ++row)
	{
		for (int col = 0; col < N; ++col)
		{
			auto poss = find_same(row, col);
			int min = 2e9;
			for (auto pos : poss)
			{
				if (min > map[pos.first][pos.second])
				{
					min = map[pos.first][pos.second];
				}
			}

			if (min != 2e9)
			{
				for (auto pos : poss)
				{
					if ((min != map[pos.first][pos.second])
						&& (2e9 != map[pos.first][pos.second]))
					{
						curr_max_number = map[pos.first][pos.second] - 1;
					}

					map[pos.first][pos.second] = min;

				}
			}
			else
			{
				map[row][col] = ++curr_max_number;
				for (auto pos : poss)
				{
					map[pos.first][pos.second] = map[row][col];
				}
			}
		}
	}
	return curr_max_number;
}
int red_green()
{
	for (int row = 0; row < N; ++row)
	{
		std::fill(map[row], map[row] + N, 2e9);
	}

	map[0][0] = 0;
	int curr_max_number = 0;
	for (int row = 0; row < N; ++row)
	{
		for (int col = 0; col < N; ++col)
		{
			auto poss = red_green_find_same(row, col);
			int min = 2e9;
			for (auto pos : poss)
			{
				if (min > map[pos.first][pos.second])
				{
					min = map[pos.first][pos.second];
				}
			}

			if (min != 2e9)
			{
				for (auto pos : poss)
				{
					if ((min != map[pos.first][pos.second])
						&& (2e9 != map[pos.first][pos.second]))
					{
						curr_max_number = map[pos.first][pos.second] - 1;
					}

					map[pos.first][pos.second] = min;

				}
			}
			else
			{
				map[row][col] = ++curr_max_number;
				for (auto pos : poss)
				{
					map[pos.first][pos.second] = map[row][col];
				}
			}
		}
	}
	return curr_max_number;
}

int main()
{
	std::cin >> N;
	board = new char* [N];
	map = new int* [N];
	for (int row = 0; row < N; ++row)
	{
		board[row] = new char[N];
		map[row] = new int[N];
		std::fill(map[row], map[row] + N, 2e9);
		for (int col = 0; col < N; ++col)
		{
			std::cin >> board[row][col];
		}
	}

	printf("%d ", normal());
	printf("%d", red_green());

	return 0;
}
