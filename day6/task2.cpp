#include <iostream>
#include <vector>
#include <fstream>
int main()
{
    std::string input;
    long long result = 0;
    std::vector<std::string> inputs;
    std::ifstream infile("data.txt");
    while (std::getline(infile, input))
    {
        if (input.empty())
        {
            break;
        }
        inputs.push_back(input);
    }
    std::vector<long long> allNumbers;
    std::vector<char> allOperations;
    std::vector<char> chars;
    std::vector<long long> results;

    for (long long j = 0; j < inputs[0].length(); j++)
    {
        if ((inputs[inputs.size() - 1][j] == '+') || (inputs[inputs.size() - 1][j] == '*'))
        {
            allOperations.push_back(inputs[inputs.size() - 1][j]);
        }
    }
    long long length = inputs[0].length();
    long long z = 0;
    long long num_data_rows = inputs.size() - 1;
    for (long long k = 0; k < length; k++)
    {
        for (long long j = 0; j < num_data_rows; j++) // biore 1 index  q 1 string
        {
            if (inputs[j][k] != ' ')
            {
                chars.push_back(inputs[j][k]);
            }
        }
        if (!chars.empty())
        {
            std::string tmp(chars.begin(), chars.end());
            long long tmp2 = std::stoll(tmp);
            allNumbers.push_back(tmp2);
            chars.clear();
        }
        else
        {
            long long tmp = 0;
            if (allOperations[z] == '*')
            {
                tmp = 1;
                for (auto elem : allNumbers)
                {
                    tmp *= elem;
                }
                results.push_back(tmp);
            }
            else
            {

                for (auto elem : allNumbers)
                {
                    tmp += elem;
                }
                results.push_back(tmp);
            }
            z++;
            allNumbers.clear();
            std::cout << "tmp: " << tmp << std::endl;
        }
    }

    long long tmp = 0;
    if (allOperations[z] == '*')
    {
        tmp = 1;
        for (auto elem : allNumbers)
        {
            tmp *= elem;
        }
        results.push_back(tmp);
    }
    else
    {

        for (auto elem : allNumbers)
        {
            tmp += elem;
        }
        results.push_back(tmp);
    }
    z++;
    allNumbers.clear();
    std::cout << "tmp: " << tmp << std::endl;

    for (auto elem : results)
    {
        result += elem;
    }

    std::cout << "result: " << result << std::endl;
    return 0;
}