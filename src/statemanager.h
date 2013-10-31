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
};

#endif /* STATEMANAGER_H */
