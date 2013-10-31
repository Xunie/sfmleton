#ifndef TESTSTATE_H
#define TESTSTATE_H
#include "state.h"

class test_state : public state {
public:
    void init();
    void cleanup();

    void pause();
    void resume();

    void handle_events( std::queue<sf::Event> events );
    void update();
    void render();

    static test_state *get() {
        return &instance;
    }
private:
    test_state() {
    }
    static test_state instance;
};

#endif /* TESTSTATE_H */
