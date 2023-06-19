#include <iostream>
#include <map>

int main()
{
    std::map<int, int> numbers;
    std::map<int, int>::iterator iter;
    int inCount;
    scanf("%d", &inCount);

    for (int i = 0; i < inCount; ++i) {
        int inputNum;
        scanf(" %d", &inputNum);
        if (numbers.find(inputNum) == numbers.end()) {
            numbers.insert({ inputNum, 1 });
        }
        else {
            iter = numbers.find(inputNum);
            iter->second += 1;
        }
    }
    for (std::pair<int, int> p : numbers) {
        for (int i = 0; i < (int)p.second; ++i) {
            printf("%d\n", p.first);
        }
    }
}
