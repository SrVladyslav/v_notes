#include <vector>
#include <iostream>

void pprint(const std::vector<char> &symbols)
{
    printf("\nSymbols: ");
    for (char c : symbols)
    {
        std::cout << c << " ";
    }
    std::cout << std::endl;
}