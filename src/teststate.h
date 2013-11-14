#ifndef TESTSTATE_H
#define TESTSTATE_H
#include "gamestate.h"

namespace game {
    namespace state {
        class test : public game::state::prototype {
        public:
            void init();
            void cleanup();

            void pause();
            void resume();

            // which functions go here?
            void update( std::queue<sf::Event> events, state::manager &man );
            void render( sf::RenderWindow &app );
        };
    };
};

#endif /* TESTSTATE_H */
