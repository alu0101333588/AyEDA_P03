#ifndef STATEADULT_H
#define STATEADULT_H

#include "State.h"

class StateAdult : public State { // Muerte: 
    public:
        StateAdult(); // Añadida
        void neighbors (const Grid& rejilla1, int i, int j);
        State* nextState();
        char getState() const; 
        ~StateAdult() = default; 

};

#endif