#include <iostream>

int R, T, C;
int ac_up_pos = -1;	// 반드시 1열임, 바로 아래 이어짐
int** curr_board;
int** next_board;

short dx[4]{ 0, 0, -1, 1 };
short dy[4]{ -1, 1, 0, 0 };

void print()
{
	for (int row = 0; row < R; ++row)
	{
		for (int col = 0; col < C; ++col)
		{
			printf("%d ", next_board[row][col]);
		}	printf("\n");
	}
}
void diffusion()
{
	for (int row = 0; row < R; ++row)
	{
		for (int col = 0; col < C; ++col)
		{
			if (0 < curr_board[row][col])
			{
				int diff_cnt = 0;
				for (short dir = 0; dir < 4; ++dir)
				{
					int new_row = row + dy[dir];
					int new_col = col + dx[dir];

					if (new_row < 0 || new_row >= R || new_col < 0 || new_col >= C)
						continue;
					if (new_col == 0 && (new_row == ac_up_pos || new_row == ac_up_pos + 1))
						continue;

					++diff_cnt;
					next_board[new_row][new_col] += (curr_board[row][col] / 5);
				}

				next_board[row][col] += (curr_board[row][col] - (curr_board[row][col] / 5) * diff_cnt);
			}
		}
	}
}
void clean_up()
{
	// Top
	for (int row = ac_up_pos - 1; row >= 0; --row)
	{
		next_board[row + 1][0] = next_board[row][0];
		if (row + 1 == ac_up_pos)
			next_board[row + 1][0] = 0;
	}
	for (int col = 1; col < C; ++col)
	{
		next_board[0][col - 1] = next_board[0][col];
	}
	for (int row = 1; row <= ac_up_pos; ++row)
	{
		next_board[row - 1][C - 1] = next_board[row][C - 1];
	}
	for (int col = C - 1; col > 0; --col)
	{
		next_board[ac_up_pos][col] = next_board[ac_up_pos][col - 1];
	}

	// Bottom
	for (int row = ac_up_pos + 1; row + 1 < R; ++row)
	{
		next_board[row][0] = next_board[row + 1][0];
		if (row == ac_up_pos + 1)
			next_board[row][0] = 0;
	}
	for (int col = 0; col + 1 < C; ++col)
	{
		next_board[R - 1][col] = next_board[R - 1][col + 1];
	}
	for (int row = R - 1; row > ac_up_pos; --row)
	{
		next_board[row][C - 1] = next_board[row - 1][C - 1];
	}
	for (int col = C - 1; col > 0; --col)
	{
		next_board[ac_up_pos + 1][col] = next_board[ac_up_pos + 1][col - 1];
	}
}
void copy_board()
{
	for (int row = 0; row < R; ++row)
	{
		for (int col = 0; col < C; ++col)
		{
			curr_board[row][col] = next_board[row][col];
			next_board[row][col] = 0;
		}
	}
}

int main()
{
	std::cin.tie(0)->sync_with_stdio(false);
	std::cin >> R >> C >> T;

	curr_board = new int*[R];
	next_board = new int*[R];
	for (int row = 0; row < R; ++row)
	{
		curr_board[row] = new int[C];
		next_board[row] = new int[C];
		for (int col = 0; col < C; ++col)
		{
			std::cin >> curr_board[row][col];
			next_board[row][col] = 0;
			if (curr_board[row][col] == -1 && ac_up_pos == -1)
			{
				ac_up_pos = row;
			}
		}
	}

	for (int t = 0; t < T; ++t)
	{
		diffusion();
		clean_up();
		copy_board();
	}
	
	int result = 0;
	for (int row = 0; row < R; ++row)
	{
		for (int col = 0; col < C; ++col)
		{
			result += curr_board[row][col];
		}
	}
	printf("%d", result);
	return 0;
}
