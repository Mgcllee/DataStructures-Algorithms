#include <iostream>
#include <set>

int main()
{
	int T;
	std::cin >> T;
	for (int tc = 0; tc < T; ++tc)
	{
		int oper_cnt;
		std::cin >> oper_cnt;
		std::multiset<int> set;

		for (int oper = 0; oper < oper_cnt; ++oper)
		{
			char order;
			int number;
			std::cin >> order >> number;
			if (order == 'I')
			{
				set.insert(number);
			}
			else if ((set.size() != 0) && (number == 1))
			{
				set.erase(set.find(*set.rbegin()));
			}
			else if ((set.size() != 0) && (number == -1))
			{
				set.erase(set.find(*set.begin()));
			}
		}

		if (set.empty())
		{
			printf("EMPTY\n");
		}
		else
		{
			printf("%d %d\n", *set.rbegin(), *set.begin());
		}
	}
	return 0;
}