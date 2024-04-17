#include <iostream>
#include <algorithm>

#define MIN -2e9
#define SETTING std::ios::sync_with_stdio(false), std::cin.tie(0)

int* arr;
int result_cnt = 0, size{};
std::pair<int, int>* temp;
int* result;

int main() 
{	
	std::cin >> size;
	arr = new int[size];
	temp = new std::pair<int, int>[size];
	
	std::fill(arr, arr + size, MIN);
	for (int i = 0, num; i < size; ++i)
	{
		std::cin >> num;
		int lower_pos = (int)(std::lower_bound(arr, arr + result_cnt, num) - arr);

		if (arr[lower_pos] == MIN)
		{
			result_cnt += 1;
		}
		
		arr[lower_pos] = num;

		temp[i].first = lower_pos;
		temp[i].second = num;
	}
	printf("%d\n", result_cnt);

	result = new int[result_cnt] {0};
	int result_size = result_cnt;
	for (int i = size - 1; i >= 0; --i)
	{
		if (temp[i].first == result_cnt - 1)
		{
			result[--result_cnt] = temp[i].second;
		}
	}
	
	for (int i = 0; i < result_size; ++i)
	{
		printf("%d ", result[i]);
	}
	return 0;
}