#include <iostream>
#include <vector>

struct Edge
{
	int start_node, end_node, cost;
};
bool new_bellman_ford(std::vector<Edge> edges, int node_cnt)
{
	std::vector<int> distance(node_cnt + 1, 2e9);
	distance[0] = 0;

	int start, end, time;
	for (int i = 1; i < node_cnt; ++i)
	{
		for (const auto& e : edges)
		{
			start = e.start_node;
			end = e.end_node;
			time = e.cost;

			if (distance[end] > distance[start] + time)
				distance[end] = distance[start] + time;
		}
	}

	for (const auto& e : edges)
	{
		start = e.start_node;
		end = e.end_node;
		time = e.cost;
		if (distance[end] > distance[start] + time)
			return true;
	}

	return false;
}

int main()
{
	std::cin.tie(NULL); 
	std::cout.tie(NULL); 
	std::ios_base::sync_with_stdio(false);

	int TC;
	std::cin >> TC;

	for (int i = 0; i < TC; ++i) 
	{
		std::vector<Edge> edges;
		int N, M, W;
		std::cin >> N >> M >> W;

		for (int i = 0; i < M; ++i)
		{
			int s, e, t;
			std::cin >> s >> e >> t;
			edges.push_back(Edge{ s, e, t });
			edges.push_back(Edge{ e, s, t });
		}

		for (int i = 0; i < W; ++i)
		{
			int s, e, t;
			std::cin >> s >> e >> t;
			edges.push_back(Edge{ s, e, -t });
		}

		if (new_bellman_ford(edges, N)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}