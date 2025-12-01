#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    int result = 0, actualNumber = 50;
    std::vector<std::string> inputs;
    std::string input = "";
    while (std::getline(std::cin, input))
    {
        if (input.empty())
            break;
        inputs.push_back(input);
    }
    std::string tmp;
    int numberOfReducing = 0;
    for (int i = 0; i < inputs.size(); i++)
    {
        tmp = inputs[i];
        char a = tmp[0];
        int numbers = std::stoi(tmp.substr(1));

        int dir = (a == 'L') ? -1 : 1;
        int kfirst = (dir == 1) ? (100 - actualNumber) % 100 : (actualNumber % 100);
        if (kfirst == 0)
            kfirst = 100;

        if (numbers >= kfirst)
        {
            result += 1 + (numbers - kfirst) / 100;
        }

        actualNumber = (actualNumber + dir * numbers) % 100;

        if (actualNumber < 0)
            actualNumber += 100;
    }

    std::cout << "result: " << result << std::endl;
    return 0;
}