#include <cstdlib>
#include <iostream>
#include <queue>

#include <SFML/Graphics.hpp>

#include "statemanager.h"
#include "teststate.h"
using namespace std;


queue<sf::Event> getInput( sf::RenderWindow &app );


int main( int argc, char *argv[] ) {
    state::manager man;
    sf::RenderWindow app;

    // get resolution
    sf::VideoMode       vmode = sf::VideoMode::getDesktopMode();

    // we only want OpenGL >= 3.3 contexts
    sf::ContextSettings hints = sf::ContextSettings();
    hints.majorVersion = 3;
    hints.minorVersion = 3;

    app.create( vmode, "sfmleton", sf::Style::Fullscreen, hints );

    if( !app.isOpen() ) {
        cerr << "Error creating SFML renderwindow" << endl;
        return EXIT_FAILURE;
    }

    // this will not run on your toaster
    if( app.getSettings().majorVersion < 3
     or app.getSettings().minorVersion < 3 ) {
        cerr << "OpenGL >= 3.3 context required, E_TOASTER" << endl;
        //return EXIT_FAILURE;
    }

    app.setVerticalSyncEnabled( true );

    // prevent partial core melt
    app.setFramerateLimit(120);

    man.push( new state::test );

    while( !man.empty() and app.isOpen() ) {
        // get input/window events
        queue<sf::Event> events = getInput(app);

        // update state
        man.top().update( app, man, events );

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
