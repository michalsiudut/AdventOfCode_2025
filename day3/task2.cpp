#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    char a;
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
    std::vector<char> chars;

    for (long long i = 0; i < inputs.size(); i++)
    {
        long long needed = 12;

        for (long long j = 0; j < inputs[i].length() && needed > 0; j++)
        {
            long long highest = 0;
            long long remaining = inputs[i].length() - j;
            long long maxReach = j + (remaining - needed);

            if (maxReach >= inputs[i].length())
                maxReach = inputs[i].length() - 1;

            for (long long k = j; k <= maxReach; k++)
            {
                long long current = (long long)inputs[i][k] - '0';

                if (current > highest)
                {
                    highest = current;
                    a = inputs[i][k];
                }
            }

            chars.push_back(a);
            needed--;
            while (j < inputs[i].length() && inputs[i][j] != a)
                j++;
        }

        std::string tmp(chars.begin(), chars.end());
        std::cout << tmp << std::endl;

        results.push_back(tmp);
        chars.clear();
    }

    long long result = 0;
    for (auto elem : results)
        result += std::stoll(elem);

    std::cout << result << std::endl;
    return 0;
}
