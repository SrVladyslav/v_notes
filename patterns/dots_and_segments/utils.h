#include <iostream>
#include <vector>
#include <string>

template <typename T>
void print_segments(const std::vector<std::vector<T>> &segments, std::string text = "Segments: ")
{
    std::cout << text << std::endl;
    for (auto segment : segments)
    {
        std::cout << "[" << segment[0] << " " << segment[1] << "]  ";
    }
}

template <typename T>
void print_segments(const std::vector<std::pair<T, T>> &segments, std::string text = "Segments: ")
{
    std::cout << text << std::endl;
    for (auto segment : segments)
    {
        std::cout << "[" << segment.first << " " << segment.second << "]  ";
    }
}