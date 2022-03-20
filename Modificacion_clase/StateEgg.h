#ifndef STATEEGG_H
#define STATEEGG_H

#include "State.h"

//class Cell;
class StateEgg : public State { 
    public:
        StateEgg();
        void neighbors (const Grid& rejilla1, int i, int j);
        State* nextState();
        char getState() const; 
        ~StateEgg() = default; 

};

#endif