#include <cstdlib>
#include <iostream>
#include <queue>

#include <SFML/Graphics.hpp>

#include "statemanager.h"
#include "teststate.h"
using namespace std;


queue<sf::Event> getInput( sf::RenderWindow &app );


int main( int argc, char *argv[] ) {
    sf::RenderWindow app;
    sf::VideoMode vmode = sf::VideoMode::getDesktopMode(); // TODO change this
    app.create( vmode, "sfmleton", sf::Style::Fullscreen );

    if( !app.isOpen() ) {
        cerr << "Error creating SFML renderwindow" << endl;
        return EXIT_FAILURE;
    }


    // add a state to the state 'stack'
    state_manager::get()->push_state( test_state::get() );

    while( app.isOpen() ) {
        // update state
        state_manager::get()->update();

        // render state
        state_manager::get()->render();

        // push input/window events to state
        queue<sf::Event> events = getInput(app);
        state_manager::get()->handle_events( events );
    }


    return EXIT_SUCCESS;
}


queue<sf::Event> getInput( sf::RenderWindow &app ) {
    queue<sf::Event> queue;

    sf::Event e;
    while( app.pollEvent(e) )
        queue.push( e );

    return queue;
}
