#pragma once

#include <vector>
#include <variant>
#include <cell/cell.hpp>

namespace View {
    class EventQuit {};
    class EventMouseClick {
    public:
        int32_t x, y;
    };     
    class EventSetBrush {
    public:
        Cell cell;
    };
    class EventMoveFrame {
    public:
        Coordinate coord;
    };
    typedef std::variant<EventQuit, EventMouseClick, EventSetBrush, EventMoveFrame> InterfaceEvent;
}
