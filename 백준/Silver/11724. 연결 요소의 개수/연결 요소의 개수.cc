#include <iostream>
#include <vector>
#include <cstring>

std::vector<int> vec[1001];
bool visited[1001];

void DFS(int X)
{
	visited[X] = true;
	
	for (int i = 0; i < vec[X].size(); i++)
	{
		int y = vec[X][i];
		if (!visited[y]) 
			DFS(y);
	}
}

int main() 
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int N, M, cnt = 0;
	std::cin >> N >> M;

	// vec = new std::vector<int>[N + 1];
	// visited = new bool[N + 1];
	memset(visited, false, 1001);

	for (int i = 0; i < M; ++i) {
		int start_node, end_node;
		std::cin >> start_node >> end_node;
		vec[start_node].push_back(end_node);
		vec[end_node].push_back(start_node);
	}

	for (int i = 1; i <= N; ++i)
	{
		if (false == visited[i])
		{
			cnt++;
			DFS(i);
		}
	}

	printf("%d", cnt);
	return 0;
}