#include <iostream>
#include <vector>

void Combination(int depth, std::vector<int>& res, std::vector<int>& vec, int next)
{
	if (depth == res.size()) {
		for (int n : res)
			printf("%d ", n);
		printf("\n");
		return;
	}	

	for (int i = next; i < vec.size(); ++i) {
		res[depth] = vec[i];
		Combination(depth + 1, res, vec, i + 1);
	}
}

int main() {
	int N, M;
	std::cin >> N >> M;

	std::vector<int> vec;
	std::vector<int> res(M);
	for (int i = 1; i <= N; ++i) vec.push_back(i);

	Combination(0, res, vec, 0);

	return 0;
}