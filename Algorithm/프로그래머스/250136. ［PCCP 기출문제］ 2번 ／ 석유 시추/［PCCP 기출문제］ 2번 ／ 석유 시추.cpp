#include <vector>
#include <queue>

using namespace std;

int N, M;
int left_index, right_index;
int dx[4]{0, 0, -1, 1};
int dy[4]{-1, 1, 0, 0};
vector<vector<bool>> visited;

int BFS(vector<vector<int>>& land, pair<int, int> start)
{
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    
    int cnt = 1;
    left_index = start.second;
    right_index = start.second;
    
    while(q.empty() == false)
    {
        pair<int, int> curr = q.front();
        q.pop();
        visited[curr.first][curr.second] = true;
        
        for(int dir = 0; dir < 4; ++dir)
        {
            int new_row = curr.first + dy[dir];
            int new_col = curr.second + dx[dir];
            
            if(new_row < 0 || new_row >= N || new_col < 0 || new_col >= M)
                continue;
            if(0 == land[new_row][new_col])
                continue;
            if(true == visited[new_row][new_col])
                continue;
            
            left_index = left_index > new_col ? new_col : left_index;
            right_index = right_index < new_col ? new_col : right_index;
            
            cnt += 1;
            
            visited[new_row][new_col] = true;
            q.push(make_pair(new_row, new_col));
        }
    }
    
    return cnt;
}

int solution(vector<vector<int>> land) {
    N = land.size();
    M = land[0].size();
    
    visited.assign(N, std::vector<bool>(M, false));
    
    vector<int> sum(M, 0);
    
    for(int row = 0; row < N; ++row)
    {
        for(int col = 0; col < M; ++col)
        {   
            if(1 == land[row][col] && false == visited[row][col])
            {
                int amount = BFS(land, make_pair(row, col));
                for(;left_index <= right_index; ++left_index)
                {
                    sum[left_index] += amount;
                }
            }
        }
    }
    
    int max = 0;
    for(int col : sum)
        max = col > max ? col : max;  
    return max;
}
