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
			return lhs.second > lhs.second;
		}
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, maxCnt = 1;
	std::cin >> N;
	std::map<int, int> map;
	std::multiset<std::pair<int, int>, ORDER> set;
	for (int i = 0, temp; i < N; ++i) {
		std::cin >> temp;
		if (false == map.insert({ temp, 1 }).second) {
			temp = map.find(temp)->second += 1;
			if (temp > maxCnt) maxCnt = temp;
		}
	}

	double sum = 0;
	int index = 0, cenVal = -4001;
	for (auto p : map) {
		sum += (p.first * p.second);
		index += p.second;
		if (index == N / 2 + 1 || (cenVal == -4001 && (index > N / 2 + 1))) cenVal = p.first;
		if (maxCnt == p.second)
			set.insert({ p.second, p.first });
	}

	double x = sum / N;
	double avg = round(x);
	if (avg == -0) avg = 0;
	printf("%d\n", (int)avg);
	printf("%d\n", cenVal);
	printf("%d\n", (set.size() > 1 ? (++set.begin())->second : set.begin()->second));
	printf("%d\n", (*map.rbegin()).first - (*map.begin()).first);

	return 0;
}