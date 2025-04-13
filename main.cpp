#include <iostream>
#include "graph.h"

int main()
{
    std::cout << "Graph by Kolin63\n";
    std::cout << "https://github.com/kolin63/graph\n";

    std::vector<std::pair<std::uint32_t, std::uint32_t>> data{
        { 0, 5 }, { 1, 4 }, { 2, 3 }, { 3, 2 }, { 4, 1 }, { 5, 0 }
    };

    kolin::graph graph{ 10, 20, data };

    return 0;
}