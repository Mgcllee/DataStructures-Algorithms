#pragma once

#include "main.h"
#include "SortFunctions.h"

#include <vector>
#include <algorithm>
#include <map>

int eratos(vector<int>& num) {
	vector<int> primeNums;

	for (int i = 2; i <= *num.crbegin(); ++i) 
		primeNums.push_back(i);

	for (int i = 2; i <= *num.crbegin(); ++i) {
		if (primeNums[i - 2] == 0)
			continue;
		for (int j = i + i; j <= *num.crbegin(); j += i)
			primeNums[j - 2] = 0;
	}

	int cnt = 0;
	for (int n : primeNums) {
		if (n != 0)
			cnt += 1;
	}
	
	return cnt;
}
void Combination(vector<int> vec, vector<int> comb, int r, int index, int depth, vector<int>& result) {
	if (r == 0) {
		int sum = 0;
		for (int n : comb) {
			sum += n;
		}
		result.push_back(sum);
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

bool Comp(pair<int, pair<double, double>>& a, pair<int, pair<double, double>>& b) {
	return a.second.first / (float)a.second.second > b.second.first / (float)b.second.second;
}

int main() {
	/*vector<int> nums = { 1, 2, 3, 4, 5, 7 , 8 };
	vector<int> result;
	int selector = 3;
	vector<int> comb(selector);
	Combination(nums, comb, selector, 0, 0, result);
	cout << eratos(result);*/

	int N = 5;
	vector<int> stages = { 3, 3, 3, 3, 3 };
	// <스테이비 번호, <현스테이지 인원, 도착한 인원>>

	vector<int> answer;
	map<int, pair<double, double>> info;

	for (int curStage = 1; curStage <= N; ++curStage) {
		info.insert({ curStage, {0, 0} });
	}
	
	for (int curStage : stages) {
		if (auto search = info.find(curStage); search != info.end()) {
			search->second.first += 1;
			search->second.second += 1;
			for (map<int, pair<double, double>>::iterator it = info.begin(); it != search; ++it) {
				it->second.second += 1;
			}
		}
		else {
			for (map<int, pair<double, double>>::iterator it = info.begin(); it != info.end(); ++it) {
				it->second.second += 1;
			}
		}
	}

	vector<pair<int, pair<double, double>>> result(info.begin(), info.end());
	sort(result.begin(), result.end(), Comp);

	for (auto p : result) {
		// answer.push_back(p.first);
		cout << p.first << ": " << p.second.first << "/" << p.second.second << endl;
		// cout << p.first << endl;
	}
}
