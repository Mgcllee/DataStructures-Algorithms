#pragma once

#include "main.h"
#include "SortFunctions.h"

#include <vector>
#include <algorithm>
#include <set>

int eratos(set<int>& num) {
	vector<int> nums;

	// 현재 result로 넘겨 num 변수로 전달받는 컨테이너가 정상적으로 전달되지 못함.

	for (int i = 2; i <= *num.crbegin(); ++i) 
		nums.push_back(i);

	for (int i = 2; i <= *num.crbegin(); ++i) {
		if (nums[i - 2] == 0) 
			continue;
		for (int j = i + i; j <= *num.crbegin(); j += i)
			nums[j - 2] = 0;
	}

	int cnt = 0;
	for (int n : nums) {
		if (n == 0) continue;
		if (num.find(n) != num.end() && n != 0)
			cnt += 1;
	}
	return cnt;
}
void failCase01() {
	vector<int> nums = { 1,2,7,6,4 };

	/*

	[설계 단계]
	1. nums의 숫자들을 홀수, 짝수로 구분하여 새로운 vector<int>에 저장한다.
	2. 홀수 == 홀수 x 3 == 홀수 x 1 + 짝수 x 2 임을 이용하여 set<int>에 중복을 제거하면서 저장한다.
	3. "에라토스테네스의 체"를 이용하여 set<int>에 저장되어 있는 숫자 중 가장 큰 수까지 소수들을 저장하는 컨테이너를 제작한다.
	4. 소수가 저장되어 있는 컨테이너와 set<int> 컨테이너를 비교하여 소수를 걸러낸다.

	[실행 단계]
	1. 홀수와 짝수를 정렬하여 실행할 경우, 테스트 케이스에 나와있는 것은 통과되나, 왜 가능한지 이해하지 못함.

	[실패 이유]
	1. 3가지의 숫자의 합이라는 것에 대해 어떤 방식으로 해결해야 할지 방향을 못 잡음.
	2. 반복문이 너무 많아 비효율적임.

	*/


	int answer = 0;
	set<int> result;
	vector<int> odds, evens;
	for (int n : nums) (n % 2 == 0) ? evens.push_back(n) : odds.push_back(n);

	sort(odds.begin(), odds.end());
	sort(evens.begin(), evens.end());

	for (int odd : odds) {
		for (int i = 0; i < evens.size() - 1; ++i) {
			result.insert(odd + evens[i] + evens[i + 1]);
			cout << odd << " + " << evens[i] << " + " << evens[i + 1] << endl;
		}
	}
	for (int i = 0; i < odds.size() - 2; ++i) {
		result.insert(odds[i] + odds[i + 1] + odds[i + 2]);
		cout << odds[i] << " + " << odds[i + 1] << " + " << odds[i + 2] << endl;
	}

	cout << eratos(result);
}

void Combination(vector<int> vec, vector<int> comb, int r, int index, int depth, set<int>& result) {
	if (r == 0) {
		int sum = 0;
		for (int n : comb) {
			cout << n << " + ";
			// sum += n;
		}
		cout << endl;
		// result.insert(sum);
	}
	else if (depth == vec.size()) {
		return;
	}
	else {
		comb[index] = vec[depth];
		Combination(vec, comb, r - 1, index + 1, depth + 1, result);

		Combination(vec, comb, r, index, depth + 1, result);
	}
}

int main() {
	vector<int> nums = { 1, 5, 6 };
	set<int> result;
	//=> 3개의 숫자를 모두 더하는 것이므로 '조합' 연산을 통해서 모든 경우의 결과를 구한다.	
	
	int selector = 3;
	vector<int> comb(selector);
	Combination(nums, comb, selector, 0, 0, result);

	for (int n : result)
		cout << n << endl;
	cout << "===============\n";

	cout << eratos(result);
}
