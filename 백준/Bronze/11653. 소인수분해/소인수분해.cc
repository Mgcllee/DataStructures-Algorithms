#include <iostream>
using namespace std;

int main() {
	int N;
	std::cin >> N;
	for(int i = 2; i * i <= N; ++i)
	{
		while(N % i == 0)
		{
			printf("%d\n", i);
			N /= i;
		}
	}
	
	if(N > 1)
	{
		printf("%d", N);
	}
	return 0;
}