#include <cstdlib>
#include <iostream>
#include <queue>

#include <SFML/Graphics.hpp>
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

    while( app.isOpen() ) {
        app.display();

        queue<sf::Event> event_queue = getInput(app);

        while( !event_queue.empty() ) {
            sf::Event e = event_queue.front();
            event_queue.pop();

            if( e.type == sf::Event::KeyPressed && app.isOpen() )
                app.close();
        }
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
