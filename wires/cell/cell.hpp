#pragma once

#include <vector>
#include <cstdint>

enum class Cell: char {wire = 'W', head = 'H', tail = 'T', empty = 'E'};

typedef std::vector<std::vector<Cell>> CellFrame;

struct Coordinate {
    int64_t x, y;
    bool operator<(const Coordinate &other) const;
};
