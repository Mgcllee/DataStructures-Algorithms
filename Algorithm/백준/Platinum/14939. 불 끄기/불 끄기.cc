#include <iostream>
#define SIZE 10

int curr_cnt = 0;
int result = 2e9;
bool board[SIZE][SIZE]{ 0 };
bool buf_board[SIZE][SIZE]{ 0 };
int dx[4]{ 0, 0, -1, 1 };
int dy[4]{ -1, 1, 0, 0 };

void check_around(int row, int col)
{
	buf_board[row][col] = !buf_board[row][col];

	for (short dir = 0; dir < 4; ++dir)
	{
		int new_row = row + dy[dir];
		int new_col = col + dx[dir];

		if (new_row < 0 || new_row >= SIZE || new_col < 0 || new_col >= SIZE)
			continue;

		buf_board[new_row][new_col] = !buf_board[new_row][new_col];
	}
}

bool count_bulb()
{
	for (int row = 0; row < SIZE; ++row)
	{
		for (int col = 0; col < SIZE; ++col)
		{
			if (buf_board[row - 1][col])
			{
				curr_cnt += 1;
				check_around(row, col);
			}
		}
	}

	for (int col = 0; col < SIZE; ++col)
		if (buf_board[SIZE - 1][col])
			return false;
	return true;
}

void solve()
{
	for (int bit_pos = 0; bit_pos < 1024; ++bit_pos)
	{
		for (int row = 0; row < SIZE; ++row)
		{
			for (int col = 0; col < SIZE; ++col)
			{
				buf_board[row][col] = board[row][col];
			}
		}

		curr_cnt = 0;
		for (int col = 0; col < SIZE; ++col)
		{
			if (bit_pos & (1 << col))
			{
				curr_cnt += 1;
				check_around(0, col);
			}
		}

		if (count_bulb())
			result = std::min(result, curr_cnt);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	// Input Section
	for (int row = 0; row < SIZE; ++row)
	{
		std::string line;
		std::cin >> line;

		for (int col = 0; col < SIZE; ++col)
		{
			board[row][col] = (line[col] == 'O' ? true : false);
		}
	}

	solve();
	std::cout << (result == 2e9 ? -1 : result);
	return 0;
}