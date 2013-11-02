#include <iostream>
#include "state.h"
#include "teststate.h"



void test_state::init() {
    shutdown = false;
}

void test_state::cleanup() {
}


void test_state::pause() {
}

void test_state::resume() {
}


void test_state::handle_events( std::queue<sf::Event> events ) {
    while( !events.empty() ) {
        sf::Event e = events.front();

        if( e.type == sf::Event::KeyPressed )
            shutdown = true;

        events.pop();
    }
}

void test_state::update( state::manager &man ) {
    if( shutdown )
        man.pop_state();
}

void test_state::render( sf::RenderWindow &app ) {
    app.display();
}
