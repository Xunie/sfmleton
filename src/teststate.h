#ifndef TESTSTATE_H
#define TESTSTATE_H
#include "gamestate.h"

namespace game {
    namespace state {
        class test : public game::state::prototype {
            bool enter;
            bool shutdown;
        public:
            test() { shutdown = false; };
            void init();
            void cleanup();

            void pause();
            void resume();

            // which functions go here?
            void handle_events( std::queue<sf::Event> events );
            void update( state::manager &man );
            void render( sf::RenderWindow &app );
        };
    };
};

#endif /* TESTSTATE_H */
