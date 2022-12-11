#include <iostream>
#include <view/user_interface.hpp>

int main(int argc, char* argv[]) {
    View::UserInterface user_interface;
    while (true) {
        user_interface.handle_event_queue();
    }
    return 0;
}
