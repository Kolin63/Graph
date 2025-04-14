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

static void linear()
{
    constexpr uint32_t x_offset{ 0 };
    constexpr uint32_t y_offset{ 0 };
    constexpr std::uint32_t width{ 25 };
    constexpr std::uint32_t height{ 25 };

    kolin::graph::dataset data;

    for (std::uint32_t x{}; x < 100; ++x) {
        kolin::graph::point point{};
        point.first = x;
        point.second = x;

        data.push_back(point);
    }

    std::cout << kolin::graph{ width, height, data }.make_body(3, 2, x_offset, y_offset) << "\n\n";
}

static void sin_wave_small()
{
    constexpr double stretch{ 25 };
    constexpr double hor_stretch{ .1 };
    constexpr std::uint32_t width{ 35 };
    constexpr std::uint32_t height{ 25 };

    kolin::graph::dataset data;

    for (std::uint32_t x{}; x < 100; ++x) {
        kolin::graph::point point{};
        point.first = x;
        point.second = static_cast<int>(std::floor(stretch * std::sin(static_cast<double>(hor_stretch * x)) + stretch));

        data.push_back(point);
    }

    std::cout << kolin::graph{ width, height, data }.make_body(2, 2) << "\n\n";
}

static void scatter()  
{  
   constexpr std::uint32_t width{ 25 };  
   constexpr std::uint32_t height{ 28 };  

   kolin::graph::dataset data{ {  
       {0, 20}, {1, 21}, {2, 19}, {3, 22}, {4, 20}, {5, 23}, {6, 24}, {7, 22}, {8, 25}, {9, 26},  
       {10, 24}, {11, 27}, {12, 28}, {13, 26}, {14, 29}, {15, 30}, {16, 28}, {17, 31}, {18, 32}, {19, 30},  
       {20, 33}, {21, 34}, {22, 32}, {23, 35}, {24, 36}, {25, 34}, {26, 37}, {27, 38}, {28, 36}, {29, 39},  
       {30, 40}, {31, 38}, {32, 41}, {33, 42}, {34, 40}, {35, 43}, {36, 44}, {37, 42}, {38, 45}, {39, 46},  
       {40, 44}, {41, 47}, {42, 48}, {43, 46}, {44, 49}, {45, 50}, {46, 48}, {47, 51}, {48, 52}, {49, 50}  
   } };  

   std::cout << kolin::graph{ width, height, data }.make_body(1, 1, 0, 10) << "\n\n";  
}

static void vsteep()
{
    constexpr std::uint32_t width{ 25 };  
    constexpr std::uint32_t height{ 28 };  
    constexpr std::uint32_t slope{ 10 };

    kolin::graph::dataset data;
    
    for (std::uint32_t x{}; x < 100; ++x) {
        kolin::graph::point point{};
        point.first = x;
        point.second = slope * x;

        data.push_back(point);
    }

    std::cout << kolin::graph{ width, height, data }.make_body(1, 1) << "\n\n";
}

int main()
{
    std::cout << "Graph by Kolin63\n";
    std::cout << "https://github.com/kolin63/graph\n\n";

    basic_example();
    sin_wave();
    reciprocal();
    linear();
    sin_wave_small();
    scatter();
    vsteep();

    return 0;
}