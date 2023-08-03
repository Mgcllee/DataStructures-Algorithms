#pragma once

#include "main.h"

string split(string str, string target) {
    string result{};

    int previous = 0;
    int curCount = str.find(target);
    while (curCount != string::npos) {
        result += str.substr(previous, curCount - previous);
        previous = curCount + target.size();
        curCount = str.find(target, previous);
    }
    result += str.substr(previous, curCount - previous);
    return result;
}