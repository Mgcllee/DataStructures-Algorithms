#include <iostream>

long long f_arr[50] = { 0, 1, };

long long fibonacci(int n) {
    if (n == 0 || n == 1)
    {
        return f_arr[n];
    }
    else if(f_arr[n] == 0)
    {
        return f_arr[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
    else
    {
        return f_arr[n];
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N;
    std::cin >> N;

    int buf;
    for (int i = 0; i < N; ++i)
    {
        std::cin >> buf;
        if (0 == buf)
        {
            printf("1 0\n");
        }
        else
        {
            printf("%lld %lld\n", fibonacci(buf - 1), fibonacci(buf));
        }
    }
    return 0;
}