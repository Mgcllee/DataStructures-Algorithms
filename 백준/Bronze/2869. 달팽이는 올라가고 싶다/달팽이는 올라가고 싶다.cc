#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int A, B, V, curr = 0, day = 0;
	std::cin >> A >> B >> V;
	if (V < A)
		printf("1");
	else if ((V - A) % (A - B) == 0)
		printf("%d", (V - A) / (A - B) + 1);
	else
		printf("%d", (V - A) / (A - B) + 2);
	return 0;
}