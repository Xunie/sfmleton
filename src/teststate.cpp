#include <iostream>
#include "teststate.h"



void game::state::test::init() {
}

void game::state::test::cleanup() {
}


void game::state::test::pause() {
}

void game::state::test::resume() {
}


void game::state::test::handle_events( std::queue<sf::Event> events ) {
    while( !events.empty() ) {
        sf::Event e = events.front();

        if( e.type == sf::Event::KeyPressed )
            shutdown = true;

        events.pop();
    }
}

void game::state::test::update( state::manager &man ) {
    if( shutdown )
        do {
            man.pop();
        } while( !man.empty() );
}

void game::state::test::render( sf::RenderWindow &app ) {
    app.display();
}
