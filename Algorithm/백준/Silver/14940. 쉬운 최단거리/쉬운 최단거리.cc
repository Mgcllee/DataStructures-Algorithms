#include <iostream>
#include <cstring>
#include <queue>

int dx[4]{ 0, 0, -1, 1 };
int dy[4]{ -1, 1, 0, 0 };

int input_row, input_col;
int M, N, goal_row, goal_col;
bool** map;
bool** visited;
int** result;

void DFS(int curr_row, int curr_col)
{
	for (int dir = 0; dir < 4; ++dir)
	{
		int new_row = dy[dir] + curr_row;
		int new_col = dx[dir] + curr_col;

		if (new_row >= 0 && new_row < N
			&& new_col >= 0 && new_col < M
			&& map[new_row][new_col])
		{
			map[new_row][new_col] = false;
			DFS(new_row, new_col);
		}
	}
}

void BFS(int start_row, int start_col)
{
	std::queue<std::pair<int, int>> q;
	q.push(std::make_pair(start_row, start_col));
	visited[start_row][start_col] = true;

	map[start_row][start_col] = false;
	result[start_row][start_col] = 0;

	while (false == q.empty())
	{
		int curr_row = q.front().first;
		int curr_col = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int new_row = dy[dir] + curr_row;
			int new_col = dx[dir] + curr_col;

			if (new_row < 0 || new_row >= N
				|| new_col < 0 || new_col >= M)
				continue;
			if (visited[new_row][new_col])
				continue;
			if (map[new_row][new_col] == 0)
				continue;

			visited[new_row][new_col] = true;
			result[new_row][new_col] = result[curr_row][curr_col] + 1;

			q.push(std::make_pair(new_row, new_col));
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> N >> M;

	map = new bool* [N];
	visited = new bool* [N];
	result = new int* [N];

	for (int i = 0; i < N; i++)
	{
		map[i] = new bool[M];
		visited[i] = new bool[M];
		result[i] = new int[M];

		memset(visited[i], false, M * sizeof(bool));
		memset(result[i], 0, M * sizeof(int));

		for (int j = 0; j < M; ++j)
		{
			int temp;
			std::cin >> temp;
			if (temp == 1)
			{
				map[i][j] = true;
			}
			else if (temp == 0)
			{
				map[i][j] = false;
			}
			else if (temp == 2)
			{
				goal_row = i;
				goal_col = j;
			}
		} 
	}

	BFS(goal_row, goal_col);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; ++j)
		{
			if ((result[i][j] == 0) && map[i][j]) printf("-1 ");
			else printf("%d ", result[i][j]);
		}	printf("\n");
	}

	return 0;
}