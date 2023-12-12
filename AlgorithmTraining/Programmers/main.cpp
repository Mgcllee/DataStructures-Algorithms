#include <iostream>
#include <vector>
#include <string>
#include <map>

struct gOrder {
	bool operator() (const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const
	{
		return lhs.first > rhs.first;
	}
};

int main()
{
	std::vector<std::string> genres{ "classic", "pop", "classic", "classic", "pop" };
	std::vector<int> plays{ 500, 600, 150, 800, 2500 };

	std::multimap<std::pair<int, int>, std::pair<std::string, int>, gOrder> map;
	for (int i = 0; i < genres.size(); ++i) {
		map.insert({ {plays[i], i}, {genres[i], i} });
	}

	std::vector<int> result;
	std::map<std::pair<int, int>, std::pair<std::string, int>, gOrder> tempMap(map.begin(), map.end());
	for (auto& p : map) {
		std::cout << p.first.first << " - " << p.second.first << " : " << p.first.second << std::endl;

		for (auto np : map) {
			if ((p.second.first == np.second.first) && (p.second.second)) {
				result.push_back(p.first.second);
				p.second.second = -1;
				break;
			}
		}
	}

	for (auto p : result)
		printf("%d ", p);
}
