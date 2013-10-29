#ifndef STATE_H
#define STATE_H
#include <queue>
#include <SFML/Graphics.hpp>

class state {
public:
    state() {};
    state( sf::RenderWindow &app );

    ~state() {};

    virtual void process_events( std::queue<sf::Event> events ) = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};

#endif /* STATE_H */
