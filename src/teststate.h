#ifndef TESTSTATE_H
#define TESTSTATE_H
#include "state.h"

class test_state : public state {
public:
    test_state( sf::RenderWindow &app );
    ~test_state();

    void process_events( std::queue<sf::Event> events );
    void update();
    void render();
};

#endif /* TESTSTATE_H */
