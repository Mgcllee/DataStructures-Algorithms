#include <iostream>
#include <map>

int* arr;

void Combination(int low, int high, int sum, std::map<int, int>& cache)
{
	if (low == high)
	{
		++cache[sum];
		return;
	}

	Combination(low + 1, high, sum, cache);
	Combination(low + 1, high, sum + arr[low], cache);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int N, S;
	std::cin >> N >> S;
	arr = new int[N];
	
	for (int i = 0; i < N; ++i)
	{
		std::cin >> arr[i];
	}

	std::map<int, int> left;
	std::map<int, int> right;
	Combination(0, N / 2, 0, left);
	Combination(N / 2, N, 0, right);

	long long result = 0;
	for (auto it = left.begin(); it != left.end(); ++it)
	{
		result += (long long)right[S - it->first] * (long long)it->second;
	}
	if (S == 0)
		--result;

	printf("%lld", result);
	return 0;
}