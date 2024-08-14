/*
N-Queen
https://www.acmicpc.net/problem/9663
*/

#include <stdio.h>

int n, ans;
int col[15], updia[29], downdia[29];

void NQueen(int x)
{
    for (int i = 0; i < n; i++)
    {
        int up = x + i;
        int down = n + x - i - 1;

        if (!col[i] && !updia[up] && !downdia[down])
        {
            if (x == n - 1)
            {
                ans++;
                continue;
            }

            col[i] = updia[up] = downdia[down] = 1;
            NQueen(x + 1);
            col[i] = updia[up] = downdia[down] = 0;
        }
    }

    return;
}

int main()
{
    scanf("%d", &n);

    NQueen(0);

    printf("%d", ans);

    return 0;
}