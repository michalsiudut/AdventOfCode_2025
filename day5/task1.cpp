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
    std::cout << "---------------" << std::endl;
    while (std::getline(infile, input))
    {
        if (input.empty())
        {
            while (std::getline(infile, input))
            {
                if (input.empty())
                {
                    break;
                }
                long long tmp = std::stoll(input);
                toCheck.push_back(tmp);
            }
            break;
        }
        ranges.push_back(input);
    }
    std::cout << "---------------" << std::endl;
    long long size = ranges.size() - 1;
    std::string lastIndex = ranges[size];
    long long index;
    for (long long i = 0; i < lastIndex.length(); i++)
    {
        if (lastIndex[i] == '-')
        {
            index = i + 1;
            break;
        }
    }
    std::cout << "---------------" << std::endl;
    std::set<long long> results;
    long long lastIndexSep = std::stoll(lastIndex.substr(index));
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
        std::cout << "---------------" << std::endl;
        std::string tmp2(chars.begin(), chars.end());
        second = std::stoll(tmp2);
        for (long long k = 0; k < toCheck.size(); k++)
        {
            if ((toCheck[k] >= first) && (toCheck[k] <= second))
            {
                results.insert(toCheck[k]);
            }
        }
        chars.clear();
    }

    result = results.size();
    std::cout
        << "result: " << result << std::endl;
    return 0;
}