#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

bool* visited;
std::vector<int>* edge;

void DFS(int curr_node)
{
	visited[curr_node] = true;
	printf("%d ", curr_node);

	for (int n : edge[curr_node])
	{
		if (false == visited[n])
			DFS(n);
	}
}

void BFS(int curr_node)
{
	std::queue<int> q;
	q.push(curr_node);
	visited[curr_node] = true;

	while (false == q.empty())
	{
		int curr_node = q.front();
		q.pop();

		printf("%d ", curr_node);

		for (int n : edge[curr_node])
		{
			if (false == visited[n])
			{
				q.push(n);
				visited[n] = true;
			}
		}
	}
}

int main()
{
	int N, M, V;
	std::cin >> N >> M >> V;
	visited = new bool[N + 1];
	edge = new std::vector<int>[N + 1];

	for (int i = 0; i < M; ++i)
	{
		int start, end;
		std::cin >> start >> end;
		edge[start].push_back(end);
		edge[end].push_back(start);
	}

	for (int i = 1; i <= N; i++) 
	{
		std::sort(edge[i].begin(), edge[i].end());
	}
	std::fill(visited, visited + N + 1, false);
	DFS(V);
	printf("\n");
	std::fill(visited, visited + N + 1, false);
	BFS(V);
	return 0;
}