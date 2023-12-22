#include<iostream>

int main() {
	int T;
	std::cin >> T;
	
	for (int i = 0; i < T; ++i) {
		std::string buf;
		std::cin >> buf;
		int lcnt = 0, rcnt = 0;
		for (char c : buf) {
			if (c == '(') lcnt += 1;
			else rcnt += 1;
			if (lcnt < rcnt) break;
		}
		if (lcnt == rcnt) printf("YES\n");
		else printf("NO\n");
	}
}