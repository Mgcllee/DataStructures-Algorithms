#include <iostream>

long long int CCW(std::pair<int, int> p1, std::pair<int, int> p2, std::pair<int, int> p3)
{
	long long int Sum = ((long long int)p1.first * p2.second + (long long int)p2.first * p3.second + (long long int)p3.first * p1.second)
		- ((long long int)p1.second * p2.first + (long long int)p2.second * p3.first + (long long int)p3.second * p1.first);

	return Sum > 0 ? 1 : (Sum == 0 ? 0 : -1);
}

int main()
{
	std::cin.tie(NULL); 
	std::cout.tie(NULL); 
	std::ios_base::sync_with_stdio(false);

	std::pair<int, int> p1, p2, p3, p4;
	std::cin >> p1.first >> p1.second >> p2.first >> p2.second;
	std::cin >> p3.first >> p3.second >> p4.first >> p4.second;

	long long int result_01 = CCW(p1, p2, p3) * CCW(p1, p2, p4);
	long long int result_02 = CCW(p3, p4, p1) * CCW(p3, p4, p2);

	if (result_01 == 0 && result_02 == 0) {
		if (p1 > p2) std::swap(p1, p2);
		if (p3 > p4) std::swap(p3, p4);

		if (p3 <= p2 && p1 <= p4) printf("1");
		else printf("0");
	}
	else if(result_01 <= 0 && result_02 <= 0) printf("1");
	else printf("0");

	return 0;
}