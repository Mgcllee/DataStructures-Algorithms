#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	unordered_map<int, string> poke_num;
	unordered_map<string, int> poke_name;

	int N, M;
	std::cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string name;
		cin >> name;
		poke_num.insert({ i + 1, name });
		poke_name.insert({ name, i + 1 });
	}

	for (int i = 0; i < M; ++i)
	{
		string buf;
		cin >> buf;
		if (isdigit(buf[0]))
		{
			cout << poke_num.at(stoi(buf)) << "\n";
		}
		else
		{
			cout << poke_name.at(buf) << "\n";
		}
	}

	return 0;
}