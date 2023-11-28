#include <iostream>
#include <vector>

void Permutation(bool* visited, std::vector<short>& vec, std::vector<short>& res, short cnt)
{
	if (cnt == static_cast<short>(res.size())) {
		for (short n : res) {
			printf("%d ", n);
		}
		printf("\n");
		return;
	}

	for (short i = 0; i < static_cast<short>(vec.size()); ++i) {
		if (visited[i] == true) continue;

		visited[i] = true;
		res[cnt] = vec[i];
		Permutation(visited, vec, res, cnt + 1);
		visited[i] = false;
	}
}

int main() {
	int N, M;
	std::cin >> N >> M;

	std::vector<short> vec;	// 1부터 N까지의 숫자 정보
	std::vector<short> res(M);	// 순열로 구한 순열 결과

	// 숫자 정보 입력
	for (short i = 1; i <= N; ++i) {
		vec.push_back(i);
	}

	// 방문 기록 남기기
	bool* visited = new bool[N];
	for (int i = 0; i < N; ++i) visited[i] = false;

	Permutation(visited, vec, res, 0);

	return 0;
}