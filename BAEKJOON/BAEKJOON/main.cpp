#pragma once

#include "main.h"

linkedList ll;

int main() {
	int input_count = 0;
	std::cin >> input_count;

	// what's difference null and nullptr?
	// -> null is 0(number), nullptr is empty pointer
	ll.head = nullptr;

	for (int i = 0; i < input_count; ++i) {
		int inputNumber = -1;
		std::cin >> inputNumber;
		ll.insert(inputNumber);
	}

	ll.printList();
}