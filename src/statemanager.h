#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include <queue>
#include <stack>
#include <SFML/Graphics.hpp>
#include "state.h"

class state_manager {
    std::stack<state*> states;

public:
    void change_state( state *ptr );
    void push_state( state *ptr );
    void pop_state();

    void handle_events( std::queue<sf::Event> &events );
    void update();
    void render();

// singleton!
    static state_manager *get() {
        return &instance;
    }
private:
    state_manager() {
    };
    static state_manager instance;
};

#endif /* STATEMANAGER_H */
