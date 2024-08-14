#include <iostream>
#include <vector>
#include <map>

struct gOrder {
	bool operator() (const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const
	{
		return lhs.first > rhs.first;
	}
};

struct oriOrder {
	bool operator() (const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const
	{
		if (lhs.first == rhs.first) {
			return lhs.second < rhs.second;
		}
		return lhs.first > rhs.first;
	}
};

int main()
{
	std::vector<std::string> genres{ "a", "b", "b", "c", "c" };
	std::vector<int> plays{ 5, 5, 40, 5, 5 };

	std::multimap<std::pair<int, int>, std::pair<std::string, int>, gOrder> map;
	for (int i = 0; i < genres.size(); ++i) {
		map.insert({ {plays[i], i}, {genres[i], plays[i]} });
	}

	std::vector<std::string> sorted;
	{
		std::map<std::string, int> sum;
		for (auto p : map) {
			if (false == sum.insert(p.second).second) {
				sum.find(p.second.first)->second += p.second.second;
			}
		}

		std::map<int, std::string, std::greater<int>> sortedString;
		for (auto p : sum) {
			sortedString.insert({ p.second, p.first });
		}



		for (auto p : sortedString) {
			sorted.push_back(p.second);
		}

	}

	std::vector<int> result;
	for (auto p : sorted) {
		int cnt = 0;
		std::map<std::pair<int, int>, std::string, oriOrder> temp;
		for (auto mp : map) {
			if (p == mp.second.first) {
				temp.insert({ {mp.first.first, mp.first.second }, mp.second.first });
			}
		}

		for (auto p : temp) {
			result.push_back(p.first.second);
			if (++cnt == 2) break;
		}
	}

	for (int i : result)
		std::cout << i << " ";
}
