#include <iostream>
#include <set>

struct WORD_ORDER {
	bool operator() (const std::string& lhs, const std::string& rhs) const
	{
		if (lhs.size() < rhs.size()) {
			return true;
		}
		else if (lhs.size() > rhs.size()) {
			return false;
		}

		for (int i = 0; i < lhs.size(); ++i) {
			if (lhs[i] == rhs[i]) continue;
			return lhs[i] < rhs[i];
		}
		return false;
	}
};

int main() {
	int N;
	std::cin >> N;
	std::set<std::string, WORD_ORDER> set;
	for (int i = 0; i < N; ++i) {
		std::string buf;
		std::cin >> buf;
		set.insert(buf);
	}
	
	for (auto s : set)
		std::cout << s << std::endl;
	return 0;
}