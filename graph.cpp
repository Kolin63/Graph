#include <cassert>
#include <iostream>
#include "graph.h"

std::uint32_t kolin::graph::coord_to_index(std::uint32_t x, std::uint32_t y, std::uint32_t start_x) const
{
    // Adding 1 to the width is to account for any \n characters
    std::uint32_t index{ y * (get_row_num_width() + 1 + m_width * get_col_width(start_x)) + x - 1 };

    //std::cout << '(' << x << ", " << y << "), " << index << '\n';

    if (index > m_body.size())
        throw out_of_range;

    return index;
}

void kolin::graph::set_coord(std::uint32_t x, std::uint32_t y, char c, std::uint32_t start_x)
{
    m_body[coord_to_index(x, y, start_x)] = c;
}

std::string kolin::graph::make_body(std::uint8_t int_x, std::uint8_t int_y, std::uint32_t start_x, std::uint32_t start_y)
{
    // Y-Axis Numbers and Dividers and Rows
    for (std::int64_t i{ static_cast<std::int64_t>(m_height) - 1}; i >= 0; --i) {
        std::string num{ std::to_string(i * int_y + start_y) };
        m_body += std::string(get_row_num_width() - 1 - num.size(), ' ') + num + '|' + std::string(m_width * get_col_width(start_x), ' ') + '\n';
    }

    // X-Axis Divider
    m_body += std::string(get_row_num_width(), ' ') + std::string(get_col_width(start_x) * m_width, '-') + '\n';

    // X-Axis Numbers
    m_body += std::string(get_col_width(start_x), ' ');

    for (std::uint32_t i{}; i < m_width; ++i) {
        std::string num{ std::to_string(i * int_x + start_x) };
        m_body += std::string(get_col_width(start_x) - num.size(), ' ') + num;
    }

    // Sets the data points
    for (const auto& point : m_data) {
        try {
            set_point(point.first, point.second, '#', int_x, int_y, start_x, start_y);
        }
        // if there is an error we simply do not set that point
        catch (kolin::graph::error) {}
    }

    return m_body; 
}

std::uint32_t kolin::graph::point_to_index(std::uint32_t x, std::uint32_t y, std::uint8_t int_x, std::uint8_t int_y, std::uint32_t start_x, std::uint32_t start_y) const
{
    if (x < start_x) throw kolin::graph::out_of_range;
    if (y < start_y) throw kolin::graph::out_of_range;

    //std::cout << '(' << x << ", " << y << ") -> ";

    const std::uint32_t gx{ get_col_width(start_x) * ((x / int_x) - start_x + 1) + (get_row_num_width()) };
    const std::uint32_t gy{ get_height() - (y / int_y) - 1 + start_y };

    return coord_to_index(gx, gy, start_x);
}

void kolin::graph::set_point(std::uint32_t x, std::uint32_t y, char c, std::uint8_t int_x, std::uint8_t int_y, std::uint32_t start_x, std::uint32_t start_y)
{
    m_body[point_to_index(x, y, int_x, int_y, start_x, start_y)] = c;
}

std::uint32_t kolin::graph::get_col_width(std::uint32_t start_x) const
{
    // Adding 1 is padding, so the numbers aren't directly next to eachother
    return static_cast<std::uint32_t>(std::to_string(m_width + start_x - 1).size() + 1);
}

std::uint32_t kolin::graph::get_row_num_width() const
{
    // Does not account for the seperation pipe 
    return static_cast<std::uint32_t>(std::to_string(m_height).size() + 1);
}
