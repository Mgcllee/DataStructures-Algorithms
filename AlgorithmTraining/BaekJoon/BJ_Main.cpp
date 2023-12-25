#include <iostream>
#include <list>
#include <cmath>

int main() {
	int n;
	std::cin >> n;
	if (n == 0) {
		printf("0\n");
		return 0;
	}

	std::list<int> list;
	for (int i = 0, temp; i < n; ++i) {
		std::cin >> temp;
		list.push_back(temp);
	}
	list.sort();

	int expt_cnt = (int)std::round((float)n * 0.3f * 0.5f);
	for (int i = 0; i < expt_cnt; ++i) {
		if (false == list.empty()) list.pop_front();
		if (false == list.empty()) list.pop_back();
	}
	float sum = 0;
	for (int n : list)
		sum += n;
	printf("%d", (int)(std::round(sum / list.size())));
	return 0;
}