#include <field.hpp>
#include <cell.hpp>
#include <string>
#include <array>
#include <fstream>

namespace Model {
    // Operator< is needed for the std::map
    bool operator<(const Coordinate &a, const Coordinate &b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    }

    Coordinate::Coordinate(int64_t x, int64_t y): x(x), y(y) {}

    Field::Field() {
        load();
    }
    Field::~Field() {
        save();
    }

    void Field::load(std::string filename) {
        field[{1, 0}] = Cell::head;
        field[{0, 1}] = field[{0, 2}] = field[{1, 3}] = Cell::wire; 
        field[{2, 1}] = field[{2, 2}] = Cell::wire;
        field[{2, 1}] = Cell::tail;
    }
    void Field::save(std::string filename) {
        return;
    }

    CellFrame Field::get_frame() {
        CellFrame frame(3);
        for (int64_t x = 0; x < 3; x++) {
            for(int64_t y = 0; y < 4; y++) {
                frame[x].push_back((*this)[{x, y}]);
            }
        }
        return frame;
    }

    auto get_neighbours(Coordinate coord) {
        //auto dX{-1, 0, 1}, dY{-1, 0, 1};
        std::vector<Coordinate> neighbours;
        for (auto dx: {-1, 0, 1}) {
            for (auto dy: {-1, 0, 1}) {
                if (dx != 0 || dy != 0)
                    neighbours.push_back({coord.x + dx, coord.y + dy});
            }
        }
        return neighbours;
    }

    void Field::step() {
        std::map<Coordinate, int8_t> count_heads;
        for (auto &[coord, cell]: field) {
            if (cell == Cell::head) {
                for (auto &neighbour: get_neighbours(coord)) {
                    count_heads[neighbour] ++; 
                }
            }
        }
        for (auto &[coord, cell]: field) {
            if (cell == Cell::tail) cell = Cell::wire;
            else if (cell == Cell::head) cell = Cell::tail;
            else if (cell == Cell::wire) {
                if (count_heads[coord] == 1 || count_heads[coord] == 2) cell = Cell::head;
            }
        }
    }

    Cell Field::operator[](Coordinate coord) {
        if (field.find(coord) == field.end()) return Cell::empty;
        return field[coord];
    }
}
