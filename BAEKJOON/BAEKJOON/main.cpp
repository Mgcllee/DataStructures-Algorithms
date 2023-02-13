#include <iostream>
#include <vector>

std::vector<unsigned int> sorted_vec;

void merge(std::vector<unsigned int>* vec, unsigned int left, unsigned int mid, unsigned int right) {
	int i = left, 
		j = mid + 1,
		k = left, 
		l = 0;

	while (i < mid && j <= right) {
		if ((*vec)[i] <= (*vec)[j]) {
			sorted_vec[k++] = (*vec)[i++];
		}
		else {
			sorted_vec[k++] = (*vec)[j++];
		}
	}

	if (i < mid) {
		for (l = j; l <= right; ++l) {
			sorted_vec[k++] = (*vec)[l];
		}
	}
	else {
		for (l = i; l <= mid; ++l) {
			sorted_vec[k++] = (*vec)[l];
		}
	}

	for (l = left; l <= right; ++l) {
		(*vec)[l] = sorted_vec[l];
	}
}

void merge_sort(std::vector<unsigned int>* vec, unsigned int left, unsigned int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		
		merge_sort(vec, left, mid);
		merge_sort(vec, mid + 1, right);
		merge(vec, left, mid, right);
	}
}

int main() {
	unsigned int count;
	unsigned int temp;
	std::cin >> count;
	std::vector<unsigned int> numbers;

	for (unsigned int i = 0; i < count; i++) {
		std::cin >> temp;
		numbers.push_back(temp);
	}
	sorted_vec.resize(numbers.size());

	merge_sort(&numbers, 0, numbers.size());

	for (unsigned int n : numbers) {
		printf("%d\n", n);
	}
}