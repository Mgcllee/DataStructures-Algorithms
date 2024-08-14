#include <iostream>
#include <queue>
#include <cstring>

/*
[문제점]
1. 치즈 내부 공간을 판단할 수 없음.
2. 최악의 경우 O(N * M)
*/
class first_program
{
	struct POS {
		int x, y;
		int melet_line;
		int time;
	};

	int dx[4]{ 1, 0, -1, 0 };
	int dy[4]{ 0, 1, 0, -1 };

	POS** board;

	void solution()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(0);

		int N, M, melt_time = 1, chz_cnt = 0;
		std::cin >> N >> M;
		board = new POS * [N];

		for (int hei = 0; hei < N; ++hei)
		{
			board[hei] = new POS[M];
			for (int wid = 0; wid < M; ++wid)
			{
				board[hei][wid].x = wid;
				board[hei][wid].y = hei;
				std::cin >> board[hei][wid].melet_line;
				if (board[hei][wid].melet_line == 1) {
					// board[hei][wid].time = 1;
					chz_cnt += 1;
				}
				board[hei][wid].time = 0;
			}
		}

		while (0 != chz_cnt)
		{
			for (int hei = 0; hei < N && 0 != chz_cnt; ++hei)
			{
				for (int wid = 0; wid < M && 0 != chz_cnt; ++wid)
				{
					if (0 == board[hei][wid].melet_line) continue;

					int melt_cnt = 0;
					for (int di = 0; di < 4; ++di)
					{
						int new_x = dx[di] + board[hei][wid].x;
						int new_y = dy[di] + board[hei][wid].y;

						if (new_x < 0 || new_x >= M || new_y < 0 || new_y >= N) continue;
						if (0 == board[new_y][new_x].melet_line)
						{
							melt_cnt += 1;
						}
					}

					if (melt_cnt >= 2 && (board[hei][wid].melet_line == 1))
					{
						chz_cnt -= 1;
						board[hei][wid].time = melt_time;
					}
				}
			}
			for (int hei = 0; hei < N; ++hei)
			{
				for (int wid = 0; wid < M; ++wid)
				{
					if (1 == board[hei][wid].time) board[hei][wid].time = 0;
				}
			}

			melt_time += 1;
		}

		printf("%d", melt_time);
	}
};

class second_program 
{
public:
	second_program(int hei, int wid, int** in_board) :
		N(hei)
		, M(wid)
		, board(in_board)
		, total_time(0)
	{
		visited = new bool*[N + 1];
		air = new int* [N + 1];
		for (int i = 0; i < N; ++i) 
		{
			visited[i] = new bool[M + 1] {false};
			air[i] = new int[M + 1] {0};
		}
	}

	void run() // use BFS algorithm
	{
		while (true) 
		{
			for (int hei = 0; hei < N; ++hei)
			{
				for (int wid = 0; wid < M; ++wid)
				{
					visited[hei][wid] = false;
					air[hei][wid] = 0;
				}
			}

			std::queue<std::pair<int, int>> q;
			q.push(std::make_pair(0, 0));

			while (false == q.empty())
			{
				std::pair<int, int> pos = q.front();
				q.pop();

				if (visited[pos.second][pos.first])
					continue;
				visited[pos.second][pos.first] = true;

				for (int di = 0; di < 4; ++di)
				{
					int new_x = dx[di] + pos.first;
					int new_y = dy[di] + pos.second;

					if (new_x < 0 || new_x >= M || new_y < 0 || new_y >= N)
						continue;

					if (1 == board[new_y][new_x])
						++air[new_y][new_x];
					else if (false == visited[new_y][new_x])
						q.push(std::make_pair(new_x, new_y));
				}
			}

			bool is_melt = false;
			for (int hei = 0; hei < N; ++hei)
			{
				for (int wid = 0; wid < M; ++wid)
				{
					if (air[hei][wid] >= 2)
					{
						board[hei][wid] = 0;
						is_melt = true;
					}
				}
			}

			if (is_melt) total_time += 1;
			else break;
		}
	}

	int get_total_time()
	{
		return total_time;
	}

private:
	int N, M;

	int dx[4]{ 0, 0, -1, 1 };
	int dy[4]{ 1, -1, 0, 0 };

	bool** visited;
	int** board;
	int** air;

	int total_time;
};

int main()
{
	int N, M;
	int** board;
	std::cin >> N >> M;
	board = new int* [N];

	for (int i = 0; i < N; ++i)
	{
		board[i] = new int[M];
		for (int j = 0; j < M; ++j)
		{
			std::cin >> board[i][j];
		}
	}

	second_program p(N, M, board);
	p.run();
	printf("%d", p.get_total_time());

	return 0;
}