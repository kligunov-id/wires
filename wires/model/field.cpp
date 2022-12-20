#include <field.hpp>
#include <cell/cell.hpp>
#include <string>
#include <array>
#include <fstream>
#include <iostream>

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
        if (c == static_cast<char>(Cell::alive)) cell = Cell::alive;
        else throw "Invalid cell type";
        return in;
    }

    void Field::load(std::string filename) {
        std::clog << "Loading field..." << std::endl;
        std::ifstream in(filename);
        Coordinate coord;
        Cell cell;
        while (in >> coord >> cell) field[coord]=cell;
        std::clog << "Field loaded" << std::endl;
    }

    std::ostream& operator<<(std::ostream &out, Coordinate coord) {
        return out << coord.x << " " << coord.y;
    }

    std::ostream& operator<<(std::ostream &out, Cell cell) {
        return out << static_cast<char>(cell);
    }

    void Field::save(std::string filename) {
        std::clog << "Saving field..." << std::endl;
        std::ofstream out(filename);
        for (auto &[coord, cell]: field) {
            out << coord << " " << cell << "\n";
        }
        std::clog << "Field saved" << std::endl;
    }

    CellFrame Field::get_frame(Coordinate topleft, int32_t num_rows, int32_t num_columns) {
        CellFrame frame(num_rows);
        for (int32_t x = 0; x < num_rows; x++) {
            for (int32_t y = 0; y < num_columns; y++) {
                frame[x].push_back((*this)[{topleft.x + x, topleft.y + y}]);
            }
        }
        return frame;
    }

    auto get_neighbours(Coordinate coord) {
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
            if (cell == Cell::alive) {
                for (auto &neighbour: get_neighbours(coord)) {
                    count_heads[neighbour]++; 
                }
            }
        }
        std::map<Coordinate, Cell> new_field;
        for (auto &[coord, count]: count_heads) {
            if (count == 3 || (count == 2 && (*this)[coord] == Cell::alive))
                new_field[coord] = Cell::alive;
        }
        std::swap(new_field, field);
    }

    Cell Field::operator[](Coordinate coord) {
        if (field.find(coord) == field.end()) return Cell::dead;
        return field[coord];
    }

    void Field::set_cell(Coordinate coord, Cell cell) {
        field[coord] = cell;
        if (cell == Cell::dead) field.erase(coord);
    }
}
