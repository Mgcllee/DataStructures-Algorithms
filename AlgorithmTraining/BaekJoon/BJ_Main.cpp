#include <iostream>

class NODE {
	NODE* next;
	int val;

public:
	NODE(int inV) : val(inV), next(nullptr) { }
	
	int get() { return val; }
	int set(int v) { val = v; }
	void set_next(NODE* nn) { next = nn; }
	NODE* get_next() { return next; }
};

int main() {
	int N = 0;
	std::cin >> N;
	NODE* top = nullptr;
	int size = 0;

	for (int i = 0; i < N; ++i) {
		std::string order;
		std::cin >> order;
		if (order == "push") {
			int newNum;
			std::cin >> newNum;
			NODE* newNode = new NODE(newNum);
			
			if (top == nullptr) {
				top = newNode;
			}
			else {
				newNode->set_next(top);
				top = newNode;
			}
			size += 1;
		}
		else if (order == "pop") {
			if (top == nullptr) printf("-1\n");
			else {
				printf("%d\n", top->get());
				NODE* delNode = top;
				top = top->get_next();
				delete delNode;
				size -= 1;
			}
		}
		else if (order == "size") {
			if (top == nullptr) printf("0\n");
			else printf("%d\n", size);
		}
		else if (order == "empty") {
			if (top == nullptr) printf("1\n");
			else printf("0\n");
		}
		else if (order == "top") {
			if (top == nullptr) printf("-1\n");
			else printf("%d\n", top->get());
		}
	}
	return 0;
}