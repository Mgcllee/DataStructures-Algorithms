#include <iostream>
#include <vector>

int main() {
	int heap_size, input_num, cur_index = 0;
	std::vector<int> heap;
	heap.assign(3, 0);
	
	std::cin >> heap_size;
	for (int i = 0; i < heap_size; ++i) {
		std::cin >> input_num;
		
		if (heap.size() == 0) {
			heap[cur_index] = input_num;
		}
		else if(heap[0] < input_num) {
			
			if (heap[cur_index] < input_num) {
				std::cout << "heap[cur_index]: " << heap[cur_index] << ", input: " << input_num << std::endl;
				heap[cur_index] = input_num;
			}
			else if (heap[cur_index] > input_num) {
				std::cout << "heap[cur_index]: " << heap[cur_index] << ", input: " << input_num << std::endl;

				int temp = heap[cur_index];
				heap[cur_index] = input_num;
				input_num = temp;

				heap[cur_index] = input_num;
			}
		}
		++cur_index;
	}

	for (int& n : heap)
		std::cout << n << std::endl;
}