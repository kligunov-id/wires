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
    typedef std::variant<EventQuit, EventMouseClick, EventSetBrush> InterfaceEvent;
}
