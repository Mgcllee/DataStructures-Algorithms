#include <iostream>
using namespace std;

int main()
{
	
	int result = 0, cnt = 0, N;
	cin >> N;

	while (cnt != N)
	{
		++result;
		int temp = result;

		while (temp != 0)
		{
			if (temp % 1000 == 666)
			{
				cnt++;
				break;
			}
			else 
			temp /= 10;
		}
	}
	printf("%d", result);
	return 0;
}