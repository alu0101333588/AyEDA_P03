#ifndef STATEDEAD_H
#define STATEDEAD_H

#include "State.h"

class StateDead : public State { 
    public:
        StateDead(); 
        void neighbors (const Grid& rejilla1, int i, int j);
        State* nextState();
        char getState() const;
        ~StateDead() = default;
    
    /*private:
        char State_;
        int neighbors_;*/
};

#endif