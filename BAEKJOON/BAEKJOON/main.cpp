#pragma once

#include "main.h"
#include "SortFunctions.h"

#include <algorithm>
#include <vector>
#include <set>


vector<string> strings = { "sun", "bed", "car" };

struct Compare {
    int inPos;

    Compare(int variable) : inPos(0 < variable ? variable : 0) {}

    bool operator()(const string& ls, const string& rs) const {
        int min = ls.length() > rs.length() ? ls.length() : rs.length();
        int newIndex = ((int)ls[inPos] == (int)rs[inPos] || inPos == min - 1) ? 0 : inPos;

        for (int curPos = newIndex; curPos < min; ++curPos) {
            if ((int)ls[curPos] != (int)rs[curPos]) {
                return (int)ls[curPos] < (int)rs[curPos];
            }
        }
    }
};

int simpleN = 1;
bool simpleCompare(string& ls, string& rs) {
    return ls == rs ? ls < rs : ls[simpleN] < rs[simpleN];
}

int main() {
    int n = 1;

    /*
    [프로그래머스 연습문제 - "문자열 내 마음대로 정렬하기"]
    
    첫 번째 직면한 문제: 퀵 정렬을 사용하려고 하였으나, key 중복이 되어있을 경우, 정렬의 성능이 떨어짐
    해결방법: 중복이 허용되는 컨테이너(multi set, multi set)을 사용해서 정렬 시도

    두 번째 직면한 문제: 내가 원하는 비교 방법을 설정하기 위한 방법을 연구
    해결방법: 주어진 위치의 문자(값)이 같은 경우 마지막 원소까지 비교하고 문자가 다른 위치를 찾아 반환.

    세 번째 직면한 문제: 문제를 잘못 이해하여, 주어진 위치의 값이 같은 경우 뒤에서부터 정렬하는 것으로 오해
    해결방법: 주어진 위치의 문자(값)이 같은 경우 문자열 비교를 사용해 값을 반환.
    */

    /*
    multiset<string, Compare> words(strings.begin(), strings.end(), Compare(n));
    for (string s : words)
        cout << s << endl;    
    */

    sort(strings.begin(), strings.end(), simpleCompare);
    for (string s : strings)
        cout << s << endl;
}