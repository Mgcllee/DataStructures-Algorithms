#include <iostream>

int main()
{
	int cnt, time;
	std::cin >> cnt >> time;
	int* arr = new int[cnt];
	int* sum = new int[time];

	for (int i = 0; i < cnt; ++i) {
		std::cin >> arr[i];
	}
	for (int i = 0, start, end; i < time; ++i) {
		std::cin >> start >> end;

		int sum = 0;
		for (int j = start - 1; j <= end - 1; ++j) {
			sum += arr[j];
		}
		std::cout << sum << std::endl;
	}
	return 0;
}