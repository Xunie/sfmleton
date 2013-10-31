#include <queue>
#include <SFML/Graphics.hpp>
#include "statemanager.h"


// singleton instance
state_manager state_manager::instance;


void state_manager::change_state( state *ptr ) {
}

void state_manager::push_state( state *ptr ) {
}

void state_manager::pop_state() {
}


void state_manager::handle_events( std::queue<sf::Event> &events ) {
    states.top()->handle_events( events );
}

void state_manager::update() {
    states.top()->update();
}

void state_manager::render() {
    states.top()->render();
}
