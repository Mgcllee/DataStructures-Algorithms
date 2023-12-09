#include <iostream>
#include <list>
#include <set>

int main() {
	int testCnt = 0;
	std::cin >> testCnt;

	for (int i = 0; i < testCnt; ++i) {
		int cnt, target;
		std::cin >> cnt >> target;
		std::list<std::pair<int, int>> list;
		std::multiset<int, std::greater<int>> set;

		// Push/Pop의 기준은 temp 값
		for (int j = 0, temp; j < cnt; ++j) {
			std::cin >> temp;
			list.push_back(std::make_pair(temp, j));
			set.insert(temp);
		}

		int index = 1;
		for (int n : set) {
			while (true) {
				if ((n == list.front().first) && (target == list.front().second)) {
					printf("%d\n", index);
					index = -1;
					break;
				}
				else if (n == list.front().first) {
					index += 1;
					list.pop_front();
					break;
				}
				else {
					list.push_back(list.front());
					list.pop_front();
				}
			}
			if (-1 == index) break;
		}
	}
}