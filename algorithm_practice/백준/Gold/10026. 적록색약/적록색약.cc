#include <iostream>

int N;
char** colors;
bool** visited;

int dx[4]{ 0, 0, -1, 1 };
int dy[4]{ -1, 1, 0, 0 };

void DFS(int row, int col)
{
	visited[row][col] = true;

	for (int dir = 0; dir < 4; ++dir)
	{
		int new_col = dx[dir] + col;
		int new_row = dy[dir] + row;

		if (0 > new_col || 0 > new_row || N <= new_col || N <= new_row)
			continue;

		if (false == visited[new_row][new_col]
			&& colors[new_row][new_col] == colors[row][col])
		{
			DFS(new_row, new_col);
		}
	}
}

int main()
{
	std::cin >> N;
	colors = new char* [N];
	visited = new bool* [N];
	for (int row = 0; row < N; ++row)
	{
		colors[row] = new char[N];
		visited[row] = new bool[N];
		std::fill(visited[row], visited[row] + N, false);
		for (int col = 0; col < N; ++col)
		{
			std::cin >> colors[row][col];
		}
	}

	int result = 0;
	for (int row = 0; row < N; ++row)
	{
		for (int col = 0; col < N; ++col)
		{
			if (false == visited[row][col])
			{
				DFS(row, col);
				++result;
			}
		}
	}
	printf("%d ", result);
	
	result = 0;
	for (int row = 0; row < N; ++row)
	{
		std::fill(visited[row], visited[row] + N, false);
		for (int col = 0; col < N; ++col)
		{
			if ('R' == colors[row][col])
				colors[row][col] = 'G';
		}
	}

	for (int row = 0; row < N; ++row)
	{
		for (int col = 0; col < N; ++col)
		{
			if (false == visited[row][col])
			{
				DFS(row, col);
				++result;
			}
		}
	}
	printf("%d", result);
}