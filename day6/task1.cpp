#include <iostream>
#include <vector>
#include <fstream>
int main()
{
    std::string input;
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
    long long length = inputs[0].length();
    for (long long i = 0; i < inputs.size() - 1; i++)
    {
        long long length = inputs[i].length();
        for (long long j = 0; j < length; j++)
        {
            if (inputs[i][j] != ' ')
            {
                chars.push_back(inputs[i][j]);
            }
            else
            {
                if (!chars.empty())
                {
                    std::string numberString(chars.begin(), chars.end());
                    chars.clear();
                    long long tmp = std::stoll(numberString);
                    allNumbers.push_back(tmp);
                }
            }
        }
        if (!chars.empty())
        {
            std::string numberString(chars.begin(), chars.end());
            chars.clear();
            long long tmp = std::stoll(numberString);
            allNumbers.push_back(tmp);
        }
    }
    for (long long j = 0; j < length; j++)
    {
        if ((inputs[inputs.size() - 1][j] == '+') || (inputs[inputs.size() - 1][j] == '*'))
        {
            allOperations.push_back(inputs[inputs.size() - 1][j]);
        }
    }

    long long result = 0;
    std::vector<long long> columnResult;
    long long start = 0;

    for (long long i = 0; i < allOperations.size(); i++)
    {
        long long tmp = 0;
        long long tmp2 = 1;
        for (long long j = i; j < allNumbers.size(); j += allOperations.size())
        {
            if (allOperations[i] == '*')
            {
                tmp2 *= allNumbers[j];
            }
            else
            {
                tmp += allNumbers[j];
            }
            std::cout << "allNumbers[j]" << allNumbers[j] << std::endl;
        }
        if (tmp != 0)
        {
            columnResult.push_back(tmp);
        }
        else if (tmp2 != 1)
        {
            columnResult.push_back(tmp2);
        }
    }
    for (auto elem : columnResult)
    {
        result += elem;
    }

    // PRITNS
    for (auto elem : allNumbers)
    {
        std::cout << elem << std::endl;
    }
    for (auto elem : allOperations)
    {
        std::cout << elem << std::endl;
    }
    for (auto elem : columnResult)
    {
        std::cout << elem << std::endl;
    }
    std::cout << allOperations.size() << " " << allNumbers.size() << " " << std::endl;
    std::cout << "result: " << result << std::endl;
    return 0;
}