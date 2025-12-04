#include <iostream>
#include <vector>
#include <fstream>

int main()
{
    int result = 0;
    std::vector<std::string> input;
    std::string inputs;
    std::vector<char> helper;
    std::ifstream infile("data.txt");
    std::getline(infile, inputs);
    inputs.insert(0, 1, '.');
    inputs.append(".");
    for (int i = 0; i < inputs.length() + 2; i++)
    {
        helper.push_back('.');
    }
    std::string tmp(helper.begin(), helper.end());
    input.push_back(tmp);
    input.push_back(inputs);
    while (std::getline(infile, inputs))
    {
        if (inputs.empty())
            break;
        inputs.insert(0, 1, '.');
        inputs.append(".");
        input.push_back(inputs);
    }
    input.push_back(tmp);
    std::vector<std::vector<char>> data(input.size());
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input[i].length(); j++)
        {
            data[i].push_back(input[i][j]);
        }
    }
    for (auto elem : data)
    {
        for (auto elem2 : elem)
        {
            std::cout << elem2;
        }
        std::cout << std::endl;
    }

    for (int i = 1; i < input.size() - 1; i++)
    {
        for (int j = 1; j < input[i].length() - 1; j++)
        {
            if (data[i][j] == '@')
            {
                int numberOfRolls = 0;
                numberOfRolls += (data[i - 1][j - 1] == '@');
                std::cout << numberOfRolls;
                numberOfRolls += (data[i - 1][j] == '@');
                std::cout << numberOfRolls;
                numberOfRolls += (data[i - 1][j + 1] == '@');
                std::cout << numberOfRolls;
                numberOfRolls += (data[i][j - 1] == '@');
                std::cout << numberOfRolls;
                numberOfRolls += (data[i][j + 1] == '@');
                std::cout << numberOfRolls;
                numberOfRolls += (data[i + 1][j - 1] == '@');
                std::cout << numberOfRolls;
                numberOfRolls += (data[i + 1][j] == '@');
                std::cout << numberOfRolls;
                numberOfRolls += (data[i + 1][j + 1] == '@');
                if (numberOfRolls < 4)
                {
                    result++;
                }
                std::cout << numberOfRolls << std::endl;
                std::cout << "result: " << result << std::endl;
            }
        }
    }
    std::cout << "result: " << result << std::endl;
    return 0;
}