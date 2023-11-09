#include <iostream>
#include <vector>
#include <set>

int main() 
{
	std::multiset<int> con = { 3, 2, 4, 1, 2, 4, 1, 3, 2, 2 };
	for (auto N : con)
		std::cout << N << ", ";

	int temp = 0, cur = 0;
	while (*con.begin() != 3) {
		temp = *(con.rbegin() - cur);
		if (temp <= 3) break;
		else ++cur;
	}

	*(con.rbegin() - cur) = 1;

	return 0;


	int testCnt, N;
	std::cin >> testCnt;
	std::vector<int> cal;
	
	for (int i = 0, result = 0; i < testCnt; ++i, result = 0) {
		std::cin >> N;	// N의 최대값은 11
		
		for (int j = 0; j < N; ++j)	cal.push_back( 1 );
		/*int temp = cal.back();
		cal.pop_back();*/
		
		int temp = 0, cur = 1;
		while (*cal.begin() != 3) {
			temp = *(cal.end() - cur);
			
		}
		

		for (auto N : cal)
			std::cout << N << ", ";
		std::cout << std::endl;

		// printf("%d\n", result);
	}
}
