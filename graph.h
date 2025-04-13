#ifndef KOLIN63_GRAPH_H
#define KOLIN63_GRAPH_H

#include <string>
#include <string_view>
#include <vector>

namespace kolin
{
    class graph
    {
    private:
        // The body of the graph, which can be printed to display it
        std::string m_body{};

        // The data of the graph, where the first of the pair is the x-coordinate 
        // and the second of the pair is the y-coordinate
        std::vector<std::pair<std::uint32_t, std::uint32_t>> m_data{};

        // How wide the graph is in characters
        // Does not include \n or \0
        std::uint32_t m_width{}; 
        // How tall the graph is in characters
        std::uint32_t m_height{};

        // Returns a one-dimensional index given a two-dimensional coordinate which can be used to index the body string
        // Note: (0, 0) is the top-left corner
        std::uint32_t coord_to_index(std::uint32_t x, std::uint32_t y) const;
        // Sets a character in the body given a two-dimensional coordinate
        // Note: (0, 0) is the top-left corner
        void set_coord(std::uint32_t x, std::uint32_t y, char c);

    public:
        graph(std::uint32_t width, std::uint32_t height, std::vector<std::pair<std::uint32_t, std::uint32_t>> data)
            : m_width{ width }, m_height{ height }, m_data{ data }
        { }

        // Returns the body of the graph
        std::string get_body() const { return m_body; }

        // Makes the body of the graph with the given interval and returns it
        std::string make_body(std::uint32_t int_x = 1, std::uint32_t int_y = 1, std::uint32_t start_x = 0);

        // Returns a one-dimensional index given a two-dimensional coordinate which can be used to index the body string
        // Note: (0, 0) is the bottom-left corner, or the origin, of the graph
        std::uint32_t point_to_index(std::uint32_t x, std::uint32_t y, std::uint8_t int_x = 1, std::uint8_t int_y = 1, std::uint32_t start_x = 0) const;
        // Sets a character in the body given a two-dimensional coordinate
        // Note: (0, 0) is the bottom-left corner, or the origin, of the graph
        void set_point(std::uint32_t x, std::uint32_t y, char c, std::uint8_t int_x = 1, std::uint8_t int_y = 1, std::uint32_t start_x = 0);

        // How wide the graph is in characters
        // Does not include \n or \0
        void set_width(std::uint32_t width) { m_width = width; }
        // How wide the graph is in characters
        // Does not include \n or \0
        std::uint32_t get_width() const { return m_width; }
        // Re-calculates the value but does not store it
        std::uint32_t get_col_width() const;

        // How tall the graph is in characters
        void set_height(std::uint32_t height) { m_height = height; }
        // How tall the graph is in characters
        std::uint32_t get_height() const { return m_height; }
        // Re-calculates the value but does not store it
        std::uint32_t get_row_num_width() const;
    };
}

#endif
