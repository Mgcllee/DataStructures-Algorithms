#include <iostream>
#include <queue>
using namespace std;

struct node{
	int val;
	node(int a) {
		val = a;
	}
	bool operator< (const node& rhs) const{
		return val > rhs.val;
	}

};

int main() {
	int N;
	std::priority_queue<node> pq;
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> N;
	
	for(int i = 0, temp; i < N; ++i)
	{
		std::cin >> temp;
		if(temp != 0)
		{
			pq.push(temp);
		}
		else
		{
			if(pq.empty())
				printf("0\n");
			else
			{
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
	}
	return 0;
}