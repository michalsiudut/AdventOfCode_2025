#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    long long result = 0;
    std::string input;
    std::ifstream infile("data.txt");
    std::getline(infile, input);
    std::vector<char> idsChars;
    std::vector<std::string> ids;
    for (long long i = 0; i < input.length() + 1; i++)
    {
        if (input[i] != ',' && i != input.length() && input[i] != '-')
        {
            idsChars.push_back(input[i]);
        }
        else
        {
            std::string tmp(idsChars.begin(), idsChars.end());
            ids.push_back(tmp);
            tmp = "";
            idsChars.clear();
        }
    }
    std::vector<std::string> invalidIDs;
    for (long long i = 0; i < ids.size(); i += 2)
    {
        for (long long j = std::stoll(ids[i]); j < std::stoll(ids[i + 1]) + 1; j++)
        {
            std::string num = std::to_string(j);
            long long midpoint = num.length() / 2;
            std::string firstHalf = num.substr(0, midpoint);
            std::string secondHalf = num.substr(midpoint);
            if (firstHalf == secondHalf)
            {
                invalidIDs.push_back(num);
            }
        }
    }

    for (auto elem : ids)
    {
        std::cout << elem << std::endl;
    }

    for (long long i = 0; i < invalidIDs.size(); i++)
    {
        result += std::stoll(invalidIDs[i]);
    }

    std::cout << "result: " << result << std::endl;
    return 0;
}