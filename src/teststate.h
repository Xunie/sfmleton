#ifndef TESTSTATE_H
#define TESTSTATE_H
#include "state.h"

class test_state : public state::prototype {
    bool shutdown;
public:
    void init();
    void cleanup();

    void pause();
    void resume();

    void handle_events( std::queue<sf::Event> events );
    void update( state::manager &man );
    void render( sf::RenderWindow &app );
};

#endif /* TESTSTATE_H */
