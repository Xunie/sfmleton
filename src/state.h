#ifndef STATE_H
#define STATE_H
#include <queue>
#include <stack>
#include <SFML/Graphics.hpp>
#include "state.h"


namespace state {
    class manager;

    class prototype {
    public:
        virtual void init()    = 0;
        virtual void cleanup() = 0;

        virtual void pause()   = 0;
        virtual void resume()  = 0;

        virtual void handle_events( std::queue<sf::Event> events ) = 0;
        virtual void update( state::manager &man )   = 0;
        virtual void render( sf::RenderWindow &app ) = 0;
    };

// -----------------------------------------------------------------------------

    class manager {
        std::stack<prototype*> states;

    public:
        void change_state( prototype *ptr );
        void push_state( prototype *ptr );
        void pop_state();

        bool running();

        void handle_events( std::queue<sf::Event> &events );
        void update();
        void render( sf::RenderWindow &app );
    };
};


#endif /* STATEMANAGER_H */
