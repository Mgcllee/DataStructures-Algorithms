#include <iostream>
#include <vector>
#include <queue>
#include <stack>

long long* dist; // Dijkstra 최단거리 테이블
std::vector<std::pair<int, int>>* path;
int* result;

void Dijkstra(int start_node)
{
	std::priority_queue<std::pair<int, int>
		, std::vector<std::pair<int, int>>
		, std::greater<std::pair<int, int>>> pq;
	pq.push(std::make_pair(0, start_node));

	while (false == pq.empty())
	{
		int curr_node = pq.top().second;
		int curr_cost = -pq.top().first;
		pq.pop();

		if (dist[curr_node] < curr_cost)
			continue;

		for (int i = 0; i < path[curr_node].size(); ++i)
		{
			int dest = path[curr_node][i].first;
			int cost = path[curr_node][i].second + curr_cost;

			if (dist[dest] > cost)
			{
				dist[dest] = cost;
				pq.push(std::make_pair(-cost, dest));
				result[dest] = curr_node;
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int N, M, start_node, end_node;
	std::cin >> N >> M;
	path = new std::vector<std::pair<int, int>>[N + 1];
	dist = new long long[N + 1];
	result = new int[N + 1];
	
	std::fill(dist, dist + N + 1, 1e9);

	for (int i = 0; i < M; ++i) 
	{
		int start, end, cost;
		std::cin >> start >> end >> cost;
		path[start].push_back(std::make_pair(end, cost));
	}

	std::cin >> start_node >> end_node;

	dist[start_node] = 0;
	Dijkstra(start_node);

	std::cout << dist[end_node] << "\n";

	std::stack<int> pathStack;
	pathStack.push(end_node);
	
	for (int curr = end_node; curr != start_node;)
	{
		pathStack.push(result[curr]);
		curr = result[curr];
	}

	std::cout << pathStack.size() << "\n";
	while (false == pathStack.empty())
	{
		std::cout << pathStack.top() << " ";
		pathStack.pop();
	}

	return 0;
}