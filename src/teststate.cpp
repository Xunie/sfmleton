#include <iostream>
#include "teststate.h"
using namespace std;



void game::state::test::init() {
}

void game::state::test::cleanup() {
}


void game::state::test::pause() {
}

void game::state::test::resume() {
}


void game::state::test::update( std::queue<sf::Event> events, state::manager &man ) {
    while( !events.empty() ) {
        sf::Event e = events.front();

        if( e.type == sf::Event::KeyPressed )
            switch( e.key.code ) {
                case sf::Keyboard::Escape:
                    man.pop();
                    break;

                case sf::Keyboard::Return:
                    man.push( new game::state::test );
                    break;

                default:
                    break;
            }

        events.pop();
    }
}

void game::state::test::render( sf::RenderWindow &app ) {
    app.display();
}
