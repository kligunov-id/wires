#pragma once

#include <vector>
#include <variant>

namespace View {
    class EventQuit {};     
    
    typedef std::variant<EventQuit> InterfaceEvent;
}
