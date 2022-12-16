#pragma once
#include <vector>

enum class Cell: char {wire = 'W', head = 'H', tail = 'T', empty = 'E'};

typedef std::vector<std::vector<Cell>> CellFrame;
