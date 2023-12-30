//#include <iostream>
//#include <vector>
//#include <set>
//
//struct GRADE {
//	bool operator() (const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const
//	{
//		if ((lhs.first > rhs.first) && (lhs.second > rhs.second)) return false;
//		else return true;
//	}
//};
//
//int main() {
//	int N;
//	std::cin >> N;
//	std::vector<int> vec;
//
//	std::multiset<std::pair<int, int>, GRADE> set;
//	for (int i = 0, a, b; i < N; ++i) {
//		std::cin >> a >> b;
//		set.insert(std::make_pair(a, b));
//	}
//
//	int curr = 0;
//	std::pair<int, int> prev = { -1, -1 };
//	for (auto p : set) {
//		if (prev.first == -1) {
//			prev = p;
//			vec.push_back(1);
//		}
//		else {
//			if (prev.first < p.first && prev.second < p.second) {
//				prev = p;
//				curr += 1;
//				vec.push_back(1);
//			}
//			else vec[curr] += 1;
//		}
//	}
//
//	std::multiset<int> s_set{ vec.begin(), vec.end() };
//	int cnt[3] = { 0, 0, 0 }, i = 0;
//	for (int n : s_set) {
//		cnt[i] += n;
//		if (i + 1 < 3) ++i;
//		else i = 0;
//	}
//
//	if (vec.size() < 3) printf("-1");
//	else printf("%d", cnt[0] - cnt[2]);
//	
//	return 0;
//}



#include <iostream>
#include <list>

bool check_pair(std::string buf) {
	std::string check_str;
	bool answer = true;
	for (char c : buf) {
		if (c == '(' || c == '[') {
			check_str.push_back(c);
			answer = false;
		}
		else if (false == check_str.empty()) {

			if ((*check_str.rbegin() == '(' && c == ')')
				|| (*check_str.rbegin() == '[' && c == ']')) {
				check_str.pop_back();
				answer = true;
			}
			else {
				answer = false;
				break;
			}
		}
		else {
			answer = false;
			break;
		}
	}
	if (answer && check_str.empty()) return true;
	else return false;
}

int main() {
	int N;
	std::string buf;
	std::cin >> N >> buf;
	std::list<char> str{ buf.begin(), buf.end() };

	while (!str.empty()) {
		std::list lhs = str, rhs = str;
		lhs.pop_front();
		rhs.pop_back();
		std::string ls{lhs.begin(), lhs.end()};
		std::string rs{rhs.begin(), rhs.end()};
		if (check_pair(ls) || check_pair(rs)) {
			printf("jimin");
			return 0;
		}
		else {
			if (!str.empty()) str.pop_back();
			if (!str.empty()) str.pop_front();
		}
	}

	printf("junhui");
	return 0;
}
