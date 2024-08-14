#include <iostream>
#include <string>

int goal, error_cnt;
bool error_arr[10]{ false, };

bool contain_error_num(int target)
{
	for (char& c : std::to_string(target))
	{
		if (error_arr[int(c - '0')])
			return true;
	}
	return false;
}

int brute_force()
{
	int min_move = 2e9;
	int ch_len;
	for (int curr = 0; curr < 1'000'001; ++curr)
	{
		if (false == contain_error_num(curr))
		{
			int dis_ch = std::abs(goal - curr);
			
			if (min_move > dis_ch)
			{
				min_move = dis_ch;
				ch_len = std::to_string(curr).size();
			}
		}
	}

	int result_01 = min_move + ch_len;
	int result_02 = std::abs(goal - 100);

	return result_01 > result_02 ? result_02 : result_01;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> goal >> error_cnt;
	std::string str_goal = std::to_string(goal);

	for (int i = 0; i < error_cnt; ++i)
	{
		int temp;
		std::cin >> temp;
		error_arr[temp] = true;
	}

	std::cout << brute_force();
	return 0;
}