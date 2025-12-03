#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    char a, b;
    std::vector<std::string> inputs;
    std::string input;
    std::ifstream infile("data.txt");
    while (std::getline(infile, input))
    {
        if (input.empty())
            break;
        inputs.push_back(input);
    }
    std::vector<std::string> results;
    for (long long i = 0; i < inputs.size(); i++)
    {
        long long highest = 0, secondH = 0, indexOfH = 0, indexOfSH = 0;
        for (long long j = 0; j < inputs[i].length(); j++)
        {
            long long current = (long long)inputs[i][j] - '0';
            if (current > highest && j + 1 != inputs[i].length())
            {
                highest = current;
                indexOfH = j;
                a = inputs[i][j];
            }
        }
        for (long long j = indexOfH + 1; j < inputs[i].length(); j++)
        {
            long long current = (long long)inputs[i][j] - '0';
            if (current > secondH)
            {
                secondH = current;
                indexOfSH = j;
                b = inputs[i][j];
            }
        }
        std::string tmp = std::string(1, a) + b;
        std::cout << tmp << std::endl;
        results.push_back(tmp);
    }
    long long restult = 0;
    for (auto elem : results)
    {
        restult += std::stoll(elem);
    }

    std::cout << restult << std::endl;
    return 0;
}