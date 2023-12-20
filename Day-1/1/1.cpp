#include <iostream>
#include <string>

int main()
{
    std::string line;
    int sum = 0;
    while (std::getline(std::cin, line))
    {
        int first = line.find_first_of("0123456789");
        int last = line.find_last_of("0123456789");
        {
            sum += std::stoi(line.substr(first, 1)) * 10 + std::stoi(line.substr(last, 1));
        }
    }
    std::cout << sum << std::endl;
}