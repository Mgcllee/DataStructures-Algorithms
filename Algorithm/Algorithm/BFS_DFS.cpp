#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <stack>
#include <algorithm>

std::queue<int> q;
bool *visited;
std::vector<int> *node;

void BFS(const std::vector<int> graph[], int start_node)
{
    q.push(start_node);
    visited[start_node] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        printf("%d ", current);

        // curr_node에 연결된 노드들을 차례로 방문
        for (int next : graph[current])
        {
            if (!visited[next])
            {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

void BFS(const std::vector<int> graph[])
{
    // 호출 전 사용할 queue/visited에 Start_node 정보를 넣은 후 호출할 것.
    // q.push(target_node);
    // visited[target_node] = true;
    if (q.empty())
    {
        return;
    }

    int current = q.front();
    q.pop();
    printf("%d ", current);

    for (int next : graph[current])
    {
        if (!visited[next])
        {
            q.push(next);
            visited[next] = true;
        }
    }

    BFS(graph);
}

void BFS(std::list<int> child_node)
{
    if (child_node.empty())
    {
        return;
    }

    int curr_node = child_node.front();
    child_node.pop_front();

    printf("%d ", curr_node);

    for (int next : node[curr_node])
    {
        if (!visited[next])
        {
            child_node.push_back(next);
            visited[next] = true;
        }
    }

    BFS(child_node);
}

void DFS(int curr_node)
{
    visited[curr_node] = true;
    printf("%d ", curr_node);

    for (int next_node : node[curr_node])
    {
        if (false == visited[next_node])
        {
            DFS(next_node);
        }
    }
}

void DFS_stack(int start_node)
{
    std::stack<int> stack;
    stack.push(start_node);
    visited[start_node] = true;
    printf("%d ", start_node);

    while (false == stack.empty())
    {
        int curr_node = stack.top();
        stack.pop();

        for (int next_node : node[curr_node])
        {
            if (false == visited[next_node])
            {
                printf("%d ", next_node);
                visited[next_node] = true;
                stack.push(curr_node);
                stack.push(next_node);
                break;
            }
        }
    }
}

int main()
{
    int N, M, V;
    std::cin >> N >> M >> V;

    visited = new bool[N + 1];
    node = new std::vector<int>[N + 1];

    std::fill(visited, visited + N + 1, false);
    for (int i = 0; i < M; ++i)
    {
        int start_node, end_node;
        std::cin >> start_node >> end_node;
        node[start_node].push_back(end_node);
        node[end_node].push_back(start_node);
    }

    for (int i = 1; i <= N; ++i)
    {
        std::sort(node[i].begin(), node[i].end());
    }

    DFS_stack(V);

    return 0;
}
