#include <iostream>

int main() 
{
	int n;
	std::cin >> n;
    printf("%d", (n/5 + n/25 + n/125));
	return 0;
}