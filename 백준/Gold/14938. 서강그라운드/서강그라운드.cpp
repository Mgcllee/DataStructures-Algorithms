#include <iostream>
#include <vector>
#include <queue>

#define MAX m + 1

int n, m, r;
std::vector<std::pair<int, int>>* graph;
int* item_cnt;
std::vector<int> dist;

int temp_result;
bool* visited;
void BFS(int curr, int cost) // fail function
{
	if (m <= cost)
		return;

	temp_result += item_cnt[curr];

	for (auto next : graph[curr])
	{
		if (false == visited[next.first]
			&&
			(cost + next.second < m))
		{
			visited[next.first] = true;
			BFS(next.first, cost + next.second);
		}
	}
}

void Dijkstra(int start)
{
	std::priority_queue<std::pair<int, int>> pq;
	pq.push({ start, 0 });
	dist[start] = 0;

	while (false == pq.empty())
	{
		int curr = pq.top().first;
		int cost = -pq.top().second;
		pq.pop();

		for (auto next : graph[curr])
		{
			if (dist[next.first] > cost + next.second)
			{
				dist[next.first] = cost + next.second;
				pq.push({ next.first, -dist[next.first] });
			}
		}
	}
}

int main()
{
	std::cin.tie(0)->sync_with_stdio(false);
	std::cin >> n >> m >> r;
	graph = new std::vector<std::pair<int, int>>[n + 1];
	item_cnt = new int[n + 1];
	dist.assign(n + 1, MAX);

	for (int node = 1; node <= n; ++node)
	{
		std::cin >> item_cnt[node];
	}
	for (int edge = 0; edge < r; ++edge)
	{
		int start, end, cost;
		std::cin >> start >> end >> cost;
		graph[start].emplace_back(end, cost);
		graph[end].emplace_back(start, cost);
	}

	int result = 0;
	for (int node = 1; node <= n; ++node)
	{
		Dijkstra(node);
		int item_max = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (dist[i] != MAX)
				item_max += item_cnt[i];
		}
		result = std::max(item_max, result);
		dist.assign(n + 1, MAX);
	}

	printf("%d", result);
	return 0;
}
