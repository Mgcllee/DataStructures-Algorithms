#include <iostream>
#include <vector>
#include <thread>

using namespace std;

class USER
{
public:
	USER(int in_ticket) : ticket(in_ticket) { }
	~USER() { }

	void process() { printf("ticket: %d\n", ticket); }

private:
	int ticket;

};

int main()
{
	vector<thread> worker_threads;
	for (int i = 7; i < 10; ++i)
	{
		worker_threads.emplace_back(&USER::process, USER(i));
	}
	
	for (auto& th : worker_threads)
	{
		th.join();
	}

	return 0;
}