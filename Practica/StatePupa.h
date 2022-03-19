#ifndef STATEPUPA_H
#define STATEPUPA_H

#include "State.h"

class StatePupa : public State { // Muerte: 
    public:
        StatePupa(); // Añadida
        void neighbors (const Grid& rejilla1, int i, int j);
        State* nextState();
        char getState() const; 
        ~StatePupa() = default; 

};

#endif