#pragma once

#include <cell.hpp>
#include <map>
#include <string>

namespace Model {
    struct Coordinate {
        int64_t x, y;
        Coordinate(int64_t x = 0, int64_t y = 0);
    };
    
    class Field {
    private:
        std::map<Coordinate, Cell> field;
    public:
        Field();
        ~Field();

        void load(std::string filename = ".save");
        void save(std::string filename = ".save");

        CellFrame get_frame();
        void step();
        
        Cell operator[](Coordinate coord);
    };
}
