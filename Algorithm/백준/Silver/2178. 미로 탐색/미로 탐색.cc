#include <iostream>
#include <queue>

int row, col;
bool** board;
bool** visited;
int** dist;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0}; 

void BFS(int start_row, int start_col)
{
    visited[start_row][start_col] = true;
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(start_row, start_col));
    dist[start_row][start_col] = 1;

    while(false == q.empty())
    {
        int curr_row = q.front().first;
        int curr_col = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; ++dir)
            {
                int new_row = curr_row + dy[dir];
                int new_col = curr_col + dx[dir];

                if (new_col < 0 || new_col >= col || new_row < 0 || new_row >= row)
                    continue;
                if (false == visited[new_row][new_col] && board[new_row][new_col])
                {
                    visited[new_row][new_col] = true;
                    q.push(std::make_pair(new_row, new_col));
                    dist[new_row][new_col] = dist[curr_row][curr_col] + 1;
                }
            }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> row >> col;
    board = new bool*[row];
    visited = new bool*[row];
    dist = new int*[row];

    for(int i = 0; i < row; ++i)
    {
        board[i] = new bool[col];
        visited[i] = new bool[col];
        dist[i] = new int[col];
        std::fill(visited[i], visited[i] + col, 0);
        std::fill(dist[i], dist[i] + col, 0);

        std::string buf;
        std::cin >> buf;
        for(int j = 0; j < col; ++j)
        {
            if(buf[j] == '1') board[i][j] = true;
            else board[i][j] = false;
        }
    }

    BFS(0, 0);

    printf("%d", dist[row - 1][col - 1]);
    return 0;
}