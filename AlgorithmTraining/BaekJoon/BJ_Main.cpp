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
	1. ������ ������ ����Ѵ�. (1 + 2 != 2 + 1)
	2. ������ ������ 1, 2, 3�� �����Ѵ�.

	i)  ���� 1�� ��
	ii) 2�� �ϳ��� ����(����)�� ��
	iii) 
	*/

	// 1) �迭�� ����� �������
	for (int i = 0; i < testCnt; ++i) {
		int result = 1;
		std::cin >> N;
		std::vector<int> vec;
		vec.resize(N, 1);	//ũ�� N��ŭ 1�� ä��

		while (vec.size() >= 2) {
			for (auto N : vec)
				std::cout << N << ", ";
			std::cout << std::endl;

			int last = *(vec.end() - 1);
			// �ߺ����� ���ο� ���� ����
			if (3 > *(vec.end() - 1) + last) {
				vec.pop_back();
				*(vec.end() - 1) += last;
				result += vec.size();
			}
			// �ߺ��� ���� ����
			else {
				// ����O, ����X(������ (1, 2)�� (2, 1)�� �ߺ����� ó��)
				
			}
		}
		
		printf("result: %d\n", result);
	}
}
