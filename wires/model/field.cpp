#include <field.hpp>
#include <cell/cell.hpp>
#include <string>
#include <array>
#include <fstream>

namespace Model {

    Field::Field() {
        load();
    }
    Field::~Field() {
        save();
    }

    std::istream& operator>>(std::istream &in, Coordinate &coord) {
        return in >> coord.x >> coord.y;
    }

    std::istream& operator>>(std::istream &in, Cell &cell) {
        char c;
        while (in >> c && c == ' ');
        if (!in) return in;
        if (c == static_cast<char>(Cell::wire)) cell = Cell::wire;
        else if (c == static_cast<char>(Cell::head)) cell = Cell::head;
        else if (c == static_cast<char>(Cell::tail)) cell = Cell::tail;
        else throw "Invalid cell type";
        return in;
    }

    void Field::load(std::string filename) {
        std::ifstream in(filename);
        Coordinate coord;
        Cell cell;
        while (in >> coord >> cell) field[coord]=cell;
    }

    std::ostream& operator<<(std::ostream &out, Coordinate coord) {
        return out << coord.x << " " << coord.y;
    }

    std::ostream& operator<<(std::ostream &out, Cell cell) {
        return out << static_cast<char>(cell);
    }

    void Field::save(std::string filename) {
        std::ofstream out(filename);
        for (auto &[coord, cell]: field) {
            out << coord << " " << cell << "\n";
        }
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