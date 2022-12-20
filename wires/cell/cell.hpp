#pragma once

#include <vector>
#include <cstdint>

enum class Cell: char {alive='A', dead='D'};

typedef std::vector<std::vector<Cell>> CellFrame;

struct Coordinate {
    int64_t x, y;
    bool operator<(const Coordinate &other) const;
};
