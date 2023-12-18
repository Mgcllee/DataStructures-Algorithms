#include <iostream>
#include <cmath>
#include <map>
#include <set>

struct ORDER {
	bool operator() (const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const
	{
		if (lhs.first > rhs.first) return true;
		else if (lhs.first < rhs.first) return false;
		else {
			return lhs.second > lhs.first;
		}
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, firstVal = 0;
	std::cin >> N;
	std::map<int, int> map;
	std::multiset<std::pair<int, int>, ORDER> set;
	for (int i = 0, temp; i < N; ++i) {
		std::cin >> temp;
		if (i == 0) firstVal = temp;
		if (false == map.insert({ temp, 1 }).second) {
			map.find(temp)->second += 1;
		}
	}

	long long sum = 0;
	int index = 0, cenVal = 0;
	for (auto p : map) {
		sum += (p.first * p.second);
		index += p.second;
		if (index == N / 2 + 1) cenVal = p.first;
		set.insert({p.second, p.first});
	}

	auto first_p = *set.begin();
	for (auto p : set) {
		if (first_p != p && first_p.first == p.first && first_p.first > p.first) {
			first_p = p;
		}
		
	}

	printf("%d\n", (int)round((float)sum / (float)N));
	printf("%d\n", cenVal);
	printf("%d\n", (set.size() == N) ? firstVal : (--set.rbegin())->second);
	printf("%d\n", (*map.rbegin()).first - (*map.begin()).first);

	return 0;
}