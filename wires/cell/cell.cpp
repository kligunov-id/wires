#include <cell.hpp>

bool Coordinate::operator<(const Coordinate &b) const {
    if (x != b.x) return x < b.x;
    return y < b.y;
}
