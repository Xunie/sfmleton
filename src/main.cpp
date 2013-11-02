#include <cstdlib>
#include <iostream>
#include <queue>

#include <SFML/Graphics.hpp>

#include "state.h"
#include "teststate.h"
using namespace std;


queue<sf::Event> getInput( sf::RenderWindow &app );


int main( int argc, char *argv[] ) {
    sf::RenderWindow app; // TODO put this in resource manager?
    state::manager man;

    sf::VideoMode vmode = sf::VideoMode::getDesktopMode(); // TODO change this
    app.create( vmode, "sfmleton", sf::Style::Fullscreen );

    if( !app.isOpen() ) {
        cerr << "Error creating SFML renderwindow" << endl;
        return EXIT_FAILURE;
    }

    man.push_state( new test_state );

    while( man.running() ) {
        // push input/window events to state
        queue<sf::Event> events = getInput(app);
        man.handle_events( events );

        // update state
        man.update();

        // window should be open
        if( !app.isOpen() ) {
            clog << "SFML RenderWindow not open." << endl;
            return EXIT_FAILURE;
        }

        // render state
        man.render( app );
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
