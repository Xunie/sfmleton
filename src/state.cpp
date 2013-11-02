#include <queue>
#include <SFML/Graphics.hpp>
#include "state.h"



void state::manager::change_state( prototype *ptr ) {
    if( !states.empty() ) {
        states.top()->cleanup();
        states.pop();
    }

    states.push( ptr );
    states.top()->init();
}

void state::manager::push_state( prototype *ptr ) {
    if( !states.empty() )
        states.top()->pause();

    states.push( ptr );
    states.top()->init();
}

void state::manager::pop_state() {
    if( states.empty() )
        return;

    states.top()->cleanup();
    states.pop();
}



bool state::manager::running() {
    return !states.empty();
}


void state::manager::handle_events( std::queue<sf::Event> &events ) {
    if( !states.empty() )
        states.top()->handle_events( events );
}

void state::manager::update() {
    if( !states.empty() )
        states.top()->update( *this );
}

void state::manager::render( sf::RenderWindow &app ) {
    if( !states.empty() )
        states.top()->render( app );
}
