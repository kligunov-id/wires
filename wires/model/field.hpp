#pragma once

#include <cell/cell.hpp>
#include <map>
#include <string>

namespace Model {
    
    class Field {
    private:
        std::map<Coordinate, Cell> field;
    public:
        Field();
        ~Field();

        void load(std::string filename = ".save");
        void save(std::string filename = ".save");

        CellFrame get_frame(int32_t cell_n, int32_t cell_m);
        void set_cell(Coordinate coord, Cell cell);
        void step();
        
        Cell operator[](Coordinate coord);
    };
}
