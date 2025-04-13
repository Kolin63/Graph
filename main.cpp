#include <iostream>
#include <cmath>
#include "graph.h"

static void basic_example()
{
    kolin::graph::dataset data{
        { 0, 5 }, { 1, 4 }, { 2, 3 }, { 3, 2 }, { 4, 1 }, { 5, 0 }
    };

    std::cout << kolin::graph{ 25, 8, data }.make_body() << "\n\n";
}

static void sin_wave()
{
    constexpr double stretch{ 25 };
    constexpr double hor_stretch{ 0.1 };
    constexpr std::uint32_t width{ 250 };
    constexpr std::uint32_t height{ 75 };

    kolin::graph::dataset data(width);

    for (std::uint32_t x{}; x < width; ++x) {
        data[x].first = x;
        data[x].second = static_cast<int>(std::floor(stretch * std::sin(static_cast<double>(hor_stretch * x)) + stretch));
    }

    std::cout << kolin::graph{ width, height, data }.make_body() << "\n\n";
}

static void reciprocal()
{
    constexpr uint32_t x_offset{ 4 };
    constexpr uint32_t y_offset{ 30 };
    constexpr double stretch{ 20 };
    constexpr double hor_stretch{ 0.1 };
    constexpr std::uint32_t width{ 75 };
    constexpr std::uint32_t height{ 75 };

    kolin::graph::dataset data(width);

    for (std::uint32_t x{}; x < width; ++x) {
        data[x].first = x;
        data[x].second = static_cast<int>(std::floor((1.0 / (hor_stretch * x - x_offset) * stretch + y_offset)));
    }

    std::cout << kolin::graph{ width, height, data }.make_body() << "\n\n";
}

int main()
{
    std::cout << "Graph by Kolin63\n";
    std::cout << "https://github.com/kolin63/graph\n\n";

    basic_example();
    sin_wave();
    reciprocal();

    return 0;
}