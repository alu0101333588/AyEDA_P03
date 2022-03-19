#ifndef STATELARVA_H
#define STATELARVA_H

#include "State.h"

class StateLarva : public State {
    public:
        StateLarva(); 
        void neighbors (const Grid& rejilla1, int i, int j);
        State* nextState();
        char getState() const; 
        ~StateLarva() = default; 

};

#endif