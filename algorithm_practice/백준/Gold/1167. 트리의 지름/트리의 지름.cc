#include <iostream>
#include <vector>
#include <queue>

int node_cnt = 0;
std::vector<std::pair<int, int>>* graph;
int* dist;
int max_cost = 0, max_node = 0;

void Dijstra(int start_node)
{
	std::priority_queue<std::pair<int, int>
		, std::vector<std::pair<int, int>>
		, std::greater<std::pair<int, int>>> pq;
	pq.push(std::make_pair(0, start_node));
	std::fill(dist, dist + 1 + node_cnt, 1e9);

	dist[start_node] = 0;

	max_cost = 0;
	while (false == pq.empty())
	{
		int curr_cost = pq.top().first;
		int curr_node = pq.top().second;
		pq.pop();

		if (dist[curr_node] < curr_cost)
			continue;

		for (int i = 0; i < graph[curr_node].size(); ++i)
		{
			int new_cost = curr_cost + graph[curr_node][i].second;

			if (new_cost < dist[graph[curr_node][i].first])
			{
				dist[graph[curr_node][i].first] = new_cost;
				pq.push(std::make_pair(new_cost, graph[curr_node][i].first));
				
				if (new_cost > max_cost) 
				{
					max_cost = new_cost;
					max_node = graph[curr_node][i].first;
				}
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	std::cin >> node_cnt;
	graph = new std::vector<std::pair<int, int>>[1 + node_cnt];
	dist = new int[1 + node_cnt];

	for (int i = 0; i < node_cnt; ++i)
	{
		int curr_node = 0;
		std::cin >> curr_node;
		
		while (true)
		{
			int next_node = 0, cost = 0;
			std::cin >> next_node;
			if (-1 == next_node) break;
			std::cin >> cost;
			graph[curr_node].push_back(std::make_pair(next_node, cost));
		}
	}

	Dijstra(1);
	Dijstra(max_node);

	printf("%d", max_cost);
	return 0;
}