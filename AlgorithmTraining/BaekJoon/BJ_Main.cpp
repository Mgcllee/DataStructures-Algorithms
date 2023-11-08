#include <iostream>

int main() 
{
	int Min = 0, Max = 0;
	std::cin >> Min >> Max;
	bool* PrimeArray = new bool[Max];

	for (int i = 2; i <= Max; i++)
		PrimeArray[i] = true;

	for (int i = 2; i <= Max; i++)
	{
		if (PrimeArray[i])
		{
			for (int j = i + i; j <= Max; j += i)
				PrimeArray[j] = false;
		}
	}

	// cout << endl을 사용할 경우 buffer를 지울 때 시간이 소요되어 타임오버
	for (int i = Min; i <= Max; ++i)
		if (PrimeArray[i] && i >= 2) printf("%d\n", i);
}
