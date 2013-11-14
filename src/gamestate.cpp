#include <queue>
#include <SFML/Graphics.hpp>
#include "gamestate.h"



void game::state::manager::push( prototype *ptr ) {
    if( !states.empty() )
        states.top()->pause();

    states.push( ptr );
    states.top()->init();
}


void game::state::manager::pop() {
    if( states.empty() )
        return;

    states.top()->cleanup();
    states.pop();

    if( states.empty() )
        return;

    states.top()->resume();
}


void game::state::manager::swap( prototype *ptr ) {
    if( !states.empty() ) {
        states.top()->cleanup();
        states.pop();
    }

    states.push( ptr );
    states.top()->init();
}



bool game::state::manager::empty() {
    return states.empty();
}


size_t game::state::manager::size() {
    return states.size();
}


game::state::prototype &game::state::manager::top() {
    if( states.empty() )
        throw; // TODO throw a proper exception here

    return *states.top();
}
