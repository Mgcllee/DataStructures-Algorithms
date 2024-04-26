#include <iostream>
#include <cstring>
#include <queue>

int dx[4]{ 0, 0, -1, 1 };
int dy[4]{ 1, -1, 0, 0 };

int T, M, N, K;
bool map[55][55]{ 0 };

void DFS(int x, int y)
{
	for (int dir = 0; dir < 4; ++dir)
	{
		int X = dy[dir] + x;
		int Y = dx[dir] + y;

		if (Y >= 0 && Y < M
			&& X >= 0 && X < N
			&& map[X][Y])
		{
			map[X][Y] = false;
			DFS(X, Y);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> T;
	for (int tc = 0; tc < T; ++tc)
	{
		std::cin >> M >> N >> K;

		for (int i = 0; i < N; i++)
		{
			memset(map[i], false, M * sizeof(bool));
		}

		for (int c = 0; c < K; ++c)
		{
			int x, y;
			std::cin >> x >> y;
			map[y][x] = true;
		}

		int result = 0;
		for (int row = 0; row < N; ++row)
		{
			for (int col = 0; col < M; ++col)
			{
				if (map[row][col])
				{
					++result;
					DFS(row, col);
				}
			}
		}

		printf("%d\n", result);
	}
	return 0;
}