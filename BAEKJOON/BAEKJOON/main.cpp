#pragma once

#include "main.h"
#include "SortFunctions.h"

#include <vector>
#include <set>
#include <algorithm>

/*
전체 순회가 아닌 정렬기준변경을 사용하면 예외가 발생 -> 이미 정렬된 정수는 접근하지 않음.
버블정렬 방식은 효율성이 떨이짐.
*/

void firstFunction() {
    vector<int> numbers = { 2,1,3,4,1 };
    // vector<int> numbers = { 0 };
    vector<int> answer;

    sort(numbers.begin(), numbers.end());

    for (int start = 0; start < numbers.size(); ++start) {
        answer.push_back(numbers[start]);

        for (int cur = start + 1; cur < numbers.size(); ++cur) {
            int sum = numbers[start] + numbers[cur];

            if (find(answer.begin(), answer.end(), sum) == answer.end()) {
                // cout << "Push-" << sum << " = " << numbers[start] << " + " << numbers[cur] << endl;

                cout << "\n\n======================\n";
                for (int i : answer)
                    cout << i << endl;
                cout << "======================\n\n";

                answer.pop_back();
                answer.push_back(sum);
            }
            else {

            }
        }
    }
}

int main() {
    vector<int> numbers = { 0, 1 };
    vector<int> answer;

    if(numbers.size() == 1) 

    sort(numbers.begin(), numbers.end());
    
    vector<int>::iterator resultCur = answer.begin();

    for (vector<int>::iterator start_it = numbers.begin(), cur_it = numbers.begin(); start_it < numbers.end(); ++start_it, cur_it = numbers.begin()) {
        for (; cur_it < numbers.end(); ++cur_it) { 
            int sum = *start_it + *cur_it;
            
            if (start_it != cur_it && find(answer.begin(), answer.end(), sum) == answer.end()) {
                answer.push_back(sum);
            }
        }
    }

    sort(answer.begin(), answer.end());
    for (int i : answer)
        cout << i << endl;
}