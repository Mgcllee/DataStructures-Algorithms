#include <iostream>

int N;
int* build;

struct POINT
{
   long long x, y;
};

int CCW(POINT A, POINT B, POINT C)
{
   long long ret = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);

   if (ret > 0)
      return 1;
   else if (ret < 0)
      return -1;
   else
      return 0;
}

int main()
{
   std::cin.tie(0)->sync_with_stdio(false);
   std::cin >> N;
   build = new int[N + 1];

   for (int i = 0; i < N; ++i)
   {
      std::cin >> build[i];
   }

   int MAX = 0;
   for (int curr = 0; curr < N; ++curr)
   {
      int left_max = 0, right_max = 0;
      
      bool block = false, same = false;
      // forward
      for (int end = curr + 1; end < N; ++end)
      {
         block = false;
         same = false;

         for (int mid = curr + 1; mid <= end; ++mid)
         {
            int ccw = CCW(POINT{ curr, build[curr] }, POINT{ end, build[end] }, POINT{ mid, build[mid] });

            if (1 == ccw)
            {
               block = true;
               break;
            }
            else if (ccw == 0)
            {
               if (false == same)
                  same = true;
               else
               {
                  block = true;
                  break;
               }
            }
         }

         if (false == block)
         {
            ++right_max;
         }
      }

      // backward
      for (int end = curr - 1; end >= 0; --end)
      {
         block = false;
         same = false;

         for (int mid = curr - 1; mid >= end; --mid)
         {
            int ccw = CCW(POINT{ curr, build[curr] }, POINT{ end, build[end] }, POINT{ mid, build[mid] });
            if (-1 == ccw)
            {
               block = true;
               break;
            }
            else if (ccw == 0)
            {
               if (false == same)
                  same = true;
               else
               {
                  block = true;
                  break;
               }
            }
         }

         if (false == block)
         {
            ++left_max;
         }
      }

      // printf("[%d] : %d + %d = %d\n", curr, left_max, right_max, left_max + right_max);

      MAX = left_max + right_max > MAX ? left_max + right_max : MAX;
   }
   printf("%d", MAX);


   return 0;
}
