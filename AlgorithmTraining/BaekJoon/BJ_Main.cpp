#include <iostream>
#include <vector>
#include <queue>


int dijkstra(std::vector<std::pair<int, int>> edge[], int* dis, int start, int end) {
	dis[start] = 0;
	std::priority_queue<std::pair<int, int>> pq;
	pq.push(std::make_pair(start, 0));

	int cnt = 0;

	while (!pq.empty()) {
		int current = pq.top().first;
		int dist = -pq.top().second;
		pq.pop();

		// 최단거리가 아닐 경우
		if (dis[current] < dist) continue;

		for (int i = 0; i < edge[current].size(); ++i) {
			int next = edge[current][i].first;
			int nextDist = dist + edge[current][i].second;

			if (nextDist < dis[next]) {
				dis[next] = nextDist;
				pq.push(std::make_pair(next, -nextDist));
				if (next == end) {
					printf("%d -> %d\n", current, next);
;					cnt += 1;
				}
			}
		}
	}

	return cnt;
}

int main() 
{
	int M, N;
	std::cin >> M >> N;
	int** arr = new int* [M];
	std::vector<std::pair<int, int>>* node = new std::vector<std::pair<int, int>>[M * N + 1];
	// std::vector<std::pair<int, int>> node[100];

	for (int i = 0; i < M; ++i) {
		arr[i] = new int[N];
		for (int j = 0; j < N; ++j) std::cin >> arr[i][j];
	} 

	for (int i = 0, num = 1; i < M; ++i) {
		for (int j = 0; j < N && num <= N * M; ++j, ++num) {
			// 좌, 상 노드
			if ((j != 0) && (arr[i][j] > arr[i][j - 1])) node[num].push_back(std::make_pair(num - 1, std::abs(arr[i][j] - arr[i][j - 1])));
			if ((i != 0) && (arr[i][j] > arr[i - 1][j])) node[num].push_back(std::make_pair(num - N, std::abs(arr[i][j] - arr[i - 1][j])));
			// 우, 하 노드
			if ((j != N - 1) && (arr[i][j] > arr[i][j + 1])) node[num].push_back(std::make_pair(num + 1, std::abs(arr[i][j] - arr[i][j + 1])));
			if ((i != M - 1) && (arr[i][j] > arr[i + 1][j])) node[num].push_back(std::make_pair(num + N, std::abs(arr[i][j] - arr[i + 1][j])));
		}
	}

	int* dis = new int[N * M + 1];
	for (int i = 0; i < N * M + 1; ++i)
		dis[i] = 10000 + 1;

	std::cout << dijkstra(node, dis, 1, N * M);
	return 0;


	int min = INT_MAX, cnt = 0;
	for (int i = 0; i < N * M; ++i) if (min > dis[i]) min = dis[i];
	for (int i = 0; i < N * M; ++i) if (min == dis[i]) cnt += 1;
	
	for (int i = 0, num = 1; i < M; ++i) {
		for (int j = 0; j < N && num <= N * M; ++j, ++num) {
			printf("%d,\t", dis[num]);
		}
		printf("\n");
	}

	printf("%d", cnt);
	return 0;
}