#include <iostream>
#include <vector>
#include <fstream>
#include <map>

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
    std::vector<std::pair<int, int>> indexes;
    bool isGoing = true;
    while (isGoing)
    {

        for (int i = 1; i < input.size() - 1; i++)
        {
            for (int j = 1; j < input[i].length() - 1; j++)
            {
                if (data[i][j] == '@')
                {
                    int numberOfRolls = 0;
                    for (int di = -1; di <= 1; di++)
                    {
                        for (int dj = -1; dj <= 1; dj++)
                        {
                            if (di == 0 && dj == 0)
                                continue;
                            if (data[i + di][j + dj] == '@')
                                numberOfRolls++;
                        }
                    }

                    if (numberOfRolls < 4)
                    {
                        result++;
                        indexes.push_back({i, j});
                    }
                }
            }
        }
        if (indexes.empty())
        {
            isGoing = false;
        }

        for (auto elem : indexes)
        {
            data[elem.first][elem.second] = '.';
        }
        indexes.clear();
    }
    for (auto elem : data)
    {
        for (auto elem2 : elem)
        {
            std::cout << elem2;
        }
        std::cout << std::endl;
    }

    for (auto elem : indexes)
    {
        std::cout << elem.first << "  " << elem.second << std::endl;
    }
    std::cout << "result: " << result << std::endl;
    return 0;
}