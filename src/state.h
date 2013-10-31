#ifndef STATE_H
#define STATE_H
#include <queue>
#include <SFML/Graphics.hpp>

class state {
public:
    virtual void init()    = 0;
    virtual void cleanup() = 0;

    virtual void pause()  = 0;
    virtual void resume() = 0;

    virtual void handle_events( std::queue<sf::Event> events ) = 0;
    virtual void update() = 0;
    virtual void render() = 0;

// all derived classes should be singletons,
// we can't implement it here.
//    static state *get() {
//        return &instance;
//    }
protected:
//    static state instance;
// with a private constructor!
    state() {};
};

#endif /* STATE_H */
