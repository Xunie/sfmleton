#include <cstdlib>
#include <iostream>
#include <queue>

#include <SFML/Graphics.hpp>

#include "gamestate.h"
#include "teststate.h"
using namespace std;


queue<sf::Event> getInput( sf::RenderWindow &app );


int main( int argc, char *argv[] ) {
    game::state::manager man;
    game::state::test t;
    sf::RenderWindow app;

    sf::VideoMode vmode = sf::VideoMode::getDesktopMode();
    app.create( vmode, "sfmleton", sf::Style::Fullscreen );

    if( !app.isOpen() ) {
        cerr << "Error creating SFML renderwindow" << endl;
        return EXIT_FAILURE;
    }

    man.push( new game::state::test );

    while( !man.empty() and app.isOpen() ) {
        // push input/window events to state
        queue<sf::Event> events = getInput(app);
        man.top().handle_events( events );

        // update state
        man.top().update( man );

        if( man.empty() )
            break;

        // window should be open
        if( !app.isOpen() ) {
            clog << "SFML RenderWindow not open." << endl;
            break;
        }

        // render state
        man.top().render( app );
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
