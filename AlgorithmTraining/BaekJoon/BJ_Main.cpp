#include <iostream>
#include <vector>

void ComPerm(std::vector<int> num, std::vector<int> res, int cnt)
{
	if (cnt == res.size()) {
		for (int n : res)
			printf("%d ", n);
		printf("\n");
		return;
	}

	for (int i = 0; i < num.size(); ++i) {
		res[cnt] = num[i];
		ComPerm(num, res, cnt + 1);
	}
}

int main()
{
	int cnt, size;
	std::cin >> cnt >> size;
	std::vector<int> num;
	for (int i = 1; i <= cnt; ++i) num.push_back(i);
	std::vector<int> res(size);

	ComPerm(num, res, 0);

	return 0;
}