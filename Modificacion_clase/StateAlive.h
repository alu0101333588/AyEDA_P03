#ifndef STATEALIVE_H
#define STATEALIVE_H

#include "State.h"

class StateAlive : public State { 
    public:
        StateAlive(); 
        void neighbors (const Grid& rejilla1, int i, int j);
        State* nextState();
        char getState() const;
        ~StateAlive() = default;
};

#endif