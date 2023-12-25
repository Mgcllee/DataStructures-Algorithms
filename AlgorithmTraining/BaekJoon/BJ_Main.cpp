#include <iostream>
#include <string>

int main() {
	while (true) {
		std::string buf;
		std::getline(std::cin, buf);
		if (buf == ".") break;
		std::string check_str;
		bool answer = true;
		for (char c : buf) {
			if (c != '(' && c != ')' && c != '[' && c != ']') continue;
			
			if (c == '(' || c == '[') {
				check_str.push_back(c);
				answer = false;
			} else if (false == check_str.empty()) {

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
		if (answer && check_str.empty()) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}