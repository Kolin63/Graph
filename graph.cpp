#include <cassert>
#include "graph.h"

std::uint32_t kolin::graph::coord_to_index(std::uint32_t x, std::uint32_t y) const
{
    assert(x * y < m_body.size() && "x * y must be less than body size");

    // Adding 1 to the width is to account for any \n characters
    std::uint32_t index{ y * (m_width + 1) + x };

    assert(index < m_body.size() && "index must be less than body size");

    return index;
}

void kolin::graph::set_coord(std::uint32_t x, std::uint32_t y, char c)
{
    m_body[coord_to_index(x, y)] = c;
}

std::string kolin::graph::make_body(std::uint32_t int_x, std::uint32_t int_y)
{
    int_x;
    int_y;

    return ""; // todo
}

std::uint32_t kolin::graph::point_to_index(std::uint32_t x, std::uint32_t y, std::uint8_t int_x, std::uint8_t int_y, std::uint32_t start_x) const
{
    assert(x >= start_x && "x cannot be less than start x");

    const std::uint16_t gx{ static_cast<std::uint16_t>(x - start_x - ( (get_col_width() * (x / int_x)) + (get_row_num_width() + 1) )) };
    const std::uint16_t gy{ static_cast<std::uint16_t>(get_height() - (y / int_y)) };

    return coord_to_index(gx, gy);
}

void kolin::graph::set_point(std::uint32_t x, std::uint32_t y, char c, std::uint8_t int_x, std::uint8_t int_y, std::uint32_t start_x)
{
    m_body[point_to_index(x, y, int_x, int_y, start_x)] = c;
}

std::size_t kolin::graph::get_col_width() const
{
    // Adding 1 is padding, so the numbers aren't directly next to eachother
    return std::to_string(m_width).size() + 1;
}

std::size_t kolin::graph::get_row_num_width() const
{
    // Does not account for the seperation pipe 
    return std::to_string(m_height).size();
}
