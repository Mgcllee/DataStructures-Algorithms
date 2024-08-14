#include <iostream>
#include <queue>

int M, N;
int d_col[4]{ -1, 1, 0, 0 };
int d_row[4]{ 0, 0, 1, -1 };
short** board;
bool** visited;

struct POS3D {
	int row, col;
};
std::queue<POS3D> q;
int pure_tomato_cnt = 0;

/*
BFS와 다르다.
첫 입력에서 모든 그래프가 바로 그려지는 것이 아니라.
시간 흐름에 따라 그려지는 간선이 다르기 때문에
어느 노드와 연결될지 알 수 없다.
*/
int BFS()
{
	if (q.empty())
		return -1;

	int new_comp_tomato = 0;
	int next_time = 0;
	while (q.front().row != -1)
	{
		bool is_next = false;
		while (true)
		{
			int row = q.front().row;
			int col = q.front().col;
			q.pop();

			if (row == -1)
			{
				q.push(POS3D{ -1, -1 });
				break;
			}

			for (int dir = 0; dir < 4; ++dir)
			{
				int new_row = d_row[dir] + row;
				int new_col = d_col[dir] + col;

				if (new_row < 0 || new_row >= N || new_col < 0 || new_col >= M)
					continue;
				if (0 == board[new_row][new_col])
				{
					board[new_row][new_col] = 1;
					q.push(POS3D{ new_row, new_col });
					is_next = true;
					++new_comp_tomato;
				}
			}
		}
		
		if (is_next)
			++next_time;
	}

	return new_comp_tomato == pure_tomato_cnt ? next_time : -1;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> M >> N;
	board = new short* [N];
	visited = new bool* [N];
	for (int row = 0; row < N; ++row)
	{
		board[row] = new short[M];
		visited[row] = new bool[M];
		std::fill(visited[row], visited[row] + M, false);
		for (int col = 0; col < M; ++col)
		{
			std::cin >> board[row][col];
			if (1 == board[row][col])
			{
				q.push(POS3D{ row, col });
			}
			else if (0 == board[row][col])
			{
				++pure_tomato_cnt;
			}
		}
	}

	if (0 == pure_tomato_cnt) printf("0");
	else
	{
		q.push(POS3D{ -1, -1 });
		printf("%d", BFS());
	}
	return 0;
}