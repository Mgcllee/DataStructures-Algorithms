#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int cnt_node, cnt_edge, cnt_goal;
int start, g, h;
int* dist;
std::vector<std::pair<int, int>>* graph;
std::vector<int> goals;

void Dijkstra(int start_node)
{
	std::priority_queue<std::pair<int, int>> pq;
	pq.emplace(start_node, 0);
	dist[start_node] = 0;

	while (false == pq.empty())
	{
		int curr_node = pq.top().first;
		int curr_cost = -pq.top().second;
		pq.pop();

		for (auto next : graph[curr_node])
		{
			if (dist[next.first] > curr_cost + next.second)
			{
				dist[next.first] = curr_cost + next.second;
				pq.push({ next.first, -dist[next.first] });
			}
		}
	}
}

int main()
{
	int T;
	std::cin.tie(0)->sync_with_stdio(false);
	
	std::cin >> T;
	
	for (int tc = 0; tc < T; ++tc)
	{
		std::cin >> cnt_node >> cnt_edge >> cnt_goal;
		std::cin >> start >> g >> h;

		graph = new std::vector<std::pair<int, int>>[cnt_node + 1];
		dist = new int[cnt_node + 1];
		std::fill(dist, dist + cnt_node + 1, 2e9);

		for (int edge = 1; edge <= cnt_edge; ++edge)
		{
			int start_node, end_node, cost;
			std::cin >> start_node >> end_node >> cost;
			graph[start_node].push_back({ end_node, cost });
			graph[end_node].push_back({ start_node, cost });
		}

		goals.assign(cnt_goal, 0);
		for (int goal_node = 0; goal_node < cnt_goal; ++goal_node)
		{
			std::cin >> goals[goal_node];
		}

		Dijkstra(start);
		
		int must_cost = dist[g] > dist[h] ? dist[g] : dist[h];
		int mid_start = dist[g] > dist[h] ? g : h;

		int* ori_dist = new int[cnt_node + 1];
		for (int i = 1; i <= cnt_node; ++i)
			ori_dist[i] = dist[i];

		std::fill(dist, dist + cnt_node + 1, 2e9);
		Dijkstra(mid_start);

		std::sort(goals.begin(), goals.end());
		for (int goal : goals)
		{
			if (must_cost + dist[goal] <= ori_dist[goal])
			{
				printf("%d ", goal);
			}
		}
		printf("\n");
		delete[] graph, dist;
	}
	
	return 0;
}
