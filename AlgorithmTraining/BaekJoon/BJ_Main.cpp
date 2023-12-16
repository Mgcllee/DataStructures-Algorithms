#include <iostream>
#include <vector>

int maxSum = 0;
int cnt = 0;

void schedule(int day, std::vector<std::pair<int, int>> vec, int sum) {
	if (day > cnt) return;

	maxSum = maxSum >= sum ? maxSum : sum;
	for (int i = day; i < cnt; ++i) {
		schedule(vec[i].first + i, vec, sum + vec[i].second);
	}
}

int main()
{
	std::cin >> cnt;
	std::vector<std::pair<int, int>> vec;
	for (int i = 0, days, price; i < cnt; ++i) {
		std::cin >> days >> price;
		vec.push_back({ days, price });
	}

	schedule(0, vec, 0);

	std::cout << maxSum;
}