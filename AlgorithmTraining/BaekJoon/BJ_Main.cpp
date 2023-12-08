#include <iostream>
#include <set>

/*
Queue의 FIFO를 사용하기 때문에
순서가 매우 중요하다.
(Pop된 값이 Push인지 아닌지 파악하기 위해)
*/

struct myOrder
{
	bool operator() (const std::pair<int, int>& left, const std::pair<int, int>& right) const
	{
		return left.first > right.first;
	}
};

int main() {
	int testCnt = 0;
	std::cin >> testCnt;

	for (int i = 0; i < testCnt; ++i) {
		int cnt, target;
		std::cin >> cnt >> target;
		std::multiset<std::pair<int, int>, myOrder> set;
		
		for (int j = 0, temp; j < cnt; ++j) {
			std::cin >> temp;
			set.insert(std::make_pair(temp, j));
		}

		for (auto p : set) {
			printf("(%d, %d), ", p.first, p.second);
		}	printf("\n");
	}
}