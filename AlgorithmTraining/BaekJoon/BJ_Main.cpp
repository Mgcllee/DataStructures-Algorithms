#include <iostream>
#include <unordered_map>

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N, cnt;
	std::cin >> N >> cnt;
	std::unordered_map<std::string, std::string> map;
	for (int i = 0; i < N; ++i) {
		std::string name, pass;
		std::cin >> name >> pass;
		map.insert(std::make_pair(name, pass));
	}

	for (int i = 0; i < cnt; ++i) {
		std::string buf;
		std::cin >> buf;
		std::cout << map[buf] << '\n';
	}

	return 0;
}