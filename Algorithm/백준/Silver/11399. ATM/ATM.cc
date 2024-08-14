#include <iostream>
#include <set>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int N, sum = 0, index = 0;
	std::cin >> N;
	int* arr = new int[N + 1];
	std::fill(arr, arr + N + 1, 0);

	std::multiset<int> set;

	for (int i = 1, temp; i <= N; ++i)
	{
		std::cin >> temp;
		set.insert(temp);
	}
	
	for (int n : set)
	{
		arr[index] = (sum += n);
		++index;
	}

	sum = 0;
	for (int i = 0; i < N; ++i)
	{
		sum += arr[i];
	}

	printf("%d", sum);
	return 0;
}