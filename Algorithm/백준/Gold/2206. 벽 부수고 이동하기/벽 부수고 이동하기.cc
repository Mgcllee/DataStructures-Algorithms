#include <iostream>
#include <queue>

#define SIZE 10

int N, M;
int** board;
int*** visited;
// int visited[SIZE][SIZE][2];

struct POS {
	int x, y, breaking_wall;
};
int DFS()
{
	int dx[4]{ 0, 0, -1, 1 };
	int dy[4]{ 1, -1, 0, 0 };
	std::queue<POS> q;
	q.push(POS{ 1, 1, 0 });
	visited[1][1][0] = 1;

	while (false == q.empty())
	{
		POS curr = q.front();
		q.pop();

		if (curr.x == M && curr.y == N)
			return visited[curr.y][curr.x][curr.breaking_wall];

		for (int di = 0; di < 4; ++di)
		{
			POS next{ curr.x + dx[di], curr.y + dy[di], curr.breaking_wall };

			if (next.y <= 0 || next.y > N || next.x <= 0 || next.x > M) continue;
			if (visited[next.y][next.x][curr.breaking_wall]) continue;

			if (0 == board[next.y][next.x])
			{
				visited[next.y][next.x][next.breaking_wall]
					= 1 + visited[curr.y][curr.x][curr.breaking_wall];
				q.push(POS{ next.x, next.y, curr.breaking_wall });
			}

			if (1 == board[next.y][next.x] && 0 == next.breaking_wall)
			{
				visited[next.y][next.x][1] = 1 + visited[curr.y][curr.x][curr.breaking_wall];
				next.breaking_wall = 1;

				q.push(next);
			}
		}
	}

	return -1;
}

int main()
{
	std::cin >> N >> M;
	visited = new int** [N + 1];
	for (int i = 1; i <= N; ++i)
	{
		visited[i] = new int* [M + 1];
		for (int j = 1; j <= M; ++j)
		{
			visited[i][j] = new int[2] {0, 0};
		}
	}

	board = new int* [N + 1];
	for (int i = 1; i <= N; ++i) 
	{
		board[i] = new int[M + 1];
		for (int j = 1; j <= M; ++j)
		{
			scanf("%1d", &board[i][j]);
		}
	}

	printf("%d", DFS());
}