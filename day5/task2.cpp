#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>

int main()
{
    std::string input;
    std::vector<std::string> ranges;
    std::vector<long long> toCheck;
    std::ifstream infile("data.txt");
    while (std::getline(infile, input))
    {
        if (input.empty())
        {
            break;
        }
        ranges.push_back(input);
    }
    std::vector<std::pair<long, long>> all;
    long long result = 0;
    std::vector<long long> indexes;
    std::vector<char> chars;
    for (auto elem : ranges)
    {
        long long first, second;
        for (long long i = 0; i < elem.length(); i++)
        {
            if (elem[i] != '-')
            {
                chars.push_back(elem[i]);
            }
            else
            {
                std::string tmp(chars.begin(), chars.end());
                first = std::stoll(tmp);
                chars.clear();
            }
        }
        std::string tmp2(chars.begin(), chars.end());
        second = std::stoll(tmp2);
        all.push_back({first, second});
        chars.clear();
    }

    std::sort(all.begin(), all.end());

    long long current_start = all[0].first;
    long long current_end = all[0].second;

    for (int i = 1; i < all.size(); i++)
    {
        long long next_start = all[i].first;
        long long next_end = all[i].second;
        if (next_start <= current_end + 1)
        {
            current_end = std::max(current_end, next_end);
        }
        else
        {
            result += (current_end - current_start + 1);
            current_start = next_start;
            current_end = next_end;
        }
    }

    result += (current_end - current_start + 1);
    std::cout << "result: " << result << std::endl;
    return 0;
}