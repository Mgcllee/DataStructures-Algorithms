#include <iostream>
#include <vector>
#include <queue>

int N, M, X;
std::vector<std::vector<std::pair<int, int>>> adj_list;
std::vector<int> dist;


int get_cost(int start_node, int end_node)
{
	dist.assign(M + 1, -1);

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
	pq.push({ 0, start_node });

	while (false == pq.empty())
	{
		int cur_dist = pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if (dist[cur_node] != -1) continue;

		dist[cur_node] = cur_dist;

		for (auto& adj_node : adj_list[cur_node])
		{
			if (dist[adj_node.first] != -1) continue;

			pq.push({ cur_dist + adj_node.second, adj_node.first });
		}
	}

	return dist[end_node];
}

int main() 
{
	std::cin >> N >> M >> X;
	adj_list.assign(M + 1, std::vector<std::pair<int, int>>());
	
	for (int i = 0; i < M; ++i) 
	{
		int start_node, end_node, cost;
		std::cin >> start_node >> end_node >> cost;
		adj_list[start_node].push_back({ end_node, cost });
	}

	int max_cost = 0;
	for (int i = 1; i <= N; ++i) 
	{
		int new_cost = get_cost(X, i) + get_cost(i, X);
		max_cost = new_cost > max_cost ? new_cost : max_cost;
	}

	printf("%d", max_cost);

	return 0;
}