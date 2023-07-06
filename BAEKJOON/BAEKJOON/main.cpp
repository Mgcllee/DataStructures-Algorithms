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

int main() {
	double N = 3;
	vector<int> stages = { 1, 1, 2, 2 };

	vector<double> answer;
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
	stable_sort(result.begin(), result.end(), 
		[](const pair<int, pair<double, double>>& a, const pair<int, pair<double, double>>& b) {
			return a.second.first / a.second.second > b.second.first / b.second.second;
		});

	for (auto p : result) {
		answer.push_back(p.first);
		// cout << p.first << ": " << p.second.first << "/" << p.second.second << endl;
	}
}
