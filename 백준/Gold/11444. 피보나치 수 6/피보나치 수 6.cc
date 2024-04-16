#include <iostream>
#include <map>

#define MOD 1'000'000'007

std::map<long long, long long> map;

long long fibonacci(long long n)
{
	if (map[n]) return map[n];

	long long result;
	if (n % 2 == 0)
	{
		result =
			fibonacci(n / 2)
			*
			(fibonacci(n / 2 + 1) + fibonacci(n / 2 - 1))
			%
			MOD;
	}
	else
	{
		result =
			(fibonacci((n + 1) / 2) * fibonacci((n + 1) / 2) % MOD)
			+
			((fibonacci((n - 1) / 2) * fibonacci((n - 1) / 2)) % MOD)
			%
			MOD;
	}

	return map[n] = result % MOD;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	long long n;
	std::cin >> n;
	map[0] = 0;
	map[1] = 1;
	map[2] = 1;

	std::cout << fibonacci(n);
	return 0;
}