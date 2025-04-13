#include <iostream>
#include "graph.h"

int main()
{
    std::cout << "Graph by Kolin63\n";
    std::cout << "https://github.com/kolin63/graph\n";

    std::vector<std::pair<std::uint32_t, std::uint32_t>> data{
        { 0, 5 }, { 1, 4 }, { 2, 3 }, { 3, 2 }, { 4, 1 }, { 5, 0 }
    };

    kolin::graph graph{ 20, 20, data };

    std::cout << graph.make_body();

    return 0;
}