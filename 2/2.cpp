#include <bits/stdc++.h>
using namespace std;

std::pair<size_t, size_t> findLargestAndSmallestIndex(const std::string &str, const std::string &substring)
{
    size_t startIndex = 0;

    size_t found = str.find(substring, startIndex);

    if (found != std::string::npos)
    {
        size_t largestIndex = found;
        size_t smallestIndex = found;

        startIndex = found + 1;

        while (startIndex < str.length())
        {
            found = str.find(substring, startIndex);

            if (found != std::string::npos)
            {
                largestIndex = std::max(largestIndex, found);
                smallestIndex = std::min(smallestIndex, found);

                startIndex = found + 1;
            }
            else
            {
                break;
            }
        }

        return std::make_pair(smallestIndex, largestIndex);
    }

    return std::make_pair(std::string::npos, std::string::npos);
}

int main()
{
    string line;
    vector<pair<string, int>> substrings = {
        {"zero", 0},
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9}};

    int sum = 0;

    while (getline(cin, line))
    {
        int min_pos = -1;
        int max_pos = -1;
        int first;
        int last;

        for (unsigned int i = 0; i < substrings.size(); i++)
        {
            pair<size_t, size_t> result = findLargestAndSmallestIndex(line, substrings[i].first);
            if (result.first != std::string::npos && result.second != std::string::npos)
            {
                // cout << "substring : " << line.substr(result.first, substrings[i].first.size()) << " at position " << result.first << endl;
                // cout << "substring : " << line.substr(result.second, substrings[i].first.size()) << " at position " << result.second << endl;
                if (min_pos == -1)
                {
                    min_pos = result.first;
                    first = substrings[i].second;
                }
                else if (min_pos >= result.first)
                {
                    min_pos = result.first;
                    first = substrings[i].second;
                    // cout << "first : " << first << endl;
                }
                if (max_pos == -1)
                {
                    max_pos = result.second;
                    last = substrings[i].second;
                }
                else if (max_pos <= result.second)
                {
                    max_pos = result.second;
                    last = substrings[i].second;
                    // cout << "last : " << last << endl;
                }
            }
        }
        int first_digit = line.find_first_of("0123456789");
        // cout << "first_digit : " << first_digit << endl;
        if (min_pos == -1)
        {
            min_pos = first_digit;
            first = std::stoi(line.substr(min_pos, 1));
        }
        else if (first_digit != -1 && first_digit < min_pos)
        {
            min_pos = first_digit;
            first = std::stoi(line.substr(min_pos, 1));
        }
        int last_digit = line.find_last_of("0123456789");
        // cout << "last_digit : " << last_digit << endl;
        if (max_pos == -1)
        {
            max_pos = last_digit;
            last = std::stoi(line.substr(max_pos, 1));
        }
        else if (last_digit != -1 && last_digit > max_pos)
        {
            max_pos = last_digit;
            last = std::stoi(line.substr(max_pos, 1));
        }
        // cout << first << " " << last << endl;
        int number = first * 10 + last;
        sum += number;
    }
    cout << sum << endl;
}