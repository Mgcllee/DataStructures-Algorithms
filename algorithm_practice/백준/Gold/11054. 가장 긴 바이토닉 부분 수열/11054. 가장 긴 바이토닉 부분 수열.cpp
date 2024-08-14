#include <iostream>
#include <vector>
#include <algorithm>

int N;
int *arr;
std::vector<std::pair<int, int>> order;
std::pair<int, int> Memo[1'005];

int Left_DP(int curr)
{
   if(curr - 1 < 0 || arr[curr] == 1)
      return 0;
   
   if(Memo[curr].first >= curr)
      return Memo[curr].first;

   int left_len = 0;
   for (int left = curr - 1; 0 <= left; --left)
   {
      if (arr[left] < arr[curr])
      {
         left_len = std::max(left_len, Left_DP(left) + 1);
      } 
   }
   
   Memo[curr].first = left_len;
   return left_len;
}

int Right_DP(int curr)
{
   if(curr + 1 >= N || arr[curr] == 1)
      return 0;

   if(Memo[curr].second >= curr)
      return Memo[curr].second;

   int right_len = 0;
   for(int right = curr + 1; right < N; ++right)
   {
      if(arr[curr] > arr[right])
      {
         right_len = std::max(right_len, Right_DP(right) + 1);
      }
   }

   Memo[curr].second = right_len;
   return right_len;
}

int L_DP[1'001];
int R_DP[1'001];
int DP()
{
   // Left side
   for(int curr = 1; curr <= N; ++curr)
   {
      L_DP[curr] = 1;
      
      for(int next = 1; next <= curr; ++next)
      {
         if(arr[next] < arr[curr] && L_DP[curr] < L_DP[next] + 1)
         {
            L_DP[curr] = L_DP[next] + 1;
         }
      }
   }

   // Right side
   for(int curr = N; curr >= 1; --curr)
   {
      R_DP[curr] = 1;

      for(int next = N; next >= curr; --next)
      {
         if(arr[next] < arr[curr] && R_DP[curr] < R_DP[next] + 1)
         {
            R_DP[curr] = R_DP[next] + 1;
         }
      }
   }

   int result = 0;
   for(int curr = 0; curr <= N; ++curr)
   {
      result = std::max(result, L_DP[curr] + R_DP[curr] - 1);
   }

   return result;
}

int main()
{
   std::cin.tie(0)->sync_with_stdio(false);
   std::cin >> N;
   arr = new int[1 + N];

   for (int i = 1; i <= N; ++i)
   {
      std::cin >> arr[i];
      order.push_back({arr[i], i});
   }
   std::fill(Memo, Memo + 1'001, std::make_pair(-1, -1));

   std::sort(order.begin(), order.end(), std::greater<std::pair<int, int>>());

   int MAX = 0;
   for (auto p : order)
   {
      // printf("[%d]: %d + %d + 1 = %d\n", arr[p.second], Left_DP(p.second), Right_DP(p.second), Left_DP(p.second) + Right_DP(p.second) + 1);
      // MAX = std::max(MAX, std::max(Left_DP(p.second), 0) + std::max(Right_DP(p.second), 0) + 1);
   }
   // printf("%d", MAX);

   std::cout << DP();

   return 0;
}
