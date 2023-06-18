#include <iostream>
#include <set>

int main() {
	std::set<int> numbers;

	int numberCount = NULL;
	scanf_s("%d", &numberCount);
	for (int i = 0; i < numberCount; ++i) {
		int inputNumber;
		scanf_s("%d", &inputNumber);
		numbers.insert(inputNumber);
	}
	
	for (int n : numbers) {
		printf("%d\n", n);
	}
}