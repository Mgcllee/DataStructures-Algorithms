#include <iostream>
#include <vector>

void Permutation(bool* visited, std::vector<int>& vec, std::vector<int>& res, int cnt) {
	if (cnt == vec.size()) {
		for (auto a : res) {
			std::cout << a << " ";
		}
		std::cout << std::endl;
		return;
	}

	for (int i = 0; i < vec.size(); i++) {
		if (visited[i] == 1)	continue;

		visited[i] = 1;
		res[cnt] = vec[i];
		Permutation(visited, vec, res, cnt + 1);
		visited[i] = 0;
	}
}

int main() 
{
	std::vector<int> vec = { 1, 1, 2, 2, 3 };
	std::vector<int> res(vec.size());
	bool* visit = new bool[vec.size()];
	Permutation(visit, vec, res, 0);

	return 0;


	int testCnt, N;
	std::cin >> testCnt;

	/*
	1. 덧셈의 순서를 고려한다. (1 + 2 != 2 + 1)
	2. 숫자의 조합은 1, 2, 3만 존재한다.

	i)  전부 1일 때
	ii) 2가 하나씩 껴있(증가)할 때
	iii) 
	*/

	// 1) 배열을 사용한 구현방법
	for (int i = 0; i < testCnt; ++i) {
		int result = 1;
		std::cin >> N;
		std::vector<int> vec;
		vec.resize(N, 1);	//크기 N만큼 1로 채움

		while (vec.size() >= 2) {
			for (auto N : vec)
				std::cout << N << ", ";
			std::cout << std::endl;

			int last = *(vec.end() - 1);
			// 중복없는 새로운 숫자 등장
			if (3 > *(vec.end() - 1) + last) {
				vec.pop_back();
				*(vec.end() - 1) += last;
				result += vec.size();
			}
			// 중복된 숫자 등장
			else {
				// 순열O, 조합X(조합은 (1, 2)와 (2, 1)을 중복으로 처리)
				
			}
		}
		
		printf("result: %d\n", result);
	}
}
