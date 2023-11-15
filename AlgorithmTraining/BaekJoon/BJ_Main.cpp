#include <iostream>
#include <vector>

std::vector<bool> visited; // bool visited[9];
std::vector<std::vector<int>> adj;
int M, N, cnt = 0;

void dfs(int x)
{

	visited[x] = true;
	// std::cout << x << " "; // 경로 추적 표시
	for (int i = 0; i < adj[x].size(); i++) // 인접한 노드 사이즈만큼 탐색
	{
		int y = adj[x][i];

		if (x == M - 1 && y == N - 1) {
			++cnt;
			return;
		}

		if (!visited[y]) // 방문하지 않았으면 즉 visited가 False일 때 not을 해주면 True가 되므로 아래 dfs 실행
			dfs(y); // 재귀적으로 방문
	}
}

int main() 
{
	std::cin >> M >> N;
	int** arr = new int* [M];
	adj.assign(N * M + 1, std::vector<int>());

	for (int i = 0; i < M; ++i) {
		arr[i] = new int[N];
		for (int j = 0; j < N; ++j) std::cin >> arr[i][j];
	}

	for (int i = 0, num = 1; i < M; ++i) {
		for (int j = 0; j < N && num <= N * M; ++j, ++num) {
			if (0 < j && (arr[i][j - 1] < arr[i][j])) adj[num].push_back(num - 1);		// 좌측이동 가능성 확인
			if (0 < i && (arr[i - 1][j] < arr[i][j])) adj[num].push_back(num - N);		// 상향이동 가능성 확인
			if (j < N - 1 && (arr[i][j + 1] < arr[i][j])) adj[num].push_back(num + 1);	// 우측이동 가능성 확인
			if (i < M - 1 && (arr[i + 1][j] < arr[i][j])) adj[num].push_back(num + N);	// 하향이동 가능성 확인
		}
	}

	visited.assign(adj.size(), false);
	dfs(1);

	std::cout << cnt;

	return 0;
}