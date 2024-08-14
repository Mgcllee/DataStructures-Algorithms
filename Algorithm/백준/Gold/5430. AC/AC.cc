#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::string get_array(std::string ch_arr, std::string order)
{
    ch_arr.erase(remove(ch_arr.begin(), ch_arr.end(), '['), ch_arr.end());
    ch_arr.erase(remove(ch_arr.begin(), ch_arr.end(), ']'), ch_arr.end());

    std::vector<int> vec;
    if (ch_arr.length() >= 3)
    {
        std::istringstream iss(ch_arr);
        std::string buf;

        while (getline(iss, buf, ','))
        {
            vec.push_back(std::stoi(buf));
        }
    }
    else if (std::string::npos == ch_arr.find(',') && ch_arr.length() >= 1)
    {
        vec.push_back(std::stoi(ch_arr));
    }

    int dir = 1;
    int left_del_curr = 0;
    int right_del_curr = 0;
    for (char c : order)
    {
        switch (c)
        {
        case 'R':
            dir *= -1;
            break;
        case 'D':
            if (vec.size() >= 1)
            {
                int del_index = ((vec.size() - 1) * (dir == 1 ? 0 : 1)) + (dir * ((dir == 1) ? left_del_curr : right_del_curr));
                if(del_index >= vec.size())
                    return "error";

                vec[del_index] = -1;

                if (dir == 1) ++left_del_curr;
                else ++right_del_curr;
            }
            else
            {
                return "error";
            }
            break;
        }
    }

    if (dir == -1)
        std::reverse(vec.begin(), vec.end());

    std::string answer = "[";
    for (int n : vec)
    {
        if (n != -1)
            answer += (std::to_string(n) + ",");
    }
    if (answer.length() > 1)
        answer.pop_back();
    return answer.append("]");
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int T;
    std::cin >> T;
    for (int tc = 0; tc < T; ++tc)
    {
        std::string order, ch_arr;
        std::cin >> order;

        int N;
        std::cin >> N;
        std::cin >> ch_arr;

        std::cout << get_array(ch_arr, order) << std::endl;
    }

    return 0;
}